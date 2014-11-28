#include "LedFiberTiming.hh"

double cLight = 2.99792458e-1;   // speed of light in vacuum [mm/ps]



Fiber FiberInit(const double& length, const double& radius, std::vector<float>* att,
                const std::vector<std::pair<double,double> >& rIndVecCore,
                const std::vector<std::pair<double,double> >& rIndVecClad,
                const std::vector<std::pair<double,double> >& rIndVecAir,
                const std::vector<std::pair<double,double> >& rIndVecGap)
{
  Fiber f;
  f.lengthTotal = length;
  f.radius = radius;
  f.attenuation = att;
  f.refrIndsCore = rIndVecCore;
  f.refrIndsClad = rIndVecClad;
  f.refrIndsAir = rIndVecAir;
  f.refrIndsGap = rIndVecGap;
  f.position.SetX(0.);
  f.position.SetY(0.);
  f.position.SetZ(0.);
  f.direction.SetX(0);
  f.direction.SetY(0);
  f.direction.SetZ(1);
  return f;
}



double FindRefrInd(const double& phE, const std::vector<std::pair<double,double> >& rIndVec)
{
  double rInd = -1;
  
  for(unsigned int it = 0; it < rIndVec.size()-1; ++it)
  {
    double energy1 = rIndVec.at(it).first;
    double energy2 = rIndVec.at(it+1).first;
    double rInd1 = rIndVec.at(it).second;
    double rInd2 = rIndVec.at(it+1).second;
    
    if( (phE >= energy1) && (phE <= energy2) )
    {
      rInd = rInd1 + (rInd2-rInd1)/(energy2-energy1) * (phE-energy1);
      break;
    }
  }
  
  return rInd;
}



double fresnelReflection(const double& th, const double& R)
{
  // reflection probablity for unpolarized photons
  //   th - incident angle wrt to normal
  //   R = n1/n2 where 
  //       n1 is refractive index of fiber
  //       n2 is refractive index of outside media
  //  
  double u = 1. - R*R*sin(th)*sin(th);
  if(u<=0.) u=0.;
  u = sqrt(u);
  double Rs = (R*cos(th) - u)/(R*cos(th) + u);
  Rs = Rs * Rs;
  double Rp = (R*u - cos(th))/(R*u + cos(th));
  Rp = Rp * Rp;
  return 0.5*(Rs+Rp);
}



std::map<int,Travel> GetTimeAndProbability(Photon& ph, const Fiber* fib, const double& prodTime)
{
  std::map<int,Travel> result;
  for(unsigned int it = 0; it < fib->attenuation->size(); ++it)
  {
    int att = int( fib->attenuation->at(it) );
    
    Travel dummy;
    for(int i = 0; i < 10; ++i)
    {
      dummy.prob[i] =  0.;
      dummy.time[i] = -1.;
    }
    dummy.nmax = 3;
    
    result[att] = dummy;
  }
  
  double cosTheta = fib->direction * ph.direction;
  double theta = acos(cosTheta);
  double absTheta = acos(fabs(cosTheta));
  
  double refrIndCore = FindRefrInd(ph.energy,fib->refrIndsCore);
  double refrIndClad = FindRefrInd(ph.energy,fib->refrIndsClad);
  double refrIndAir = FindRefrInd(ph.energy,fib->refrIndsAir);
  double refrIndGap = FindRefrInd(ph.energy,fib->refrIndsGap);
  
  //std::cout << "energy: " << ph.energy
  //          << "  core: " << refrIndCore
  //          << "  clad: " << refrIndClad
  //          << "  air: "  << refrIndAir
  //          << "  gap: " << refrIndGap
  //          << std::endl;
  
  double probReflectFace = fresnelReflection(absTheta, refrIndCore/refrIndAir);
  double probReflectRear = fresnelReflection(absTheta, refrIndCore/refrIndGap);
  
  
  // Total internal reflection at the face and the rear, photon will not reach a photo-detector
  if( (1.-probReflectFace) < 1.e-9 )
  {
    //std::cout << "tot int ref" << std::endl;
    return result;
  }
  
  
  // fiber axis
  TVector3 b = fib->position + fib->direction * fib->direction.Dot(ph.position - fib->position);
  // direction of a photon in transverse plane
  TVector3 v = ph.direction - fib->direction * fib->direction.Dot(ph.direction);
  // distance from the photon trajectory and the fiber axis in transverse plane
  TVector3 d = (b - ph.position) - v * (v.Dot(b - ph.position) / v.Mag2());
  // skew angle in transverse plane
  double cosGamma = sqrt( 1. - d.Mag2()/(fib->radius*fib->radius) );  
  // check if there is a total internal reflection off the fiber walls
  if( acos(cosGamma*sin(theta))<asin(refrIndClad/refrIndCore) ) return result;

  double relDistance = 0.;
  double probReflections = 1.;
  if( cosTheta > 0 )
  {
    relDistance = 1. - ph.dist;
  }
  else
  {
    relDistance = 1. + ph.dist;
    probReflections *= probReflectFace;
  }
  
  for(int i = 0; i < 3; ++i)
  {    
    double length = relDistance * fib->lengthTotal / fabs(cosTheta);
    double time = prodTime + length / cLight * refrIndCore;
    double prob = probReflections * (1.-probReflectRear);
    
    for(unsigned int it = 0; it < fib->attenuation->size(); ++it)
    {
      int att = int( fib->attenuation->at(it) );
      result[att].time[i] = time;
      result[att].prob[i] =  exp( -1. * length / att ) * prob;
    }
    
    //result.time[i] = prodTime + length / cLight * refrIndCore;
    //result.prob[i] =  exp( -1. * length / fib->attenuation ) * probReflections * (1.-probReflectRear);
    
    //if( fabs(ph.position.y()) > 100 )
    //std::cout << "result.prob[" << i << "]: " << result.prob[i] << "   y: " << ph.position.y() << "   py: " << ph.direction.y() << "   dist: " << ph.dist << "   relDistance: " << relDistance << "   length: " << length/10. << "  exp( -length / fib->attenuation ): " <<  exp( -length / fib->attenuation ) << "   probReflections: " << probReflections << "   (1.-probReflectRear): " << (1.-probReflectRear) << std::endl;  
    
    relDistance += 2.;
    probReflections *= probReflectFace * probReflectRear;
  }
  return result;    
}
