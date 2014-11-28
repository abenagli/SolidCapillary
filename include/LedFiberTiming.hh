#ifndef LedFiberTiming_H
#define LedFiberTiming_H

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#include "TVector3.h"



struct Fiber{
  double   lengthTotal;
  std::vector<std::pair<double,double> > refrIndsCore;
  std::vector<std::pair<double,double> > refrIndsClad;
  std::vector<std::pair<double,double> > refrIndsAir;
  std::vector<std::pair<double,double> > refrIndsGap;
  std::vector<float>* attenuation;
  TVector3 position; 
  TVector3 direction;
  double   radius;
};

struct Photon{
  TVector3 position;
  TVector3 direction;
  double energy;
  double dist;   // relative from 0 to 1 (0 & 1 = photodetector)
};

struct Travel{
  int      nmax;
  double   prob[10];
  double   time[10];
};

Fiber FiberInit(const double& length, const double& radius, std::vector<float>* att,
                const std::vector<std::pair<double,double> >& rIndVecCore,
                const std::vector<std::pair<double,double> >& rIndVecClad,
                const std::vector<std::pair<double,double> >& rIndVecAir,
                const std::vector<std::pair<double,double> >& rIndVecGap);

double FindRefrInd(const double& phE, const std::vector<std::pair<double,double> >& rIndVec);

double fresnelReflection(const double& th, const double& R);

std::map<int,Travel> GetTimeAndProbability(Photon& ph, const Fiber* fib, const double& prodTime);

#endif
