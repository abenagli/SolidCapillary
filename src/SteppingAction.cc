#include "SteppingAction.hh"

using namespace std;
using namespace CLHEP;



int to_int (string name)
{
  int Result ;             // int which will contain the result
  stringstream convert (name) ;
  string dummy ;           
  convert >> dummy ;       
  convert >> Result ;
  return Result ;
}


//---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


SteppingAction::SteppingAction (DetectorConstruction* detectorConstruction,
                                const G4int& scint, const G4int& cher):
  fDetectorConstruction(detectorConstruction),
  propagateScintillation(scint),
  propagateCerenkov(cher)
{}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


SteppingAction::~SteppingAction ()
{}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void SteppingAction::UserSteppingAction (const G4Step * theStep)
{
  G4Track* theTrack = theStep->GetTrack () ;
  G4int trackID = theTrack->GetTrackID();
  TrackInformation* theTrackInfo = (TrackInformation*)(theTrack->GetUserInformation());
  G4ParticleDefinition* particleType = theTrack->GetDefinition () ;
  
  G4StepPoint * thePrePoint  = theStep->GetPreStepPoint () ;
  G4StepPoint * thePostPoint = theStep->GetPostStepPoint () ;
  const G4ThreeVector & thePrePosition  = thePrePoint->GetPosition () ;
  G4VPhysicalVolume * thePrePV  = thePrePoint->GetPhysicalVolume () ;
  G4VPhysicalVolume * thePostPV = thePostPoint->GetPhysicalVolume () ;
  G4String thePrePVName  = "" ; if ( thePrePV )  thePrePVName  = thePrePV  -> GetName () ;
  G4String thePostPVName = "" ; if ( thePostPV ) thePostPVName = thePostPV -> GetName () ;
  
  G4int nStep = theTrack -> GetCurrentStepNumber();
  
  
  
  //-------------
  // get position
  G4double global_x = thePrePosition.x()/mm;
  G4double global_y = thePrePosition.y()/mm;
  G4double global_z = thePrePosition.z()/mm;
  
  
  
  // optical photon
  if( particleType == G4OpticalPhoton::OpticalPhotonDefinition() )
  {
    G4String processName = theTrack->GetCreatorProcess()->GetProcessName();
    
    
    //----------------------------
    // count photons at production
    if( ( theTrack->GetLogicalVolumeAtVertex()->GetName().contains("core") ) &&
        (nStep == 1) && (processName == "Scintillation") )
    {
      CreateTree::Instance()->tot_phot_sci += 1;
      if( !propagateScintillation ) theTrack->SetTrackStatus(fKillTrackAndSecondaries);
    }
        
    if( ( theTrack->GetLogicalVolumeAtVertex()->GetName().contains("core") ||
          theTrack->GetLogicalVolumeAtVertex()->GetName().contains("capillary") ||
          theTrack->GetLogicalVolumeAtVertex()->GetName().contains("cladding") ) &&
        (nStep == 1) && (processName == "Cerenkov") )
    {
      CreateTree::Instance()->tot_phot_cer += 1;
      if( !propagateCerenkov ) theTrack->SetTrackStatus(fKillTrackAndSecondaries);      
    }
    
    
    //----------------------------
    // count photons at fiber exit
    
    if( ( theTrack->GetLogicalVolumeAtVertex()->GetName().contains("core") ) &&
        (processName == "Scintillation") &&
        (thePrePVName == "gapLayerPV") && (thePostPVName == "gapPV") )
    {
      CreateTree::Instance()->tot_gap_phot_sci += 1;
      // if you do not want to kill a photon once it exits the fiber, comment here below
      theTrack->SetTrackStatus(fKillTrackAndSecondaries);
    }
    
    if( ( theTrack->GetLogicalVolumeAtVertex()->GetName().contains("core") ||
          theTrack->GetLogicalVolumeAtVertex()->GetName().contains("capillary") ||
          theTrack->GetLogicalVolumeAtVertex()->GetName().contains("cladding") ) &&
        (processName == "Cerenkov") &&
        (thePrePVName == "gapLayerPV") && (thePostPVName == "gapPV") )
    {
      CreateTree::Instance()->tot_gap_phot_cer += 1;
      // if you do not want to kill a photon once it exits the fiber, comment here below
      theTrack->SetTrackStatus(fKillTrackAndSecondaries);
    }
    
    
    //------------------------------
    // count photons at the detector
    
    if( ( theTrack->GetLogicalVolumeAtVertex()->GetName().contains("core") ) &&
        (processName == "Scintillation") &&
        (thePrePVName == "detLayerPV") && (thePostPVName == "detPV") )
    {
      CreateTree::Instance()->tot_det_phot_sci += 1;
      // if you do not want to kill a photon once it enters the detector, comment here below
      theTrack->SetTrackStatus(fKillTrackAndSecondaries);
    }
    
    if( ( theTrack->GetLogicalVolumeAtVertex()->GetName().contains("core") ||
          theTrack->GetLogicalVolumeAtVertex()->GetName().contains("capillary") ||
          theTrack->GetLogicalVolumeAtVertex()->GetName().contains("cladding") ) &&
        (processName == "Cerenkov") &&
        (thePrePVName == "detLayerPV") && (thePostPVName == "detPV") )
    {
      CreateTree::Instance()->tot_det_phot_cer += 1;
      // if you do not want to kill a photon once it enters the detector, comment here below
      theTrack->SetTrackStatus(fKillTrackAndSecondaries);
    }
    
    
    //-----------------------------------------------
    // kill photons escaping from the lateral surface
    if( (thePrePVName == "claddingPV") && (thePostPVName == "worldPV") )
    {
      theTrack->SetTrackStatus(fKillTrackAndSecondaries);
    }
    
    

    /*
    if( (theTrack->GetLogicalVolumeAtVertex()->GetName().contains("core")) && (nStep == 1) )
    {    
      //----------------------------------------------------------
      // storing time, energy and position at gap with fast timing
      Photon ph;
      ph.position.SetX(global_x);
      ph.position.SetY(global_y);
      ph.position.SetZ(global_z);
      ph.direction.SetX(theTrack->GetVertexMomentumDirection().x());
      ph.direction.SetY(theTrack->GetVertexMomentumDirection().y());
      ph.direction.SetZ(theTrack->GetVertexMomentumDirection().z());
      ph.dist = (global_z/(0.5*fiber_length));
      ph.energy = theTrack->GetTotalEnergy()/eV;
      
      Fiber* fib = fDetectorConstruction -> GetFiber();
      std::map<int,Travel> trc = GetTimeAndProbability(ph,fib,theTrackInfo->GetParticleProdTime());
      
      for(unsigned int it = 0; it < CreateTree::Instance()->attLengths->size(); ++it)
      {
        int attLength = int( CreateTree::Instance()->attLengths->at(it) );
        
        if( trc[attLength].prob[0] < 1.E-09 ) theTrack->SetTrackStatus(fKillTrackAndSecondaries);      
        
        for(int it2 = 0; it2 < 3; ++it2)
        {
          CreateTree::Instance()->tot_gap_photFast_cer->at(it) += trc[attLength].prob[it2];
          
          //CreateTree::Instance()->h_photFast_cer_gap_lambda[attLength] -> Fill( MyMaterials::fromEvToNm(theTrack->GetTotalEnergy()/eV), trc[attLength].prob[it2] );
          //CreateTree::Instance()->h_photFast_cer_gap_E[attLength]      -> Fill( theTrack->GetTotalEnergy()/eV, trc[attLength].prob[it2] );
          //CreateTree::Instance()->h_photFast_cer_gap_time[attLength]   -> Fill( trc[attLength].time[it2], trc[attLength].prob[it2] );
        }
      }
    }
    */
  } // optical photon
  
  
  // non optical photon
  else
  {
    //G4cout << ">>> begin non optical photon" << G4endl;
    
    G4double energy = theStep->GetTotalEnergyDeposit() - theStep->GetNonIonizingEnergyDeposit();
    if ( energy == 0. ) return;
    
    CreateTree::Instance() -> depositedEnergyTotal += energy/GeV;
    
    if( thePrePVName.contains("core") )
    {
      CreateTree::Instance()->depositedEnergyCore += energy/GeV;
    }
    if( thePrePVName.contains("capillary") )
    {
      CreateTree::Instance()->depositedEnergyCapillary += energy/GeV;
    }
    if( thePrePVName.contains("cladding") )
    {
      CreateTree::Instance()->depositedEnergyCladding += energy/GeV;
    }
    if( thePrePVName.contains("world") )
    {
      CreateTree::Instance() -> depositedEnergyWorld += energy/GeV;
    }
    
    //G4cout << ">>> end non optical photon" << G4endl;
  } // non optical photon
  
  
  return ;
}
