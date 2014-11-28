// Martin Goettlich @ DESY
//
 
#include "EventAction.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"
#include "G4SDManager.hh"
#include "MyMaterials.hh"
#include "CreateTree.hh"
#include "PrimaryGeneratorAction.hh"

#include <vector>

using namespace CLHEP;



EventAction::EventAction (const G4int& modulo) :
  printModulo(modulo)
{}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


EventAction::~EventAction ()
{}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void EventAction::BeginOfEventAction (const G4Event* evt)
{
  G4int evtNb = evt->GetEventID () ;
  if ( evtNb%printModulo == 0 ) 
  {
    G4cout << "---> Begin of Event: " << evtNb << G4endl ;
  }
  
  CreateTree::Instance ()->Clear () ;
  
  G4PrimaryVertex* vertex = evt->GetPrimaryVertex();
  G4double x = vertex -> GetX0();
  G4double y = vertex -> GetY0();
  G4double z = vertex -> GetZ0();
  
  G4PrimaryParticle * particle = vertex -> GetPrimary();
  G4double InitEnergy = particle -> GetTotalEnergy();
  G4double px = particle -> GetPx();
  G4double py = particle -> GetPy();
  G4double pz = particle -> GetPz();
  
  CreateTree::Instance() -> Event = evt->GetEventID () ;
  CreateTree::Instance() -> inputInitialPosition->at(0) = x/mm;
  CreateTree::Instance() -> inputInitialPosition->at(1) = y/mm;
  CreateTree::Instance() -> inputInitialPosition->at(2) = z/mm;
  CreateTree::Instance() -> inputMomentum->at(0) = px/GeV;
  CreateTree::Instance() -> inputMomentum->at(1) = py/GeV;
  CreateTree::Instance() -> inputMomentum->at(2) = pz/GeV;
  CreateTree::Instance() -> inputMomentum->at(3) = InitEnergy/GeV;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void EventAction::EndOfEventAction(const G4Event* evt)
{ 
  evt -> GetEventID();
  
  CreateTree::Instance ()->Fill ();
}
