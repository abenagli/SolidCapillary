#include "CreateTree.hh"
#include <algorithm>

using namespace std ;

CreateTree* CreateTree::fInstance = NULL ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


CreateTree::CreateTree (TString name)
{
  if( fInstance )
  {
    return ;
  }

  
  this -> fInstance = this ;
  this -> fname     = name ;
  this -> ftree     = new TTree (name,name) ;
  
  this -> GetTree ()->Branch ("Event", &this->Event, "Event/I") ;
  
  inputInitialPosition = new vector<float>(3,0.); 
  inputMomentum =        new vector<float>(4,0.); 
  this -> GetTree() -> Branch("inputInitialPosition", "vector<float>", &inputInitialPosition);
  this -> GetTree() -> Branch("inputMomentum",        "vector<float>", &inputMomentum);
  
  this -> GetTree() -> Branch("depositedEnergyTotal",     &this->depositedEnergyTotal,         "depositedEnergyTotal/F");
  this -> GetTree() -> Branch("depositedEnergyCore",      &this->depositedEnergyCore,           "depositedEnergyCore/F");
  this -> GetTree() -> Branch("depositedEnergyCapillary", &this->depositedEnergyCapillary, "depositedEnergyCapillary/F");
  this -> GetTree() -> Branch("depositedEnergyCladding",  &this->depositedEnergyCladding,   "depositedEnergyCladding/F");
  this -> GetTree() -> Branch("depositedEnergyWorld",     &this->depositedEnergyWorld,         "depositedEnergyWorld/F");
  
  this -> GetTree() -> Branch("tot_phot_sci",     &this->tot_phot_sci,         "tot_phot_sci/I");
  this -> GetTree() -> Branch("tot_phot_cer",     &this->tot_phot_cer,         "tot_phot_cer/I");
  this -> GetTree() -> Branch("tot_gap_phot_sci", &this->tot_gap_phot_sci, "tot_gap_phot_sci/I");
  this -> GetTree() -> Branch("tot_gap_phot_cer", &this->tot_gap_phot_cer, "tot_gap_phot_cer/I");
  this -> GetTree() -> Branch("tot_det_phot_sci", &this->tot_det_phot_sci, "tot_det_phot_sci/I");
  this -> GetTree() -> Branch("tot_det_phot_cer", &this->tot_det_phot_cer, "tot_det_phot_cer/I");
  
  this -> Clear() ;
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----



CreateTree::~CreateTree()
{}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----



int CreateTree::Fill() 
{ 
  return this -> GetTree() -> Fill(); 
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----



bool CreateTree::Write(TFile * outfile)
{
  outfile -> cd();
  ftree -> Write();
  return true ;
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----



void CreateTree::Clear()
{
  Event	= 0;
  
  depositedEnergyTotal = 0.;
  depositedEnergyCore = 0.;
  depositedEnergyCapillary = 0.;
  depositedEnergyCladding = 0.;
  depositedEnergyWorld = 0.;
  
  tot_phot_sci = 0;
  tot_phot_cer = 0;
  tot_det_phot_sci = 0;
  tot_det_phot_cer = 0;
  tot_gap_phot_sci = 0;
  tot_gap_phot_cer = 0;
  
  for (int i = 0 ; i < 3 ; ++i) 
  {
    inputInitialPosition -> at(i) = 0.;
  }
  for (int i = 0 ; i < 4 ; ++i) 
  {
    inputMomentum ->at(i) = 0.;
  }
}
