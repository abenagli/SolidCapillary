#ifndef CreateTree_H
#define CreateTree_H 1

#include <iostream>
#include <vector>
#include <map>

#include "TH2F.h"
#include "TH3F.h"
#include "TFile.h"
#include "TTree.h"
#include "TNtuple.h"



class CreateTree
{
private:
  
  TTree*  ftree ;
  TString fname ;
  
public:
  
  CreateTree (TString name);
  ~CreateTree () ;
  
  TTree*             GetTree() const { return ftree; };
  TString            GetName() const { return fname; };
  void               AddEnergyDeposit(int index, float deposit);
  void               AddScintillationPhoton(int index);
  void               AddCerenkovPhoton(int index);
  int                Fill();
  bool               Write(TFile *);
  void               Clear() ;
  static CreateTree* Instance() { return fInstance; } ;
  
  static CreateTree* fInstance;
  
  int Event;
  
  std::vector<float>* inputMomentum ; // Px Py Pz E
  std::vector<float>* inputInitialPosition ; // x, y, z
  
  float depositedEnergyTotal;
  float depositedEnergyCore;
  float depositedEnergyCapillary;
  float depositedEnergyCladding;
  float depositedEnergyWorld;
  
  int tot_phot_sci;
  int tot_phot_cer;
  int tot_gap_phot_sci;
  int tot_gap_phot_cer;
  int tot_det_phot_sci;
  int tot_det_phot_cer;
};

#endif
