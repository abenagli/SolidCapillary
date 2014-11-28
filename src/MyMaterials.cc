#include "MyMaterials.hh"
#include "G4NistManager.hh"

using namespace CLHEP;



MyMaterials::MyMaterials()
{}



MyMaterials::~MyMaterials()
{}



G4Material* MyMaterials::Air()
{
  G4double a, z, density;
  G4int nelements;
  
  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  
  G4Material* mat = new G4Material("Air", density=1.29*mg/cm3, nelements=2);
  mat->AddElement(N, 70.*perCent);
  mat->AddElement(O, 30.*perCent);
  
  const G4int nEntries_RI = 42;
  G4double PhotonEnergy_RI[nEntries_RI] = 
    { 0.1000*eV, 1.0000*eV, 1.0121*eV, 1.0332*eV, 
      1.0552*eV, 1.0781*eV, 1.1021*eV, 1.1271*eV, 
      1.1533*eV, 1.1808*eV, 1.2096*eV, 1.2398*eV, 
      1.2716*eV, 1.3051*eV, 1.3404*eV, 1.3776*eV, 
      1.4170*eV, 1.4586*eV, 1.5028*eV, 1.5498*eV, 
      1.5998*eV, 1.6531*eV, 1.7101*eV, 1.7712*eV, 
      1.8368*eV, 1.9074*eV, 1.9837*eV, 2.0664*eV, 
      2.1562*eV, 2.2543*eV, 2.3616*eV, 2.4797*eV, 
      2.6102*eV, 2.7552*eV, 2.9173*eV, 3.0996*eV, 
      3.3062*eV, 3.5424*eV, 3.8149*eV, 4.1328*eV, 
      4.5085*eV, 4.9594*eV };
  
  G4double RefractiveIndex[nEntries_RI] = 
    { 1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003, 1.0003, 1.0003, 
      1.0003, 1.0003 };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",PhotonEnergy_RI,RefractiveIndex,nEntries_RI);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::Water()
{
  G4double a, z, density;
  G4int nelements;
  
  G4Element* H = new G4Element("Hydrogen", "H", z=1 , a=1.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  
  G4Material* mat = new G4Material("Water", density= 1.0*g/cm3, nelements=2);
  mat->AddElement(H, 2);
  mat->AddElement(O, 1);
  
  const G4int nEntries = 33;
  G4double PhotonEnergy[nEntries] =
    { 0.100*eV, 2.034*eV, 2.068*eV, 2.103*eV,
      2.139*eV, 2.177*eV, 2.216*eV, 2.256*eV,
      2.298*eV, 2.341*eV, 2.386*eV, 2.433*eV,
      2.481*eV, 2.532*eV, 2.585*eV, 2.640*eV,
      2.697*eV, 2.757*eV, 2.820*eV, 2.885*eV,
      2.954*eV, 3.026*eV, 3.102*eV, 3.181*eV,
      3.265*eV, 3.353*eV, 3.446*eV, 3.545*eV,
      3.649*eV, 3.760*eV, 3.877*eV, 4.002*eV,
      4.136*eV };
  G4double RefractiveIndex[nEntries] =
    { 1.3435, 1.3435, 1.3440, 1.3445,
      1.3450, 1.3455, 1.3460, 1.3465,
      1.3470, 1.3475, 1.3480, 1.3485,
      1.3492, 1.3500, 1.3505, 1.3510,
      1.3518, 1.3522, 1.3530, 1.3535,
      1.3540, 1.3545, 1.3550, 1.3555,
      1.3560, 1.3568, 1.3572, 1.3580,
      1.3585, 1.3590, 1.3595, 1.3600,
      1.3608};
  G4double Absorption[nEntries] =
    {  3.448*m,  3.448*m,  4.082*m,  6.329*m,
       9.174*m, 12.346*m, 13.889*m, 15.152*m,
      17.241*m, 18.868*m, 20.000*m, 26.316*m,
      35.714*m, 45.455*m, 47.619*m, 52.632*m,
      52.632*m, 55.556*m, 52.632*m, 52.632*m,
      47.619*m, 45.455*m, 41.667*m, 37.037*m,
      33.333*m, 30.000*m, 28.500*m, 27.000*m,
      24.500*m, 22.000*m, 19.500*m, 17.500*m,
      14.500*m };
  G4double FastComponent[nEntries] =
    { 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00,
      1.00 };
  G4double SlowComponent[nEntries] =
    { 0.01, 0.01, 1.00, 2.00,
      3.00, 4.00, 5.00, 6.00,
      7.00, 8.00, 9.00, 8.00,
      7.00, 6.00, 4.00, 3.00,
      2.00, 1.00, 0.01, 1.00,
      2.00, 3.00, 4.00, 5.00,
      6.00, 7.00, 8.00, 9.00,
      8.00, 7.00, 6.00, 5.00,
      4.00 };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",        PhotonEnergy, RefractiveIndex, nEntries);
  myMPT->AddProperty("ABSLENGTH",     PhotonEnergy, Absorption,      nEntries);
  myMPT->AddProperty("FASTCOMPONENT", PhotonEnergy, FastComponent,   nEntries);
  myMPT->AddProperty("SLOWCOMPONENT", PhotonEnergy, SlowComponent,   nEntries);
  
  myMPT->AddConstProperty("SCINTILLATIONYIELD",50./MeV);
  //myMPT->AddConstProperty("ELECTRONSCINTILLATIONYIELD",50./MeV);
  myMPT->AddConstProperty("RESOLUTIONSCALE",1.0);
  myMPT->AddConstProperty("FASTTIMECONSTANT", 1.*ns);
  myMPT->AddConstProperty("SLOWTIMECONSTANT",10.*ns);
  myMPT->AddConstProperty("YIELDRATIO",0.8);
  
  mat->SetMaterialPropertiesTable(myMPT);

  return mat;
}



G4Material* MyMaterials::Vacuum()
{
  G4double a, z, density;
  G4int nelements;

  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  
  G4Material* mat = new G4Material("Vacuum", density=0.001*mg/cm3, nelements=2);
  mat->AddElement(N, 70.*perCent);
  mat->AddElement(O, 30.*perCent);
  
  const G4int nEntries = 3;
  G4double PhotonEnergy[nEntries] =
    { 0.0001*eV, 1.00*eV,100.00*eV };
  G4double RefractiveIndex[nEntries] =
    { 1.00, 1.00, 1.00 };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX", PhotonEnergy, RefractiveIndex, nEntries);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::Silicon()
{
  G4double a, z, density;
  
  G4Element* Si = new G4Element("Silicon", "Si", z=14., a=28.09*g/mole);
  
  G4Material* mat = new G4Material("Silicon", density=2.33*g/cm3,1);
  mat->AddElement(Si,1);
  
  const G4int nEntries = 4;
  G4double PhotonEnergy[nEntries] =
    { 0.0001*eV, 1.0*eV, 1.84*eV, 6.26*eV };
  G4double RefractiveIndex[nEntries] =
    { 4.0, 4.0, 4.0, 4.0 };
  G4double Absorption[nEntries] =
    { 0.1*mm, 0.1*mm, 0.1*mm, 0.1*mm};
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",    PhotonEnergy,  RefractiveIndex, nEntries);
  myMPT->AddProperty("ABSLENGTH", PhotonEnergy,  Absorption,      nEntries);
  
  mat->SetMaterialPropertiesTable(myMPT);

  return mat;
}



G4Material* MyMaterials::Quartz()
{
  G4double a, z, density;
  
  G4Element* Si = new G4Element("Silicon", "Si", z = 14., a = 28.09* g/mole);
  G4Element* O  = new G4Element("Oxygen",  "O",  z =  8., a = 16.00* g/mole);
  
  G4Material* mat = new G4Material ("Quartz", density = 2.2*g/cm3,2);
  mat->AddElement(Si,1);
  mat->AddElement(O,2);
  
  const G4int nEntries_RI = 11;
  G4double PhotonEnergy_RI[nEntries_RI] =
    { 1.0 * eV, 2.0 * eV, 2.5 * eV, 3.0 * eV,
      3.5 * eV, 4.0 * eV, 4.5 * eV, 5.0 * eV,
      5.5 * eV, 6.0 * eV, 6.26 * eV };
  G4double RefractiveIndex[nEntries_RI] =
    { 1.53, 1.54, 1.55, 1.56,
      1.56, 1.57, 1.59, 1.60,
      1.62, 1.64, 1.65 };
  
  const G4int nEntries_ABS = 4;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.0 * eV, 1.84 * eV, 4.08 * eV, 6.26 * eV };
  G4double Absorption[nEntries_ABS] =
    { 138.*mm, 138.*mm, 138.*mm, 138. *mm };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty ("RINDEX",    PhotonEnergy_RI,  RefractiveIndex, nEntries_RI);
  myMPT->AddProperty ("ABSLENGTH", PhotonEnergy_ABS, Absorption,      nEntries_ABS);
  
  mat->SetMaterialPropertiesTable (myMPT);
  
  return mat;
}

G4Material* MyMaterials::SiO2()
{
  G4double a, z, density;

  G4Element* Si = new G4Element("Silicon", "Si", z = 14., a = 28.09* g/mole);
  G4Element* O  = new G4Element("Oxygen",  "O",  z =  8., a = 16.00* g/mole);

  G4Material* mat = new G4Material ("SiO2Ce", density = 2.65*g/cm3,2);
  mat->AddElement(Si,1);
  mat->AddElement(O,2);
  
  const G4int nEntries_RI = 42;
  G4double PhotonEnergy_RI[nEntries_RI] = 
    { 0.1000*eV, 1.0000*eV, 1.0121*eV, 1.0332*eV, 
      1.0552*eV, 1.0781*eV, 1.1021*eV, 1.1271*eV, 
      1.1533*eV, 1.1808*eV, 1.2096*eV, 1.2398*eV, 
      1.2716*eV, 1.3051*eV, 1.3404*eV, 1.3776*eV, 
      1.4170*eV, 1.4586*eV, 1.5028*eV, 1.5498*eV, 
      1.5998*eV, 1.6531*eV, 1.7101*eV, 1.7712*eV, 
      1.8368*eV, 1.9074*eV, 1.9837*eV, 2.0664*eV, 
      2.1562*eV, 2.2543*eV, 2.3616*eV, 2.4797*eV, 
      2.6102*eV, 2.7552*eV, 2.9173*eV, 3.0996*eV, 
      3.3062*eV, 3.5424*eV, 3.8149*eV, 4.1328*eV, 
      4.5085*eV, 4.9594*eV };
  
  G4double RefractiveIndex[nEntries_RI] = 
    { 1.4476, 1.4476, 1.4478, 1.4481, 
      1.4483, 1.4486, 1.4489, 1.4492, 
      1.4495, 1.4498, 1.4501, 1.4504, 
      1.4507, 1.4511, 1.4514, 1.4518, 
      1.4521, 1.4525, 1.4529, 1.4533, 
      1.4538, 1.4542, 1.4547, 1.4553, 
      1.4559, 1.4565, 1.4572, 1.4580, 
      1.4589, 1.4599, 1.4610, 1.4623, 
      1.4638, 1.4656, 1.4676, 1.4701, 
      1.4731, 1.4769, 1.4816, 1.4878, 
      1.4960, 1.5074 };
  
  const G4int nEntries_ABS = 4;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.0 * eV, 1.84 * eV, 4.08 * eV, 6.26 * eV };
  G4double Absorption[nEntries_ABS] =
    { 138.*mm, 138.*mm, 138.*mm, 138. *mm };
  
  G4MaterialPropertiesTable* mt = new G4MaterialPropertiesTable();
  mt->AddProperty ("RINDEX",    PhotonEnergy_RI,  RefractiveIndex, nEntries_RI);
  mt->AddProperty ("ABSLENGTH", PhotonEnergy_ABS, Absorption,      nEntries_ABS);
  
  mat->SetMaterialPropertiesTable(mt);
  return mat;
}

G4Material* MyMaterials::SiO2_Ce()
{
  G4double a, z, density;

  G4Element* Si = new G4Element("Silicon", "Si", z = 14., a = 28.09* g/mole);
  G4Element* O  = new G4Element("Oxygen",  "O",  z =  8., a = 16.00* g/mole);

  G4Material* mat = new G4Material ("SiO2Ce", density = 2.65*g/cm3,2);
  mat->AddElement(Si,1);
  mat->AddElement(O,2);
  
  const G4int nEntries_RI = 42;
  G4double PhotonEnergy_RI[nEntries_RI] = 
    { 0.1000*eV, 1.0000*eV, 1.0121*eV, 1.0332*eV, 
      1.0552*eV, 1.0781*eV, 1.1021*eV, 1.1271*eV, 
      1.1533*eV, 1.1808*eV, 1.2096*eV, 1.2398*eV, 
      1.2716*eV, 1.3051*eV, 1.3404*eV, 1.3776*eV, 
      1.4170*eV, 1.4586*eV, 1.5028*eV, 1.5498*eV, 
      1.5998*eV, 1.6531*eV, 1.7101*eV, 1.7712*eV, 
      1.8368*eV, 1.9074*eV, 1.9837*eV, 2.0664*eV, 
      2.1562*eV, 2.2543*eV, 2.3616*eV, 2.4797*eV, 
      2.6102*eV, 2.7552*eV, 2.9173*eV, 3.0996*eV, 
      3.3062*eV, 3.5424*eV, 3.8149*eV, 4.1328*eV, 
      4.5085*eV, 4.9594*eV };
  
  G4double RefractiveIndex[nEntries_RI] = 
    { 1.4476, 1.4476, 1.4478, 1.4481, 
      1.4483, 1.4486, 1.4489, 1.4492, 
      1.4495, 1.4498, 1.4501, 1.4504, 
      1.4507, 1.4511, 1.4514, 1.4518, 
      1.4521, 1.4525, 1.4529, 1.4533, 
      1.4538, 1.4542, 1.4547, 1.4553, 
      1.4559, 1.4565, 1.4572, 1.4580, 
      1.4589, 1.4599, 1.4610, 1.4623, 
      1.4638, 1.4656, 1.4676, 1.4701, 
      1.4731, 1.4769, 1.4816, 1.4878, 
      1.4960, 1.5074 };
  
  const G4int nEntries_ABS = 4;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.0 * eV, 1.84 * eV, 4.08 * eV, 6.26 * eV };
  G4double Absorption[nEntries_ABS] =
    { 138.*mm, 138.*mm, 138.*mm, 138. *mm };

  const G4int NUMENTRIES_1 = 5;
  G4double FAST_Energy[NUMENTRIES_1]    = {1.8*eV,1.90*eV,2.7*eV,2.88*eV,4.08*eV};
  G4double FAST_COMPONENT[NUMENTRIES_1] = {0.00,1.00,2.0,1.0,0.00};

  G4MaterialPropertiesTable* mt = new G4MaterialPropertiesTable();
  mt->AddProperty ("RINDEX",    PhotonEnergy_RI,  RefractiveIndex, nEntries_RI);
  mt->AddProperty ("ABSLENGTH", PhotonEnergy_ABS, Absorption,      nEntries_ABS);
  mt->AddProperty("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);

  mt->AddConstProperty("SCINTILLATIONYIELD",40000/MeV);
  mt->AddConstProperty("RESOLUTIONSCALE",8.5);
  mt->AddConstProperty("FASTTIMECONSTANT",55.*ns);
  mt->AddConstProperty("YIELDRATIO",1.0);
  mt->AddConstProperty("FASTSCINTILLATIONRISETIME",0.5*ns);
  
  mat->SetMaterialPropertiesTable(mt);
  return mat;
}



G4Material* MyMaterials::YAG_Ce()
{
  G4double a, z, density;
  
  G4Element* Y  = new G4Element("Silicon",   "Y",  z = 39., a = 88.01* g/mole);
  G4Element* Al = new G4Element("Aluminium", "Al", z = 27., a = 28.09* g/mole);
  G4Element* O  = new G4Element("Oxygen",    "O",  z =  8., a = 16.00* g/mole);
  
  G4Material* mat = new G4Material ("YAGCe", density = 4.6*g/cm3,3);
  mat->AddElement(Y,3);
  mat->AddElement(Al,5);
  mat->AddElement(O,12);
  
  const G4int nEntries_RI = 42;
  G4double PhotonEnergy_RI[nEntries_RI] = 
    { 0.1000*eV, 1.0000*eV, 1.0121*eV, 1.0332*eV, 
      1.0552*eV, 1.0781*eV, 1.1021*eV, 1.1271*eV, 
      1.1533*eV, 1.1808*eV, 1.2096*eV, 1.2398*eV, 
      1.2716*eV, 1.3051*eV, 1.3404*eV, 1.3776*eV, 
      1.4170*eV, 1.4586*eV, 1.5028*eV, 1.5498*eV, 
      1.5998*eV, 1.6531*eV, 1.7101*eV, 1.7712*eV, 
      1.8368*eV, 1.9074*eV, 1.9837*eV, 2.0664*eV, 
      2.1562*eV, 2.2543*eV, 2.3616*eV, 2.4797*eV, 
      2.6102*eV, 2.7552*eV, 2.9173*eV, 3.0996*eV, 
      3.3062*eV, 3.5424*eV, 3.8149*eV, 4.1328*eV, 
      4.5085*eV, 4.9594*eV };
  
  G4double RefractiveIndex[nEntries_RI] = 
    { 1.8116, 1.8116, 1.8118, 1.8122, 
      1.8126, 1.8131, 1.8135, 1.8140, 
      1.8144, 1.8149, 1.8154, 1.8160, 
      1.8165, 1.8171, 1.8177, 1.8184, 
      1.8191, 1.8198, 1.8206, 1.8214, 
      1.8223, 1.8233, 1.8244, 1.8256, 
      1.8269, 1.8284, 1.8300, 1.8318, 
      1.8338, 1.8362, 1.8388, 1.8419, 
      1.8455, 1.8497, 1.8548, 1.8608, 
      1.8683, 1.8775, 1.8892, 1.9045, 
      1.9249, 1.9532 };
  //G4double Rayleigh[nEntries_RI] =
  //  { 138.*mm, 138.*mm, 138.*mm };
  
  const G4int nEntries_ABS = 4;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.0 * eV, 1.84 * eV, 4.08 * eV, 6.26 * eV };
  G4double Absorption[nEntries_ABS] =
    { 138.*mm, 138.*mm, 138.*mm, 138. *mm };
  
  const G4int NUMENTRIES_1 = 5;
  G4double FAST_Energy[NUMENTRIES_1]    = {1.8*eV,1.90*eV,2.7*eV,2.88*eV,4.08*eV};
  G4double FAST_COMPONENT[NUMENTRIES_1] = {0.00,1.00,2.0,1.0,0.00};
  
  G4MaterialPropertiesTable* mt = new G4MaterialPropertiesTable();
  mt->AddProperty ("RINDEX",    PhotonEnergy_RI,  RefractiveIndex, nEntries_RI);
  mt->AddProperty ("ABSLENGTH", PhotonEnergy_ABS, Absorption,      nEntries_ABS);
  mt->AddProperty("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
  
  mt->AddConstProperty("SCINTILLATIONYIELD",1800/MeV);
  mt->AddConstProperty("RESOLUTIONSCALE",8.5);
  mt->AddConstProperty("FASTTIMECONSTANT",55.*ns);
  mt->AddConstProperty("YIELDRATIO",1.0);
  mt->AddConstProperty("FASTSCINTILLATIONRISETIME",0.5*ns);
  
  mat->SetMaterialPropertiesTable(mt);
  return mat;
}



G4Material* MyMaterials::Brass()
{
  G4double a, z, density;

  G4Element* Cu = new G4Element("Copper", "Cu", z=29., a=63.546*g/mole);
  G4Element* Zn = new G4Element("Zinc",   "Zn", z=30., a=65.409*g/mole);
  
  G4Material* mat = new G4Material("Brass", density=8.73*g/cm3,2);
  mat->AddElement(Cu,0.75);
  mat->AddElement(Zn,0.25);
  
  return mat;
}



G4Material* MyMaterials::Aluminium()
{
  G4NistManager* man = G4NistManager::Instance();
  G4Element* Al = man->FindOrBuildElement("Al");
  
  G4Material* mat = new G4Material("Aluminium",2.700*g/cm3,1);
  mat->AddElement(Al,100.*perCent);
  
  return mat;
}



G4Material* MyMaterials::Iron()
{
  G4NistManager* man = G4NistManager::Instance();
  G4Element* Fe = man->FindOrBuildElement("Fe");
  
  G4Material* mat = new G4Material("Iron",7.874*g/cm3,1);
  mat->AddElement(Fe,100.*perCent);
  
  return mat;
}



G4Material* MyMaterials::Lead()
{
  G4NistManager* man = G4NistManager::Instance();
  G4Element* Pb = man->FindOrBuildElement("Pb");
  
  G4Material* mat = new G4Material("Lead",11.342*g/cm3,1);
  mat->AddElement(Pb,100.*perCent);
  
  return mat;
}



G4Material* MyMaterials::Tungsten()
{
  G4NistManager* man = G4NistManager::Instance();
  G4Element* W = man->FindOrBuildElement("W");
  G4Element* Ni = man->FindOrBuildElement("Ni");
  G4Element* Cu = man->FindOrBuildElement("Cu");
  
  G4Material* mat = new G4Material("Tungsten",17.*g/cm3,3);
  mat->AddElement(W,90.*perCent);
  mat->AddElement(Ni,5.*perCent);
  mat->AddElement(Cu,5.*perCent);
  
  return mat;
}



G4Material* MyMaterials::CopperTungstenAlloy(const G4double& WFrac)
{
  G4NistManager* man = G4NistManager::Instance();
  G4Element* W = man->FindOrBuildElement("W");
  G4Element* Cu = man->FindOrBuildElement("Cu");
  
  G4double rho_Cu = 8.96;
  G4double rho_W = 19.25;
  G4double rho = (1.-WFrac)*rho_Cu + WFrac*rho_W;
  G4Material* mat = new G4Material("CopperTungstenAlloy",rho*g/cm3,2);
  mat->AddElement(Cu,1.-WFrac);
  mat->AddElement(W,WFrac);
  
  return mat;
}



G4Material* MyMaterials::OpticalGrease()
{
  G4double a, z, density;
  G4Element* H = new G4Element("Hydrogen", "H", z=1., a= 1.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8., a=16.00*g/mole);
  G4Element* C = new G4Element("Carbon"  , "C", z=6., a=12.01*g/mole);

  G4Material* mat = new G4Material("Grease", density=1.0*g/cm3,3);
  mat->AddElement(C,1);
  mat->AddElement(H,1);
  mat->AddElement(O,1);

  const G4int nEntries = 35;
  G4double PhotonEnergy[nEntries] =
    { 0.0001*eV, 1.000*eV, 2.034*eV, 2.068*eV,
       2.103*eV, 2.139*eV, 2.177*eV, 2.216*eV,
       2.256*eV, 2.298*eV, 2.341*eV, 2.386*eV,
       2.433*eV, 2.481*eV, 2.532*eV, 2.585*eV,
       2.640*eV, 2.697*eV, 2.757*eV, 2.820*eV,
       2.885*eV, 2.954*eV, 3.026*eV, 3.102*eV,
       3.181*eV, 3.265*eV, 3.353*eV, 3.446*eV,
       3.545*eV, 3.649*eV, 3.760*eV, 3.877*eV,
       4.002*eV, 4.136*eV, 6.260*eV };
  G4double RefractiveIndex[nEntries] =
    { 1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50, 1.50,
      1.50, 1.50, 1.50 };

  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("RINDEX",    PhotonEnergy, RefractiveIndex, nEntries);
  //myMPT->AddProperty("ABSLENGTH", PhotonEnergy, Absorption,      nEntries);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}

G4Material* MyMaterials::DSB_Ce()  // Nanostructured glass ceramics scintillator DSB:Ce
{
  G4double a, z, density;
  G4Element*  DSB_glass = new G4Element("DSB_glass",    "DSB",   z=51,  a=124.00*g/mole);

  G4Material* mat = new G4Material("DSB", density=4*g/cm3,1);
  mat->AddElement(DSB_glass,1);

  // large band between 470 (2.64 eV) and 630 nm (1.97 eV) (mean 535 nm, 2.32)
  const G4int NUMENTRIES_1 = 5;
  G4double FAST_Energy[NUMENTRIES_1]    = {1.8*eV,1.90*eV,2.7*eV,2.88*eV,4.08*eV};
  G4double FAST_COMPONENT[NUMENTRIES_1] = {0.00,1.00,2.0,1.0,0.00};
  
  const G4int nEntries_RI = 42;
  G4double PhotonEnergy_RI[nEntries_RI] = 
    { 0.1000*eV, 1.0000*eV, 1.0121*eV, 1.0332*eV, 
      1.0552*eV, 1.0781*eV, 1.1021*eV, 1.1271*eV, 
      1.1533*eV, 1.1808*eV, 1.2096*eV, 1.2398*eV, 
      1.2716*eV, 1.3051*eV, 1.3404*eV, 1.3776*eV, 
      1.4170*eV, 1.4586*eV, 1.5028*eV, 1.5498*eV, 
      1.5998*eV, 1.6531*eV, 1.7101*eV, 1.7712*eV, 
      1.8368*eV, 1.9074*eV, 1.9837*eV, 2.0664*eV, 
      2.1562*eV, 2.2543*eV, 2.3616*eV, 2.4797*eV, 
      2.6102*eV, 2.7552*eV, 2.9173*eV, 3.0996*eV, 
      3.3062*eV, 3.5424*eV, 3.8149*eV, 4.1328*eV, 
      4.5085*eV, 4.9594*eV };
  
  G4double RefractiveIndex[nEntries_RI] = 
    { 1.4476, 1.4476, 1.4478, 1.4481, 
      1.4483, 1.4486, 1.4489, 1.4492, 
      1.4495, 1.4498, 1.4501, 1.4504, 
      1.4507, 1.4511, 1.4514, 1.4518, 
      1.4521, 1.4525, 1.4529, 1.4533, 
      1.4538, 1.4542, 1.4547, 1.4553, 
      1.4559, 1.4565, 1.4572, 1.4580, 
      1.4589, 1.4599, 1.4610, 1.4623, 
      1.4638, 1.4656, 1.4676, 1.4701, 
      1.4731, 1.4769, 1.4816, 1.4878, 
      1.4960, 1.5074 };
  
  const G4int NUMENTRIES_2 = 4;
  G4double ABS_Energy[NUMENTRIES_2] = { 1.0*eV, 1.84*eV, 4.08*eV, 6.26*eV };
  G4double ABS_LENGTH[NUMENTRIES_2] = { 500.*mm, 500.*mm, 500.*mm, 500.*mm }; //138 original
  //G4double Rayleigh[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm};

  G4MaterialPropertiesTable* mt = new G4MaterialPropertiesTable();
  mt->AddProperty("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
  mt->AddProperty("RINDEX",        PhotonEnergy_RI, RefractiveIndex, nEntries_RI);
  mt->AddProperty("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_2);
  //mt->AddProperty("RAYLEIGH",      ABS_Energy,  Rayleigh,     NUMENTRIES_2);

  mt->AddConstProperty("SCINTILLATIONYIELD",1800/MeV);
  mt->AddConstProperty("RESOLUTIONSCALE",8.5);
  mt->AddConstProperty("FASTTIMECONSTANT",50.*ns);
  mt->AddConstProperty("YIELDRATIO",1.0);
  mt->AddConstProperty("FASTSCINTILLATIONRISETIME",0.5*ns);

  mat->SetMaterialPropertiesTable(mt);
  return mat;
}



G4Material* MyMaterials::LuAG_Ce() // Lutetium Aluminum Garnet - Ce-doped
{
  G4double a, z, density;
  G4Element*  O = new G4Element("Oxygen",   "O",  z=8.,  a= 16.00*g/mole);
  G4Element* Lu = new G4Element("Lutetium", "Lu", z=71., a=174.97*g/mole);
  G4Element* Al = new G4Element("Aluminum", "Al", z=27., a= 28.09*g/mole);
  
  G4Material* mat = new G4Material("LuAG_Ce", density=6.7*g/cm3,3);
  mat->AddElement(Lu,3);
  mat->AddElement(Al,12);
  mat->AddElement(O,5);
  
  const G4int nEntries_FAST = 458;
  G4double PhotonEnergy_FAST[nEntries_FAST] =
    { 1.82487*eV, 1.82622*eV, 1.82756*eV, 1.82891*eV, 1.83026*eV, 1.83161*eV, 1.83296*eV, 1.83432*eV, 1.83568*eV, 1.83704*eV,
      1.8384*eV, 1.83976*eV, 1.84113*eV, 1.8425*eV, 1.84387*eV, 1.84524*eV, 1.84661*eV, 1.84799*eV, 1.84937*eV, 1.85075*eV,
      1.85213*eV, 1.85351*eV, 1.8549*eV, 1.85629*eV, 1.85768*eV, 1.85907*eV, 1.86047*eV, 1.86186*eV, 1.86326*eV, 1.86466*eV,
      1.86606*eV, 1.86747*eV, 1.86888*eV, 1.87029*eV, 1.8717*eV, 1.87311*eV, 1.87453*eV, 1.87595*eV, 1.87737*eV, 1.87879*eV,
      1.88021*eV, 1.88164*eV, 1.88307*eV, 1.8845*eV, 1.88593*eV, 1.88737*eV, 1.8888*eV, 1.89024*eV, 1.89169*eV, 1.89313*eV,
      1.89458*eV, 1.89602*eV, 1.89748*eV, 1.89893*eV, 1.90038*eV, 1.90184*eV, 1.9033*eV, 1.90476*eV, 1.90623*eV, 1.90769*eV,
      1.90916*eV, 1.91063*eV, 1.9121*eV, 1.91358*eV, 1.91506*eV, 1.91654*eV, 1.91802*eV, 1.9195*eV, 1.92099*eV, 1.92248*eV,
      1.92397*eV, 1.92547*eV, 1.92696*eV, 1.92846*eV, 1.92996*eV, 1.93146*eV, 1.93297*eV, 1.93448*eV, 1.93599*eV, 1.9375*eV,
      1.93901*eV, 1.94053*eV, 1.94205*eV, 1.94357*eV, 1.9451*eV, 1.94662*eV, 1.94815*eV, 1.94969*eV, 1.95122*eV, 1.95276*eV,
      1.95429*eV, 1.95584*eV, 1.95738*eV, 1.95893*eV, 1.96047*eV, 1.96203*eV, 1.96358*eV, 1.96513*eV, 1.96669*eV, 1.96825*eV,
      1.96982*eV, 1.97138*eV, 1.97295*eV, 1.97452*eV, 1.9761*eV, 1.97767*eV, 1.97925*eV, 1.98083*eV, 1.98241*eV, 1.984*eV,
      1.98559*eV, 1.98718*eV, 1.98877*eV, 1.99037*eV, 1.99197*eV, 1.99357*eV, 1.99517*eV, 1.99678*eV, 1.99839*eV, 2*eV,
      2.00161*eV, 2.00323*eV, 2.00485*eV, 2.00647*eV, 2.0081*eV, 2.00972*eV, 2.01135*eV, 2.01299*eV, 2.01462*eV, 2.01626*eV,
      2.0179*eV, 2.01954*eV, 2.02119*eV, 2.02284*eV, 2.02449*eV, 2.02614*eV, 2.0278*eV, 2.02946*eV, 2.03112*eV, 2.03279*eV,
      2.03445*eV, 2.03612*eV, 2.0378*eV, 2.03947*eV, 2.04115*eV, 2.04283*eV, 2.04452*eV, 2.0462*eV, 2.04789*eV, 2.04959*eV,
      2.05128*eV, 2.05298*eV, 2.05468*eV, 2.05638*eV, 2.05809*eV, 2.0598*eV, 2.06151*eV, 2.06323*eV, 2.06495*eV, 2.06667*eV,
      2.06839*eV, 2.07012*eV, 2.07185*eV, 2.07358*eV, 2.07531*eV, 2.07705*eV, 2.07879*eV, 2.08054*eV, 2.08228*eV, 2.08403*eV,
      2.08579*eV, 2.08754*eV, 2.0893*eV, 2.09106*eV, 2.09283*eV, 2.09459*eV, 2.09637*eV, 2.09814*eV, 2.09992*eV, 2.10169*eV,
      2.10348*eV, 2.10526*eV, 2.10705*eV, 2.10884*eV, 2.11064*eV, 2.11244*eV, 2.11424*eV, 2.11604*eV, 2.11785*eV, 2.11966*eV,
      2.12147*eV, 2.12329*eV, 2.12511*eV, 2.12693*eV, 2.12876*eV, 2.13058*eV, 2.13242*eV, 2.13425*eV, 2.13609*eV, 2.13793*eV,
      2.13978*eV, 2.14162*eV, 2.14347*eV, 2.14533*eV, 2.14719*eV, 2.14905*eV, 2.15091*eV, 2.15278*eV, 2.15465*eV, 2.15652*eV,
      2.1584*eV, 2.16028*eV, 2.16216*eV, 2.16405*eV, 2.16594*eV, 2.16783*eV, 2.16973*eV, 2.17163*eV, 2.17353*eV, 2.17544*eV,
      2.17735*eV, 2.17926*eV, 2.18118*eV, 2.1831*eV, 2.18502*eV, 2.18695*eV, 2.18888*eV, 2.19081*eV, 2.19275*eV, 2.19469*eV,
      2.19663*eV, 2.19858*eV, 2.20053*eV, 2.20249*eV, 2.20444*eV, 2.20641*eV, 2.20837*eV, 2.21034*eV, 2.21231*eV, 2.21429*eV,
      2.21626*eV, 2.21825*eV, 2.22023*eV, 2.22222*eV, 2.22422*eV, 2.22621*eV, 2.22821*eV, 2.23022*eV, 2.23222*eV, 2.23423*eV,
      2.23625*eV, 2.23827*eV, 2.24029*eV, 2.24231*eV, 2.24434*eV, 2.24638*eV, 2.24841*eV, 2.25045*eV, 2.2525*eV, 2.25455*eV,
      2.2566*eV, 2.25865*eV, 2.26071*eV, 2.26277*eV, 2.26484*eV, 2.26691*eV, 2.26898*eV, 2.27106*eV, 2.27314*eV, 2.27523*eV,
      2.27732*eV, 2.27941*eV, 2.28151*eV, 2.28361*eV, 2.28571*eV, 2.28782*eV, 2.28994*eV, 2.29205*eV, 2.29417*eV, 2.2963*eV,
      2.29842*eV, 2.30056*eV, 2.30269*eV, 2.30483*eV, 2.30698*eV, 2.30912*eV, 2.31128*eV, 2.31343*eV, 2.31559*eV, 2.31776*eV,
      2.31993*eV, 2.3221*eV, 2.32427*eV, 2.32645*eV, 2.32864*eV, 2.33083*eV, 2.33302*eV, 2.33522*eV, 2.33742*eV, 2.33962*eV,
      2.34183*eV, 2.34405*eV, 2.34626*eV, 2.34848*eV, 2.35071*eV, 2.35294*eV, 2.35518*eV, 2.35741*eV, 2.35966*eV, 2.3619*eV,
      2.36416*eV, 2.36641*eV, 2.36867*eV, 2.37094*eV, 2.37321*eV, 2.37548*eV, 2.37776*eV, 2.38004*eV, 2.38232*eV, 2.38462*eV,
      2.38691*eV, 2.38921*eV, 2.39151*eV, 2.39382*eV, 2.39614*eV, 2.39845*eV, 2.40077*eV, 2.4031*eV, 2.40543*eV, 2.40777*eV,
      2.41011*eV, 2.41245*eV, 2.4148*eV, 2.41715*eV, 2.41951*eV, 2.42188*eV, 2.42424*eV, 2.42661*eV, 2.42899*eV, 2.43137*eV,
      2.43376*eV, 2.43615*eV, 2.43854*eV, 2.44094*eV, 2.44335*eV, 2.44576*eV, 2.44817*eV, 2.45059*eV, 2.45302*eV, 2.45545*eV,
      2.45788*eV, 2.46032*eV, 2.46276*eV, 2.46521*eV, 2.46766*eV, 2.47012*eV, 2.47258*eV, 2.47505*eV, 2.47752*eV, 2.48*eV,
      2.48248*eV, 2.48497*eV, 2.48746*eV, 2.48996*eV, 2.49246*eV, 2.49497*eV, 2.49748*eV, 2.5*eV, 2.50252*eV, 2.50505*eV,
      2.50758*eV, 2.51012*eV, 2.51266*eV, 2.51521*eV, 2.51777*eV, 2.52033*eV, 2.52289*eV, 2.52546*eV, 2.52803*eV, 2.53061*eV,
      2.5332*eV, 2.53579*eV, 2.53838*eV, 2.54098*eV, 2.54359*eV, 2.5462*eV, 2.54882*eV, 2.55144*eV, 2.55407*eV, 2.5567*eV,
      2.55934*eV, 2.56198*eV, 2.56463*eV, 2.56729*eV, 2.56995*eV, 2.57261*eV, 2.57529*eV, 2.57796*eV, 2.58065*eV, 2.58333*eV,
      2.58603*eV, 2.58873*eV, 2.59143*eV, 2.59414*eV, 2.59686*eV, 2.59958*eV, 2.60231*eV, 2.60504*eV, 2.60778*eV, 2.61053*eV,
      2.61328*eV, 2.61603*eV, 2.6188*eV, 2.62156*eV, 2.62434*eV, 2.62712*eV, 2.6299*eV, 2.6327*eV, 2.63549*eV, 2.6383*eV,
      2.64111*eV, 2.64392*eV, 2.64674*eV, 2.64957*eV, 2.65241*eV, 2.65525*eV, 2.65809*eV, 2.66094*eV, 2.6638*eV, 2.66667*eV,
      2.66954*eV, 2.67241*eV, 2.6753*eV, 2.67819*eV, 2.68108*eV, 2.68398*eV, 2.68689*eV, 2.6898*eV, 2.69273*eV, 2.69565*eV,
      2.69859*eV, 2.70153*eV, 2.70447*eV, 2.70742*eV, 2.71038*eV, 2.71335*eV, 2.71632*eV, 2.7193*eV, 2.72228*eV, 2.72527*eV,
      2.72827*eV, 2.73128*eV, 2.73429*eV, 2.73731*eV, 2.74033*eV, 2.74336*eV, 2.7464*eV, 2.74945*eV };
  G4double FastComponent[nEntries_FAST] =
    { 5.81332e-05, 6.44431e-05, 5.14981e-05, 5.53578e-05, 7.63256e-05, 7.53282e-05, 7.58269e-05, 8.97693e-05, 7.76917e-05, 7.38103e-05,
      7.78435e-05, 7.09481e-05, 7.49162e-05, 8.77528e-05, 8.86852e-05, 9.01596e-05, 7.3355e-05, 8.61916e-05, 8.31125e-05, 9.63177e-05,
      9.64045e-05, 8.96609e-05, 0.000118934, 0.000122446, 0.000112017, 8.10092e-05, 9.10487e-05, 9.54287e-05, 0.000102975, 0.000102996,
      0.00010833, 9.44529e-05, 9.82259e-05, 0.000117372, 0.000121601, 0.00011206, 0.000123183, 0.000126371, 0.000114987, 0.000121687,
      0.00011065, 0.000131879, 0.000124766, 0.000119606, 0.000146146, 0.000145279, 0.000141441, 0.000148553, 0.000156012, 0.000149746,
      0.000163168, 0.000161043, 0.000174898, 0.000182661, 0.000175918, 0.000175939, 0.000171169, 0.000159807, 0.0001726, 0.000178866,
      0.000175028, 0.000190836, 0.000208768, 0.000179539, 0.000198165, 0.000197644, 0.000199509, 0.000202545, 0.000218005, 0.000208031,
      0.000212584, 0.000219848, 0.000234961, 0.000249945, 0.000232078, 0.000224814, 0.000229476, 0.000248232, 0.000290948, 0.000269568,
      0.000289062, 0.000288346, 0.000276572, 0.000287999, 0.000306235, 0.000306452, 0.000293724, 0.000325186, 0.000335356, 0.000332277,
      0.000323885, 0.000335464, 0.000335724, 0.000372413, 0.000366406, 0.000352919, 0.000341297, 0.000400384, 0.00038796, 0.000373518,
      0.000396785, 0.000419986, 0.00042712, 0.000413654, 0.000429158, 0.000443621, 0.000482629, 0.000489546, 0.00047736, 0.000457151,
      0.000534973, 0.000505028, 0.000518277, 0.000507934, 0.000520879, 0.000552884, 0.00054859, 0.00057396, 0.000561015, 0.000557329,
      0.000603645, 0.000608111, 0.000628646, 0.000624894, 0.000634196, 0.000647055, 0.000670148, 0.000680122, 0.000679211, 0.000696731,
      0.000703887, 0.000728888, 0.000708722, 0.000749509, 0.000780863, 0.000772819, 0.000771908, 0.000782294, 0.000797256, 0.000792767,
      0.000837197, 0.00086081, 0.000856668, 0.000894267, 0.000905629, 0.000906323, 0.00097068, 0.00095175, 0.000955696, 0.000969986,
      0.000980069, 0.00103508, 0.00108445, 0.00109566, 0.00108985, 0.00108554, 0.00116115, 0.00116232, 0.00123272, 0.00118337,
      0.0012059, 0.00121104, 0.00122034, 0.00134806, 0.00132759, 0.00131655, 0.00134255, 0.0014004, 0.00139422, 0.00140613,
      0.00148002, 0.00146782, 0.00151511, 0.00152601, 0.00156979, 0.00156765, 0.00161945, 0.00161797, 0.00164276, 0.00167585,
      0.00163298, 0.00169692, 0.00173064, 0.00185434, 0.0018602, 0.00183116, 0.00184591, 0.00187262, 0.00185005, 0.00187863,
      0.00193908, 0.00196593, 0.00204381, 0.00207335, 0.00214098, 0.00216439, 0.00214946, 0.00215717, 0.00218378, 0.00220102,
      0.00226733, 0.00225952, 0.00232741, 0.0023407, 0.00237913, 0.0023986, 0.00246035, 0.00246658, 0.00256504, 0.00255051,
      0.00260585, 0.00261381, 0.00263094, 0.00263575, 0.00272168, 0.00272411, 0.00270891, 0.00276706, 0.00281004, 0.00290874,
      0.00298958, 0.00287925, 0.00292917, 0.00294574, 0.00308388, 0.00300632, 0.00300664, 0.00304351, 0.00310511, 0.00314704,
      0.00307382, 0.0031967, 0.00324223, 0.0032804, 0.00328582, 0.00328493, 0.00322873, 0.00335108, 0.00344131, 0.00348589,
      0.00347806, 0.00350257, 0.00354257, 0.00361777, 0.00364609, 0.00357236, 0.00361374, 0.0036504, 0.00367545, 0.00370214,
      0.00372157, 0.00380769, 0.00386073, 0.00378243, 0.0038225, 0.00388172, 0.00388896, 0.0039206, 0.00382433, 0.0039355,
      0.00394595, 0.00403936, 0.00412466, 0.00398097, 0.00412995, 0.00410556, 0.00412607, 0.00409762, 0.00417612, 0.00419223,
      0.00418902, 0.00420858, 0.00418737, 0.00438864, 0.00428859, 0.00424058, 0.00428341, 0.00434349, 0.00426255, 0.00425739,
      0.00426099, 0.00435654, 0.00430615, 0.0043434, 0.00436442, 0.00443317, 0.00453702, 0.00458465, 0.00451718, 0.00454829,
      0.004526, 0.00444941, 0.00459784, 0.00461657, 0.00464116, 0.00463936, 0.00462128, 0.00464869, 0.00472074, 0.00464255,
      0.00463531, 0.00464357, 0.00472312, 0.00471226, 0.00472876, 0.00475929, 0.00477558, 0.00477493, 0.00476745, 0.00480513,
      0.00488634, 0.00489984, 0.00491695, 0.0049675, 0.00488809, 0.00492643, 0.0048836, 0.00497446, 0.00506449, 0.00503294,
      0.00507216, 0.00511015, 0.00528854, 0.00508509, 0.00508214, 0.00515293, 0.00521213, 0.00535207, 0.00521807, 0.00530294,
      0.00523004, 0.00531701, 0.00543113, 0.00540544, 0.00534221, 0.00529414, 0.00536786, 0.00530663, 0.00540221, 0.0054366,
      0.00546841, 0.00534307, 0.0053802, 0.00543647, 0.00542493, 0.00540019, 0.0054354, 0.00542636, 0.00540218, 0.00539761,
      0.00546834, 0.00538748, 0.0054119, 0.00524333, 0.0052661, 0.00528475, 0.00527178, 0.00527688, 0.00527451, 0.0051803,
      0.00532525, 0.00516377, 0.00502179, 0.00498588, 0.00493792, 0.00504124, 0.00497812, 0.00480997, 0.00484698, 0.00475996,
      0.00467631, 0.0046375, 0.00452982, 0.00445893, 0.00443842, 0.00431203, 0.004365, 0.00422527, 0.00416564, 0.00407752,
      0.00394289, 0.00401572, 0.00385061, 0.00368295, 0.00359867, 0.00356532, 0.00350603, 0.00343337, 0.00328738, 0.00314308,
      0.00308744, 0.00307742, 0.00298919, 0.00291293, 0.00276594, 0.00274861, 0.00263172, 0.00244029, 0.00243841, 0.0023837,
      0.00222602, 0.00220015, 0.00206933, 0.0019725, 0.00198421, 0.00188412, 0.00176243, 0.00169384, 0.00163604, 0.00154739,
      0.00148061, 0.00135909, 0.00128767, 0.00121056, 0.00116466, 0.00113142, 0.00102363, 0.000933341, 0.000903136, 0.00086764,
      0.000834096, 0.000722275, 0.000704733, 0.000665919, 0.000615007, 0.00057151, 0.000541261, 0.000484668, 0.000465868, 0.000435923,
      0.000406347, 0.000362091, 0.000334272, 0.000302766, 0.000280562, 0.000268874, 0.000248102, 0.000231557, 0.0002133, 0.0001981,
      0.000193611, 0.000166442, 0.000154017, 0.000139056, 0.0001301, 0.00011928, 0.000122511, 0.000106704, 8.5411e-05, 8.49339e-05,
      8.20717e-05, 6.96905e-05, 6.09304e-05, 5.20402e-05, 5.76345e-05, 5.77646e-05, 4.39089e-05, 6.16243e-05 };
  
  const G4int nEntries_RI = 42;
  G4double PhotonEnergy_RI[nEntries_RI] = 
    { 0.1000*eV, 1.0000*eV, 1.0121*eV, 1.0332*eV, 
      1.0552*eV, 1.0781*eV, 1.1021*eV, 1.1271*eV, 
      1.1533*eV, 1.1808*eV, 1.2096*eV, 1.2398*eV, 
      1.2716*eV, 1.3051*eV, 1.3404*eV, 1.3776*eV, 
      1.4170*eV, 1.4586*eV, 1.5028*eV, 1.5498*eV, 
      1.5998*eV, 1.6531*eV, 1.7101*eV, 1.7712*eV, 
      1.8368*eV, 1.9074*eV, 1.9837*eV, 2.0664*eV, 
      2.1562*eV, 2.2543*eV, 2.3616*eV, 2.4797*eV, 
      2.6102*eV, 2.7552*eV, 2.9173*eV, 3.0996*eV, 
      3.3062*eV, 3.5424*eV, 3.8149*eV, 4.1328*eV, 
      4.5085*eV, 4.9594*eV };
  
  G4double RefractiveIndex[nEntries_RI] = 
    { 1.8212, 1.8212, 1.8215, 1.8219, 
      1.8223, 1.8227, 1.8231, 1.8236, 
      1.8240, 1.8245, 1.8250, 1.8255, 
      1.8261, 1.8266, 1.8272, 1.8279, 
      1.8285, 1.8293, 1.8300, 1.8308, 
      1.8317, 1.8327, 1.8338, 1.8349, 
      1.8362, 1.8376, 1.8392, 1.8410, 
      1.8430, 1.8453, 1.8479, 1.8509, 
      1.8545, 1.8587, 1.8637, 1.8699, 
      1.8774, 1.8869, 1.8991, 1.9152, 
      1.9374, 1.9694 };
  //G4double Rayleigh[nEntries_RI] =
  //  { 138.*mm, 138.*mm, 138.*mm };
  
  const G4int nEntries_ABS = 89;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.78417*eV, 1.7971*eV, 1.81022*eV, 1.82353*eV, 1.83704*eV, 1.85075*eV, 1.86466*eV, 1.87879*eV, 1.89313*eV, 1.90769*eV,
      1.92248*eV, 1.9375*eV, 1.95276*eV, 1.96825*eV, 1.984*eV, 2*eV, 2.01626*eV, 2.03279*eV, 2.04959*eV, 2.06667*eV,
      2.08403*eV, 2.10169*eV, 2.11966*eV, 2.13793*eV, 2.15652*eV, 2.17544*eV, 2.19469*eV, 2.21429*eV, 2.23423*eV, 2.25455*eV,
      2.27523*eV, 2.2963*eV, 2.31776*eV, 2.33962*eV, 2.3619*eV, 2.38462*eV, 2.40777*eV, 2.43137*eV, 2.45545*eV, 2.48*eV,
      2.50505*eV, 2.53061*eV, 2.5567*eV, 2.58333*eV, 2.61053*eV, 2.6383*eV, 2.66667*eV, 2.69565*eV, 2.72527*eV, 2.75556*eV,
      2.78652*eV, 2.81818*eV, 2.85057*eV, 2.88372*eV, 2.91765*eV, 2.95238*eV, 2.98795*eV, 3.02439*eV, 3.06173*eV, 3.1*eV,
      3.13924*eV, 3.17949*eV, 3.22078*eV, 3.26316*eV, 3.30667*eV, 3.35135*eV, 3.39726*eV, 3.44444*eV, 3.49296*eV, 3.54286*eV,
      3.5942*eV, 3.64706*eV, 3.70149*eV, 3.75758*eV, 3.81538*eV, 3.875*eV, 3.93651*eV, 4*eV, 4.06557*eV, 4.13333*eV,
      4.20339*eV, 4.27586*eV, 4.35088*eV, 4.42857*eV, 4.50909*eV, 4.59259*eV, 4.67925*eV, 4.76923*eV, 4.86275*eV };
  G4double Absorption[nEntries_ABS] =
    { 1.66482*m, 1.0584*m, 1.90233*m, 0.958758*m, 1.16913*m, 1.05368*m, 0.881739*m, 2.74593*m, 0.969113*m, 1.30342*m,
      1.11065*m, 1.14053*m, 0.926481*m, 0.835474*m, 0.814388*m, 0.702776*m, 1.01264*m, 0.749002*m, 0.691299*m, 0.791851*m,
      0.708582*m, 0.609636*m, 0.625308*m, 0.59058*m, 0.522642*m, 0.599727*m, 0.595345*m, 0.594927*m, 0.574464*m, 0.541271*m,
      0.531547*m, 0.581632*m, 0.57251*m, 0.560577*m, 0.493902*m, 0.422165*m, 0.354962*m, 0.255139*m, 0.151762*m, 0.0827965*m,
      0.0409174*m, 0.02007*m, 0.0100463*m, 0.00588694*m, 0.00636339*m, 0.0084497*m, 0.0224574*m, 0.0509883*m, 0.262914*m, 0.0571499*m,
      0.0830375*m, 0.378696*m, 0.0528428*m, 0.0661874*m, 0.0930821*m, 0.0672707*m, 0.0152385*m, 0.00676752*m, 0.00538106*m, 0.00799596*m,
      0.0177025*m, 0.0411282*m, 0.0919861*m, 0.149875*m, 0.132761*m, 0.068419*m, 0.0246548*m, 0.00922619*m, 0.00902168*m, 0.0264256*m,
      0.0839517*m, 0.0796384*m, 0.0552649*m, 0.0197203*m, 0.00872616*m, 0.00764327*m, 0.0153009*m, 0.0299903*m, 0.0403526*m, 0.0377371*m,
      0.0322887*m, 0.0251734*m, 0.0194992*m, 0.0145645*m, 0.0112908*m, 0.0100775*m, 0.0112081*m, 0.0158907*m, 0.019793*m };
  
  // for now, using the LSO scintillation properties
  const G4int nEntries_SCY = 12;
  G4double ElectronEnergy_SCY[nEntries_SCY] =
    { 0.000*MeV, 0.015*MeV, 0.020*MeV, 0.030*MeV,
      0.040*MeV, 0.060*MeV, 0.080*MeV, 0.090*MeV,
      0.105*MeV, 0.300*MeV, 0.500*MeV, 1.000*MeV };
  G4double ScintilYield[nEntries_SCY] =
    { 0.10, 0.46, 0.60, 0.68,
      0.74, 0.80, 0.82, 0.84,
      0.87, 0.96, 0.98, 1.00 };
  for(int i = 0; i < nEntries_SCY; i++)
    ScintilYield[i] = 15000.0*MeV*ScintilYield[i]*ElectronEnergy_SCY[i];
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("FASTCOMPONENT", PhotonEnergy_FAST, FastComponent,   nEntries_FAST);
  myMPT->AddProperty("RINDEX",        PhotonEnergy_RI,   RefractiveIndex, nEntries_RI);
  //myMPT->AddProperty("RAYLEIGH",      PhotonEnergy_RI,   Rayleigh,        nEntries_RI);
  myMPT->AddProperty("ABSLENGTH",     PhotonEnergy_ABS,  Absorption,      nEntries_ABS);
  //myMPT->AddProperty("ELECTRONSCINTILLATIONYIELD", ElectronEnergy_SCY, ScintilYield, nEntries_SCY);
  myMPT->AddConstProperty("SCINTILLATIONYIELD",15000/MeV);
  myMPT->AddConstProperty("RESOLUTIONSCALE",8.5);
  myMPT->AddConstProperty("FASTTIMECONSTANT",60.*ns);
  myMPT->AddConstProperty("YIELDRATIO",1.0);
  myMPT->AddConstProperty("FASTSCINTILLATIONRISETIME",0.5*ns);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::LuAG_Pr() // Lutetium Aluminum Garnet - 
{
  G4double a, z, density;
  G4Element*  O = new G4Element("Oxygen",   "O",  z= 8., a= 16.00*g/mole);
  G4Element* Lu = new G4Element("Lutetium", "Lu", z=71., a=174.97*g/mole);
  G4Element* Al = new G4Element("Aluminum", "Al", z=27., a= 28.09*g/mole);
  
  G4Material* mat = new G4Material("LuAG_Pr", density=6.7*g/cm3,3);
  mat->AddElement(Lu,3);
  mat->AddElement(Al,12);
  mat->AddElement(O,5);
  
  //  2 bands at 290nm (4.28eV) and 350nm (3.54eV) about 50% of the light in each.
  const G4int nEntries_FAST = 8;
  G4double PhotonEnergy_FAST[nEntries_FAST] =
    { 1.00*eV, 3.40*eV, 3.50*eV, 3.60*eV,
      3.90*eV, 3.91*eV, 4.07*eV, 4.08*eV};
  G4double FastComponent[nEntries_FAST] =
    {0.00, 0.00, 1.00, 0.00,
     0.00, 1.00, 0.00, 0.00 }; 

  const G4int nEntries_RI = 42;
  G4double PhotonEnergy_RI[nEntries_RI] = 
    { 0.1000*eV, 1.0000*eV, 1.0121*eV, 1.0332*eV, 
      1.0552*eV, 1.0781*eV, 1.1021*eV, 1.1271*eV, 
      1.1533*eV, 1.1808*eV, 1.2096*eV, 1.2398*eV, 
      1.2716*eV, 1.3051*eV, 1.3404*eV, 1.3776*eV, 
      1.4170*eV, 1.4586*eV, 1.5028*eV, 1.5498*eV, 
      1.5998*eV, 1.6531*eV, 1.7101*eV, 1.7712*eV, 
      1.8368*eV, 1.9074*eV, 1.9837*eV, 2.0664*eV, 
      2.1562*eV, 2.2543*eV, 2.3616*eV, 2.4797*eV, 
      2.6102*eV, 2.7552*eV, 2.9173*eV, 3.0996*eV, 
      3.3062*eV, 3.5424*eV, 3.8149*eV, 4.1328*eV, 
      4.5085*eV, 4.9594*eV };
  
  G4double RefractiveIndex[nEntries_RI] = 
    { 1.8212, 1.8212, 1.8215, 1.8219, 
      1.8223, 1.8227, 1.8231, 1.8236, 
      1.8240, 1.8245, 1.8250, 1.8255, 
      1.8261, 1.8266, 1.8272, 1.8279, 
      1.8285, 1.8293, 1.8300, 1.8308, 
      1.8317, 1.8327, 1.8338, 1.8349, 
      1.8362, 1.8376, 1.8392, 1.8410, 
      1.8430, 1.8453, 1.8479, 1.8509, 
      1.8545, 1.8587, 1.8637, 1.8699, 
      1.8774, 1.8869, 1.8991, 1.9152, 
      1.9374, 1.9694 }; 
  //G4double Rayleigh[nEntries_RI] =
  //  { 138.*mm, 138.*mm, 138.*mm};
  
  const G4int nEntries_ABS = 3;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.0*eV, 1.84*eV, 4.08*eV };
  G4double Absorption[nEntries_ABS] =
    { 138.*mm, 138.*mm, 138.*mm };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("FASTCOMPONENT", PhotonEnergy_FAST, FastComponent,   nEntries_FAST);
  myMPT->AddProperty("RINDEX",        PhotonEnergy_RI,   RefractiveIndex, nEntries_RI);
  //myMPT->AddProperty("RAYLEIGH",      PhotonEnergy_RI,   Rayleigh,        nEntries_RI);
  myMPT->AddProperty("ABSLENGTH",     PhotonEnergy_ABS,  Absorption,      nEntries_RI);
  myMPT->AddConstProperty("SCINTILLATIONYIELD",7000/MeV);
  myMPT->AddConstProperty("RESOLUTIONSCALE",6.4);
  myMPT->AddConstProperty("FASTTIMECONSTANT",20.*ns);
  myMPT->AddConstProperty("YIELDRATIO",1.0);
  myMPT->AddConstProperty("FASTSCINTILLATIONRISETIME",0.5*ns);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::LYSO()
{
  G4double a, z, density;
  G4Element*  O = new G4Element("Oxygen",   "O",  z= 8., a= 16.00*g/mole);
  G4Element* Lu = new G4Element("Lutetium", "Lu", z=71., a=174.97*g/mole);
  G4Element* Si = new G4Element("Silicon",  "Si", z=14., a= 28.09*g/mole);
  
  G4Material* mat = new G4Material("LYSO", density=7.1*g/cm3,3,kStateSolid);
  mat->AddElement(Lu,2);
  mat->AddElement(Si,1);
  mat->AddElement(O,5);
  
  const G4int nEntries_FAST = 261;
  G4double PhotonEnergy_FAST[nEntries_FAST] = 
    { 1.77169*eV, 1.77266*eV, 1.77558*eV, 1.77851*eV, 1.78145*eV, 1.78539*eV, 1.79033*eV, 1.7963*eV, 1.80231*eV, 1.80836*eV,
      1.81445*eV, 1.82058*eV, 1.82882*eV, 1.83401*eV, 1.84553*eV, 1.85293*eV, 1.86147*eV, 1.869*eV, 1.87769*eV, 1.89308*eV,
      1.90536*eV, 1.92007*eV, 1.93039*eV, 1.94901*eV, 1.95846*eV, 1.9668*eV, 1.97884*eV, 1.99102*eV, 2.00088*eV, 2.01209*eV,
      2.02596*eV, 2.03617*eV, 2.04519*eV, 2.0569*eV, 2.06611*eV, 2.0794*eV, 2.09151*eV, 2.10239*eV, 2.112*eV, 2.1231*eV,
      2.13431*eV, 2.14565*eV, 2.15566*eV, 2.16868*eV, 2.18038*eV, 2.19519*eV, 2.21171*eV, 2.2193*eV, 2.23619*eV, 2.23464*eV,
      2.24395*eV, 2.25806*eV, 2.27234*eV, 2.28358*eV, 2.29493*eV, 2.30475*eV, 2.31631*eV, 2.32463*eV, 2.33134*eV, 2.33809*eV,
      2.34487*eV, 2.35856*eV, 2.36719*eV, 2.37939*eV, 2.38642*eV, 2.40238*eV, 2.41134*eV, 2.424*eV, 2.43312*eV, 2.44047*eV,
      2.44786*eV, 2.46278*eV, 2.47788*eV, 2.48741*eV, 2.49317*eV, 2.49702*eV, 2.50282*eV, 2.50865*eV, 2.5145*eV, 2.52038*eV,
      2.52432*eV, 2.53223*eV, 2.5362*eV, 2.54619*eV, 2.55424*eV, 2.56031*eV, 2.56437*eV, 2.57049*eV, 2.57663*eV, 2.58487*eV,
      2.59317*eV, 2.59734*eV, 2.60571*eV, 2.61414*eV, 2.61414*eV, 2.61837*eV, 2.62262*eV, 2.62475*eV, 2.62902*eV, 2.63331*eV,
      2.63545*eV, 2.63976*eV, 2.64191*eV, 2.64841*eV, 2.65493*eV, 2.6593*eV, 2.66149*eV, 2.66588*eV, 2.67914*eV, 2.67914*eV,
      2.68136*eV, 2.68136*eV, 2.68359*eV, 2.68805*eV, 2.68805*eV, 2.68805*eV, 2.69477*eV, 2.69477*eV, 2.69702*eV, 2.70153*eV,
      2.70605*eV, 2.71286*eV, 2.71742*eV, 2.71971*eV, 2.722*eV, 2.722*eV, 2.72429*eV, 2.72889*eV, 2.72889*eV, 2.73351*eV,
      2.73814*eV, 2.74279*eV, 2.74512*eV, 2.74979*eV, 2.75213*eV, 2.75447*eV, 2.75917*eV, 2.75682*eV, 2.76389*eV, 2.76626*eV,
      2.76389*eV, 2.76626*eV, 2.77338*eV, 2.77576*eV, 2.78533*eV, 2.79255*eV, 2.79738*eV, 2.80223*eV, 2.80466*eV, 2.80709*eV,
      2.80953*eV, 2.80953*eV, 2.81934*eV, 2.8218*eV, 2.82673*eV, 2.83168*eV, 2.84164*eV, 2.84916*eV, 2.85419*eV, 2.8643*eV,
      2.86684*eV, 2.87449*eV, 2.87705*eV, 2.87961*eV, 2.88475*eV, 2.88733*eV, 2.8925*eV, 2.89509*eV, 2.90028*eV, 2.90549*eV,
      2.90811*eV, 2.91073*eV, 2.91335*eV, 2.91335*eV, 2.91335*eV, 2.91861*eV, 2.92125*eV, 2.92125*eV, 2.92389*eV, 2.92654*eV,
      2.92654*eV, 2.92919*eV, 2.92919*eV, 2.93185*eV, 2.93451*eV, 2.93717*eV, 2.93985*eV, 2.94252*eV, 2.9452*eV, 2.94789*eV,
      2.94789*eV, 2.94789*eV, 2.95058*eV, 2.95868*eV, 2.96411*eV, 2.96955*eV, 2.97228*eV, 2.97228*eV, 2.96955*eV, 2.97228*eV,
      2.97502*eV, 2.97776*eV, 2.97502*eV, 2.9805*eV, 2.9805*eV, 2.9805*eV, 2.98601*eV, 2.99154*eV, 2.99431*eV, 2.99431*eV,
      2.99708*eV, 2.99431*eV, 2.99708*eV, 3.00544*eV, 3.00824*eV, 3.00824*eV, 3.00824*eV, 3.00824*eV, 3.01385*eV, 3.0223*eV,
      3.02797*eV, 3.03081*eV, 3.02797*eV, 3.03365*eV, 3.03081*eV, 3.03081*eV, 3.0365*eV, 3.03935*eV, 3.04221*eV, 3.04795*eV,
      3.04795*eV, 3.05083*eV, 3.05371*eV, 3.05949*eV, 3.06239*eV, 3.06529*eV, 3.0682*eV, 3.06529*eV, 3.07112*eV, 3.0682*eV,
      3.07696*eV, 3.08283*eV, 3.0976*eV, 3.09464*eV, 3.09464*eV, 3.10653*eV, 3.11252*eV, 3.11852*eV, 3.12757*eV, 3.13668*eV,
      3.14583*eV, 3.15813*eV, 3.16741*eV, 3.17675*eV, 3.20828*eV, 3.23719*eV, 3.26664*eV, 3.28656*eV, 3.31351*eV, 3.34783*eV,
      3.38287*eV };
  G4double FastComponent[nEntries_FAST] = 
    { 0.011691, 0.011691, 0.011691, 0.0146138, 0.0146138, 0.0146138, 0.011691, 0.011691, 0.00876827, 0.00876827,
      0.00584551, 0.00584551, 0.00584551, 0.00292276, 0.00876827, 0.0146138, 0.0146138, 0.0146138, 0.0204593, 0.023382,
      0.0263048, 0.0204593, 0.0204593, 0.023382, 0.0292276, 0.0321503, 0.0350731, 0.0379958, 0.0379958, 0.0379958,
      0.0350731, 0.0379958, 0.0409186, 0.0438413, 0.0526096, 0.0584551, 0.0643006, 0.0730689, 0.0730689, 0.0818372,
      0.0906054, 0.0964509, 0.0993737, 0.105219, 0.111065, 0.122756, 0.125678, 0.146138, 0.146138, 0.160752,
      0.157829, 0.163674, 0.184134, 0.192902, 0.20167, 0.219207, 0.230898, 0.242589, 0.25428, 0.265971,
      0.274739, 0.292276, 0.306889, 0.315658, 0.321503, 0.350731, 0.368267, 0.385804, 0.397495, 0.415031,
      0.432568, 0.458873, 0.482255, 0.496868, 0.514405, 0.529019, 0.549478, 0.564092, 0.581628, 0.593319,
      0.602088, 0.616701, 0.637161, 0.660543, 0.681002, 0.71023, 0.736534, 0.756994, 0.777453, 0.806681,
      0.844676, 0.868058, 0.891441, 0.9119, 0.938205, 0.955741, 0.984969, 1.0142, 1.03173, 1.05511,
      1.07557, 1.11649, 1.13695, 1.15741, 1.17495, 1.19248, 1.21002, 1.22756, 1.27432, 1.2977,
      1.31524, 1.32985, 1.36785, 1.40292, 1.39415, 1.4, 1.41754, 1.44092, 1.47015, 1.48476,
      1.50814, 1.5286, 1.54906, 1.56952, 1.58998, 1.61921, 1.63967, 1.66597, 1.68935, 1.71566,
      1.73904, 1.76242, 1.77996, 1.80042, 1.8238, 1.83549, 1.85303, 1.8618, 1.87933, 1.89979,
      1.91733, 1.92902, 1.95825, 1.98163, 2.01378, 2.03424, 2.0547, 2.07808, 2.09562, 2.11023,
      2.12484, 2.13361, 2.15407, 2.15699, 2.15992, 2.16576, 2.16868, 2.16868, 2.16284, 2.15699,
      2.14823, 2.13946, 2.12484, 2.11023, 2.08977, 2.06639, 2.04593, 2.02839, 2.01086, 1.98455,
      1.96409, 1.94948, 1.93194, 1.91733, 1.90271, 1.87641, 1.86472, 1.8501, 1.83841, 1.82088,
      1.79749, 1.77119, 1.75073, 1.73027, 1.70689, 1.68058, 1.65428, 1.6309, 1.60167, 1.57244,
      1.55491, 1.53152, 1.50522, 1.47891, 1.45261, 1.43215, 1.40877, 1.38831, 1.362, 1.33862,
      1.31232, 1.28601, 1.27432, 1.25678, 1.21587, 1.19541, 1.17203, 1.14864, 1.12234, 1.10772,
      1.08434, 1.06096, 1.0142, 0.987891, 0.967432, 0.938205, 0.9119, 0.879749, 0.853445, 0.82714,
      0.786221, 0.765762, 0.739457, 0.716075, 0.681002, 0.660543, 0.637161, 0.60501, 0.581628, 0.552401,
      0.531942, 0.505637, 0.485177, 0.458873, 0.435491, 0.412109, 0.379958, 0.356576, 0.336117, 0.309812,
      0.280585, 0.25428, 0.207516, 0.175365, 0.157829, 0.13737, 0.119833, 0.0993737, 0.0759916, 0.0613779,
      0.0526096, 0.0350731, 0.0263048, 0.011691, 0.00876827, 0.00876827, 0.011691, 0.011691, 0.011691, 0.00876827,
      0.011691 };
  
  const G4int nEntries_RI = 3;
  G4double PhotonEnergy_RI[nEntries_RI] =
    { 1.0*eV, 1.84*eV, 6.26*eV };
  G4double RefractiveIndex[nEntries_RI] =
    { 1.82, 1.82, 1.82 };
  //G4double Rayleigh[nEntries_RI] =
  //  { 138.*mm, 138.*mm, 138.*mm};
  
  const G4int nEntries_ABS = 9;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.00*eV , 2.82*eV , 2.88*eV , 2.95*eV , 3.02*eV  , 3.10*eV  , 3.18*eV  , 3.26*eV , 4.08*eV };
  G4double Absorption[nEntries_ABS] =
    { 438.*mm , 438.*mm , 413.*mm , 375.*mm , 263.*mm  , 87.5*mm  , 11.5*mm  , 1.0*mm  , 1.0*mm  };
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("FASTCOMPONENT", PhotonEnergy_FAST, FastComponent,  nEntries_FAST);
  myMPT->AddProperty("RINDEX",        PhotonEnergy_RI,   RefractiveIndex, nEntries_RI);
  //myMPT->AddProperty("RAYLEIGH",      PhotonEnergy_ABS,  Rayleigh,        nEntries_RI);
  myMPT->AddProperty("ABSLENGTH",     PhotonEnergy_ABS,  Absorption,      nEntries_ABS);
  myMPT->AddConstProperty("SCINTILLATIONYIELD",40000./MeV);
  myMPT->AddConstProperty("RESOLUTIONSCALE",3.4);
  myMPT->AddConstProperty("FASTTIMECONSTANT",40.*ns);
  myMPT->AddConstProperty("YIELDRATIO",1.0);
  myMPT->AddConstProperty("FASTSCINTILLATIONRISETIME",0.1*ns);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::LYSO_lowLY()
{
  G4double a, z, density;
  G4Element*  O = new G4Element("Oxygen",   "O",  z=8.,  a= 16.00*g/mole);
  G4Element* Lu = new G4Element("Lutetium", "Lu", z=71., a=174.97*g/mole);
  G4Element* Si = new G4Element("Silicon",  "Si", z=14., a= 28.09*g/mole);
  
  G4Material* mat = new G4Material("LYSO_lowLY", density=7.1*g/cm3,3,kStateSolid);
  mat->AddElement(Lu,2);
  mat->AddElement(Si,1);
  mat->AddElement(O,5);
  
  const G4int nEntries_FAST = 261;
  G4double PhotonEnergy_FAST[nEntries_FAST] = 
    { 1.77169*eV, 1.77266*eV, 1.77558*eV, 1.77851*eV, 1.78145*eV, 1.78539*eV, 1.79033*eV, 1.7963*eV, 1.80231*eV, 1.80836*eV,
      1.81445*eV, 1.82058*eV, 1.82882*eV, 1.83401*eV, 1.84553*eV, 1.85293*eV, 1.86147*eV, 1.869*eV, 1.87769*eV, 1.89308*eV,
      1.90536*eV, 1.92007*eV, 1.93039*eV, 1.94901*eV, 1.95846*eV, 1.9668*eV, 1.97884*eV, 1.99102*eV, 2.00088*eV, 2.01209*eV,
      2.02596*eV, 2.03617*eV, 2.04519*eV, 2.0569*eV, 2.06611*eV, 2.0794*eV, 2.09151*eV, 2.10239*eV, 2.112*eV, 2.1231*eV,
      2.13431*eV, 2.14565*eV, 2.15566*eV, 2.16868*eV, 2.18038*eV, 2.19519*eV, 2.21171*eV, 2.2193*eV, 2.23619*eV, 2.23464*eV,
      2.24395*eV, 2.25806*eV, 2.27234*eV, 2.28358*eV, 2.29493*eV, 2.30475*eV, 2.31631*eV, 2.32463*eV, 2.33134*eV, 2.33809*eV,
      2.34487*eV, 2.35856*eV, 2.36719*eV, 2.37939*eV, 2.38642*eV, 2.40238*eV, 2.41134*eV, 2.424*eV, 2.43312*eV, 2.44047*eV,
      2.44786*eV, 2.46278*eV, 2.47788*eV, 2.48741*eV, 2.49317*eV, 2.49702*eV, 2.50282*eV, 2.50865*eV, 2.5145*eV, 2.52038*eV,
      2.52432*eV, 2.53223*eV, 2.5362*eV, 2.54619*eV, 2.55424*eV, 2.56031*eV, 2.56437*eV, 2.57049*eV, 2.57663*eV, 2.58487*eV,
      2.59317*eV, 2.59734*eV, 2.60571*eV, 2.61414*eV, 2.61414*eV, 2.61837*eV, 2.62262*eV, 2.62475*eV, 2.62902*eV, 2.63331*eV,
      2.63545*eV, 2.63976*eV, 2.64191*eV, 2.64841*eV, 2.65493*eV, 2.6593*eV, 2.66149*eV, 2.66588*eV, 2.67914*eV, 2.67914*eV,
      2.68136*eV, 2.68136*eV, 2.68359*eV, 2.68805*eV, 2.68805*eV, 2.68805*eV, 2.69477*eV, 2.69477*eV, 2.69702*eV, 2.70153*eV,
      2.70605*eV, 2.71286*eV, 2.71742*eV, 2.71971*eV, 2.722*eV, 2.722*eV, 2.72429*eV, 2.72889*eV, 2.72889*eV, 2.73351*eV,
      2.73814*eV, 2.74279*eV, 2.74512*eV, 2.74979*eV, 2.75213*eV, 2.75447*eV, 2.75917*eV, 2.75682*eV, 2.76389*eV, 2.76626*eV,
      2.76389*eV, 2.76626*eV, 2.77338*eV, 2.77576*eV, 2.78533*eV, 2.79255*eV, 2.79738*eV, 2.80223*eV, 2.80466*eV, 2.80709*eV,
      2.80953*eV, 2.80953*eV, 2.81934*eV, 2.8218*eV, 2.82673*eV, 2.83168*eV, 2.84164*eV, 2.84916*eV, 2.85419*eV, 2.8643*eV,
      2.86684*eV, 2.87449*eV, 2.87705*eV, 2.87961*eV, 2.88475*eV, 2.88733*eV, 2.8925*eV, 2.89509*eV, 2.90028*eV, 2.90549*eV,
      2.90811*eV, 2.91073*eV, 2.91335*eV, 2.91335*eV, 2.91335*eV, 2.91861*eV, 2.92125*eV, 2.92125*eV, 2.92389*eV, 2.92654*eV,
      2.92654*eV, 2.92919*eV, 2.92919*eV, 2.93185*eV, 2.93451*eV, 2.93717*eV, 2.93985*eV, 2.94252*eV, 2.9452*eV, 2.94789*eV,
      2.94789*eV, 2.94789*eV, 2.95058*eV, 2.95868*eV, 2.96411*eV, 2.96955*eV, 2.97228*eV, 2.97228*eV, 2.96955*eV, 2.97228*eV,
      2.97502*eV, 2.97776*eV, 2.97502*eV, 2.9805*eV, 2.9805*eV, 2.9805*eV, 2.98601*eV, 2.99154*eV, 2.99431*eV, 2.99431*eV,
      2.99708*eV, 2.99431*eV, 2.99708*eV, 3.00544*eV, 3.00824*eV, 3.00824*eV, 3.00824*eV, 3.00824*eV, 3.01385*eV, 3.0223*eV,
      3.02797*eV, 3.03081*eV, 3.02797*eV, 3.03365*eV, 3.03081*eV, 3.03081*eV, 3.0365*eV, 3.03935*eV, 3.04221*eV, 3.04795*eV,
      3.04795*eV, 3.05083*eV, 3.05371*eV, 3.05949*eV, 3.06239*eV, 3.06529*eV, 3.0682*eV, 3.06529*eV, 3.07112*eV, 3.0682*eV,
      3.07696*eV, 3.08283*eV, 3.0976*eV, 3.09464*eV, 3.09464*eV, 3.10653*eV, 3.11252*eV, 3.11852*eV, 3.12757*eV, 3.13668*eV,
      3.14583*eV, 3.15813*eV, 3.16741*eV, 3.17675*eV, 3.20828*eV, 3.23719*eV, 3.26664*eV, 3.28656*eV, 3.31351*eV, 3.34783*eV,
      3.38287*eV };
  G4double FastComponent[nEntries_FAST] = 
    { 0.011691, 0.011691, 0.011691, 0.0146138, 0.0146138, 0.0146138, 0.011691, 0.011691, 0.00876827, 0.00876827,
      0.00584551, 0.00584551, 0.00584551, 0.00292276, 0.00876827, 0.0146138, 0.0146138, 0.0146138, 0.0204593, 0.023382,
      0.0263048, 0.0204593, 0.0204593, 0.023382, 0.0292276, 0.0321503, 0.0350731, 0.0379958, 0.0379958, 0.0379958,
      0.0350731, 0.0379958, 0.0409186, 0.0438413, 0.0526096, 0.0584551, 0.0643006, 0.0730689, 0.0730689, 0.0818372,
      0.0906054, 0.0964509, 0.0993737, 0.105219, 0.111065, 0.122756, 0.125678, 0.146138, 0.146138, 0.160752,
      0.157829, 0.163674, 0.184134, 0.192902, 0.20167, 0.219207, 0.230898, 0.242589, 0.25428, 0.265971,
      0.274739, 0.292276, 0.306889, 0.315658, 0.321503, 0.350731, 0.368267, 0.385804, 0.397495, 0.415031,
      0.432568, 0.458873, 0.482255, 0.496868, 0.514405, 0.529019, 0.549478, 0.564092, 0.581628, 0.593319,
      0.602088, 0.616701, 0.637161, 0.660543, 0.681002, 0.71023, 0.736534, 0.756994, 0.777453, 0.806681,
      0.844676, 0.868058, 0.891441, 0.9119, 0.938205, 0.955741, 0.984969, 1.0142, 1.03173, 1.05511,
      1.07557, 1.11649, 1.13695, 1.15741, 1.17495, 1.19248, 1.21002, 1.22756, 1.27432, 1.2977,
      1.31524, 1.32985, 1.36785, 1.40292, 1.39415, 1.4, 1.41754, 1.44092, 1.47015, 1.48476,
      1.50814, 1.5286, 1.54906, 1.56952, 1.58998, 1.61921, 1.63967, 1.66597, 1.68935, 1.71566,
      1.73904, 1.76242, 1.77996, 1.80042, 1.8238, 1.83549, 1.85303, 1.8618, 1.87933, 1.89979,
      1.91733, 1.92902, 1.95825, 1.98163, 2.01378, 2.03424, 2.0547, 2.07808, 2.09562, 2.11023,
      2.12484, 2.13361, 2.15407, 2.15699, 2.15992, 2.16576, 2.16868, 2.16868, 2.16284, 2.15699,
      2.14823, 2.13946, 2.12484, 2.11023, 2.08977, 2.06639, 2.04593, 2.02839, 2.01086, 1.98455,
      1.96409, 1.94948, 1.93194, 1.91733, 1.90271, 1.87641, 1.86472, 1.8501, 1.83841, 1.82088,
      1.79749, 1.77119, 1.75073, 1.73027, 1.70689, 1.68058, 1.65428, 1.6309, 1.60167, 1.57244,
      1.55491, 1.53152, 1.50522, 1.47891, 1.45261, 1.43215, 1.40877, 1.38831, 1.362, 1.33862,
      1.31232, 1.28601, 1.27432, 1.25678, 1.21587, 1.19541, 1.17203, 1.14864, 1.12234, 1.10772,
      1.08434, 1.06096, 1.0142, 0.987891, 0.967432, 0.938205, 0.9119, 0.879749, 0.853445, 0.82714,
      0.786221, 0.765762, 0.739457, 0.716075, 0.681002, 0.660543, 0.637161, 0.60501, 0.581628, 0.552401,
      0.531942, 0.505637, 0.485177, 0.458873, 0.435491, 0.412109, 0.379958, 0.356576, 0.336117, 0.309812,
      0.280585, 0.25428, 0.207516, 0.175365, 0.157829, 0.13737, 0.119833, 0.0993737, 0.0759916, 0.0613779,
      0.0526096, 0.0350731, 0.0263048, 0.011691, 0.00876827, 0.00876827, 0.011691, 0.011691, 0.011691, 0.00876827,
      0.011691 };
  
  const G4int nEntries_RI = 3;
  G4double PhotonEnergy_RI[nEntries_RI] =
    { 1.0*eV, 1.84*eV, 6.26*eV };
  G4double RefractiveIndex[nEntries_RI] =
    { 1.82, 1.82, 1.82 };
  //G4double Rayleigh[nEntries_RI]
  //  = { 138.*mm, 138.*mm, 138.*mm};
  
  const G4int nEntries_ABS = 9;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.00*eV , 2.82*eV , 2.88*eV , 2.95*eV , 3.02*eV  , 3.10*eV  , 3.18*eV  , 3.26*eV , 4.08*eV };
  G4double Absorption[nEntries_ABS] =
    { 438.*mm , 438.*mm , 413.*mm , 375.*mm , 263.*mm  , 87.5*mm  , 11.5*mm  , 1.0*mm  , 1.0*mm  };
  
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("FASTCOMPONENT", PhotonEnergy_FAST, FastComponent,  nEntries_FAST);
  myMPT->AddProperty("RINDEX",        PhotonEnergy_RI,   RefractiveIndex, nEntries_RI);
  //myMPT->AddProperty("RAYLEIGH",      PhotonEnergy_RI,   Rayleigh,        nEntries_RI);
  myMPT->AddProperty("ABSLENGTH",     PhotonEnergy_ABS,  Absorption,      nEntries_ABS);
  myMPT->AddConstProperty("SCINTILLATIONYIELD",10./MeV);
  myMPT->AddConstProperty("RESOLUTIONSCALE",3.4);
  myMPT->AddConstProperty("FASTTIMECONSTANT",40.*ns);
  myMPT->AddConstProperty("YIELDRATIO",1.0);
  myMPT->AddConstProperty("FASTSCINTILLATIONRISETIME",0.1*ns);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::LSO()
{
  G4double a, z, density;
  G4Element*  O = new G4Element("Oxygen",   "O",  z= 8., a= 16.00*g/mole);
  G4Element* Lu = new G4Element("Lutetium", "Lu", z=71., a=174.97*g/mole);
  G4Element* Si = new G4Element("Silicon",  "Si", z=14., a= 28.09*g/mole);
  
  G4Material* mat = new G4Material("LSO", density=7.4*g/cm3,3);
  mat->AddElement(Lu,2);
  mat->AddElement(Si,1);
  mat->AddElement(O,5);
  
  const G4int nEntries_FAST = 192;
  G4double PhotonEnergy_FAST[nEntries_FAST] = 
    { 1.83966*eV, 1.84948*eV, 1.86274*eV, 1.87507*eV, 1.88413*eV, 1.90369*eV, 1.91187*eV, 1.92129*eV, 1.92962*eV, 1.93922*eV,
      1.95258*eV, 1.96365*eV, 1.97986*eV, 1.99124*eV, 2.00533*eV, 2.02618*eV, 2.04747*eV, 2.06101*eV, 2.07472*eV, 2.09424*eV,
      2.11269*eV, 2.12565*eV, 2.14466*eV, 2.16251*eV, 2.17914*eV, 2.19602*eV, 2.21317*eV, 2.22422*eV, 2.24021*eV, 2.25479*eV,
      2.26462*eV, 2.27785*eV, 2.29462*eV, 2.30821*eV, 2.32024*eV, 2.33588*eV, 2.34643*eV, 2.35529*eV, 2.37322*eV, 2.38594*eV,
      2.3896*eV, 2.39879*eV, 2.40805*eV, 2.41365*eV, 2.4268*eV, 2.44009*eV, 2.45161*eV, 2.46518*eV, 2.47693*eV, 2.48483*eV,
      2.49477*eV, 2.50479*eV, 2.51692*eV, 2.53123*eV, 2.5457*eV, 2.54986*eV, 2.55613*eV, 2.56033*eV, 2.56665*eV, 2.58796*eV,
      2.59658*eV, 2.60091*eV, 2.60309*eV, 2.60744*eV, 2.614*eV, 2.62059*eV, 2.62943*eV, 2.6361*eV, 2.64057*eV, 2.64729*eV,
      2.65632*eV, 2.66085*eV, 2.6654*eV, 2.66997*eV, 2.67684*eV, 2.67684*eV, 2.68839*eV, 2.69303*eV, 2.70237*eV, 2.70471*eV,
      2.71177*eV, 2.72124*eV, 2.72362*eV, 2.73077*eV, 2.73077*eV, 2.73317*eV, 2.73797*eV, 2.74279*eV, 2.74762*eV, 2.7549*eV,
      2.7549*eV, 2.75978*eV, 2.75978*eV, 2.76468*eV, 2.76713*eV, 2.77205*eV, 2.77699*eV, 2.77699*eV, 2.77947*eV, 2.78941*eV,
      2.79692*eV, 2.80195*eV, 2.80699*eV, 2.8146*eV, 2.81714*eV, 2.8248*eV, 2.8325*eV, 2.83507*eV, 2.85063*eV, 2.85847*eV,
      2.86635*eV, 2.86899*eV, 2.87428*eV, 2.87959*eV, 2.88225*eV, 2.89027*eV, 2.89295*eV, 2.89833*eV, 2.90103*eV, 2.90915*eV,
      2.91186*eV, 2.91731*eV, 2.92278*eV, 2.92278*eV, 2.92553*eV, 2.93103*eV, 2.93103*eV, 2.93103*eV, 2.94487*eV, 2.94487*eV,
      2.94766*eV, 2.95324*eV, 2.95604*eV, 2.95885*eV, 2.95604*eV, 2.96166*eV, 2.96447*eV, 2.97012*eV, 2.96166*eV, 2.97295*eV,
      2.98434*eV, 2.98434*eV, 2.98148*eV, 2.98434*eV, 2.99006*eV, 2.9872*eV, 2.99006*eV, 2.9872*eV, 2.99006*eV, 2.99869*eV,
      3.00447*eV, 3.00737*eV, 3.0161*eV, 3.01902*eV, 3.0161*eV, 3.0161*eV, 3.01318*eV, 3.01318*eV, 3.02194*eV, 3.02781*eV,
      3.03666*eV, 3.03666*eV, 3.03666*eV, 3.04556*eV, 3.05152*eV, 3.05152*eV, 3.05451*eV, 3.05451*eV, 3.05451*eV, 3.06051*eV,
      3.05751*eV, 3.07258*eV, 3.07258*eV, 3.07561*eV, 3.08169*eV, 3.09085*eV, 3.08779*eV, 3.09085*eV, 3.09699*eV, 3.10935*eV,
      3.10625*eV, 3.1218*eV, 3.12807*eV, 3.13121*eV, 3.14067*eV, 3.15657*eV, 3.16941*eV, 3.19213*eV, 3.21849*eV, 3.24529*eV,
      3.27255*eV, 3.28981*eV };
  G4double FastComponent[nEntries_FAST] = 
    { 0.0121475, 0.0121475, 0.0151844, 0.0151844, 0.0151844, 0.0182213, 0.0182213, 0.0182213, 0.024295, 0.024295,
      0.0212581, 0.0212581, 0.0303688, 0.0303688, 0.0303688, 0.0425163, 0.0516269, 0.0607375, 0.0698482, 0.072885,
      0.0850325, 0.0941432, 0.106291, 0.127549, 0.130586, 0.142733, 0.163991, 0.179176, 0.19436, 0.212581,
      0.224729, 0.239913, 0.252061, 0.273319, 0.297614, 0.318872, 0.34013, 0.355315, 0.376573, 0.38872,
      0.413015, 0.4282, 0.440347, 0.458568, 0.47679, 0.507158, 0.531453, 0.567896, 0.595228, 0.628633,
      0.652928, 0.68026, 0.71974, 0.759219, 0.77744, 0.813883, 0.835141, 0.859436, 0.886768, 0.920174,
      0.956616, 0.990022, 1.00521, 1.01735, 1.04165, 1.06898, 1.09328, 1.11757, 1.15098, 1.17223,
      1.2026, 1.23297, 1.26334, 1.29067, 1.32104, 1.37874, 1.40304, 1.43341, 1.46074, 1.49414,
      1.52451, 1.56095, 1.60043, 1.63991, 1.67028, 1.69761, 1.72191, 1.7462, 1.77354, 1.81605,
      1.84946, 1.88286, 1.88286, 1.88894, 1.9102, 1.94056, 1.98308, 2.00434, 2.03167, 2.07419,
      2.10759, 2.13189, 2.15315, 2.16833, 2.17744, 2.19566, 2.20781, 2.20781, 2.21996, 2.21692,
      2.20477, 2.18959, 2.16833, 2.14403, 2.11367, 2.08026, 2.04685, 2.01649, 1.98308, 1.94056,
      1.90716, 1.87679, 1.84642, 1.80998, 1.77354, 1.73406, 1.70369, 1.66421, 1.60651, 1.53362,
      1.5154, 1.49111, 1.46985, 1.44252, 1.4243, 1.39696, 1.36356, 1.318, 1.26941, 1.21171,
      1.16616, 1.13275, 1.09935, 1.12972, 1.11453, 1.08416, 1.05683, 1.02343, 0.993059, 0.956616,
      0.929284, 0.895879, 0.87462, 0.835141, 0.801735, 0.77744, 0.747072, 0.704555, 0.67115, 0.640781,
      0.595228, 0.570933, 0.540564, 0.510195, 0.473753, 0.443384, 0.419089, 0.394794, 0.373536, 0.34013,
      0.318872, 0.276356, 0.252061, 0.203471, 0.185249, 0.163991, 0.142733, 0.127549, 0.112364, 0.0911063,
      0.072885, 0.0577007, 0.0425163, 0.0303688, 0.024295, 0.00911063, 0.00607375, 0.00607375, 0.00303688, 0.00303688,
      0.00911063, 0.00911063 };
  
  const G4int nEntries_RI = 4;
  G4double PhotonEnergy_RI[nEntries_RI] =
    { 0.0001*eV, 1.0*eV, 1.84*eV, 6.26*eV };
  G4double RefractiveIndex[nEntries_RI] =
    { 1.82, 1.82, 1.82, 1.82 };
  //G4double Rayleigh[nEntries_RI] =
  //  { 138.*mm, 138.*mm, 138.*mm};
  
  const G4int nEntries_ABS = 4;  
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 0.0001*eV, 1.0*eV, 1.84*eV, 4.08*eV };
  G4double Absorption[nEntries_ABS] =
    { 1*mm,138.*mm, 138.*mm, 138.*mm };
  
  const G4int nEntries_SCY = 12;
  G4double ElectronEnergy_SCY[nEntries_SCY] =
    { 0.000*MeV, 0.015*MeV, 0.020*MeV, 0.030*MeV,
      0.040*MeV, 0.060*MeV, 0.080*MeV, 0.090*MeV,
      0.105*MeV, 0.300*MeV, 0.500*MeV, 1.000*MeV };
  G4double ScintilYield[nEntries_SCY] =
    { 0.10, 0.46, 0.60, 0.68,
      0.74, 0.80, 0.82, 0.84,
      0.87,  0.96,  0.98,  1.00 };
  for(int i=0; i < nEntries_SCY; i++)
    ScintilYield[i] = 60000.0*MeV*ScintilYield[i]*ElectronEnergy_SCY[i];
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty("FASTCOMPONENT", PhotonEnergy_FAST, FastComponent,   nEntries_FAST);
  myMPT->AddProperty("RINDEX",        PhotonEnergy_RI,   RefractiveIndex, nEntries_RI);
  //myMPT->AddProperty("RAYLEIGH",      PhotonEnergy_RI,   Rayleigh,        nEntries_RI);
  myMPT->AddProperty("ABSLENGTH",     PhotonEnergy_ABS,  Absorption,      nEntries_ABS);
  myMPT->AddProperty("ELECTRONSCINTILLATIONYIELD", ElectronEnergy_SCY, ScintilYield, nEntries_SCY);
  myMPT->AddConstProperty("SCINTILLATIONYIELD",60000./MeV);
  myMPT->AddConstProperty("RESOLUTIONSCALE",3.2);
  myMPT->AddConstProperty("FASTTIMECONSTANT",40.*ns);
  myMPT->AddConstProperty("YIELDRATIO",1.0);
  myMPT->AddConstProperty("FASTSCINTILLATIONRISETIME",0.1*ns);
  
  mat->SetMaterialPropertiesTable(myMPT);
  
  return mat;
}



G4Material* MyMaterials::PWO()
{
  G4double a, z, density;
  G4Element* Pb = new G4Element("Lead",     "Pb", z = 82., a = 207.21*g/mole);
  G4Element* W  = new G4Element("Tungsten", "W",  z = 74., a = 183.85*g/mole);
  G4Element* O  = new G4Element("Oxygen",   "O",  z =  8., a =  16.00*g/mole);
  
  G4Material* mat = new G4Material ("PWO", density = 8.28*g/cm3,3);
  mat->AddElement (Pb, 1);
  mat->AddElement (W, 1);
  mat->AddElement (O, 4);
  
  const G4int nEntries_FAST = 501;
  G4double PhotonEnergy_FAST[nEntries_FAST] =
    { 1.7712*eV, 1.77374*eV, 1.77628*eV, 1.77883*eV, 1.78138*eV, 1.78395*eV, 1.78652*eV, 1.78909*eV, 1.79168*eV, 1.79427*eV,
      1.79687*eV, 1.79948*eV, 1.8021*eV, 1.80472*eV, 1.80735*eV, 1.80999*eV, 1.81263*eV, 1.81529*eV, 1.81795*eV, 1.82062*eV,
      1.8233*eV, 1.82598*eV, 1.82868*eV, 1.83138*eV, 1.83409*eV, 1.8368*eV, 1.83953*eV, 1.84226*eV, 1.845*eV, 1.84775*eV,
      1.85051*eV, 1.85328*eV, 1.85605*eV, 1.85883*eV, 1.86162*eV, 1.86442*eV, 1.86723*eV, 1.87005*eV, 1.87287*eV, 1.87571*eV,
      1.87855*eV, 1.8814*eV, 1.88426*eV, 1.88713*eV, 1.89*eV, 1.89289*eV, 1.89578*eV, 1.89869*eV, 1.9016*eV, 1.90452*eV,
      1.90745*eV, 1.91039*eV, 1.91334*eV, 1.91629*eV, 1.91926*eV, 1.92224*eV, 1.92522*eV, 1.92821*eV, 1.93122*eV, 1.93423*eV,
      1.93725*eV, 1.94028*eV, 1.94333*eV, 1.94638*eV, 1.94944*eV, 1.95251*eV, 1.95559*eV, 1.95868*eV, 1.96178*eV, 1.96488*eV,
      1.968*eV, 1.97113*eV, 1.97427*eV, 1.97742*eV, 1.98058*eV, 1.98375*eV, 1.98693*eV, 1.99012*eV, 1.99331*eV, 1.99652*eV,
      1.99974*eV, 2.00298*eV, 2.00622*eV, 2.00947*eV, 2.01273*eV, 2.016*eV, 2.01929*eV, 2.02258*eV, 2.02589*eV, 2.0292*eV,
      2.03253*eV, 2.03587*eV, 2.03921*eV, 2.04257*eV, 2.04594*eV, 2.04933*eV, 2.05272*eV, 2.05612*eV, 2.05954*eV, 2.06296*eV,
      2.0664*eV, 2.06985*eV, 2.07331*eV, 2.07679*eV, 2.08027*eV, 2.08377*eV, 2.08728*eV, 2.0908*eV, 2.09433*eV, 2.09787*eV,
      2.10143*eV, 2.10499*eV, 2.10857*eV, 2.11217*eV, 2.11577*eV, 2.11939*eV, 2.12302*eV, 2.12666*eV, 2.13031*eV, 2.13398*eV,
      2.13766*eV, 2.14135*eV, 2.14506*eV, 2.14877*eV, 2.1525*eV, 2.15625*eV, 2.16*eV, 2.16377*eV, 2.16756*eV, 2.17135*eV,
      2.17516*eV, 2.17898*eV, 2.18282*eV, 2.18667*eV, 2.19053*eV, 2.19441*eV, 2.1983*eV, 2.20221*eV, 2.20612*eV, 2.21006*eV,
      2.214*eV, 2.21796*eV, 2.22194*eV, 2.22593*eV, 2.22993*eV, 2.23395*eV, 2.23798*eV, 2.24203*eV, 2.24609*eV, 2.25017*eV,
      2.25426*eV, 2.25836*eV, 2.26249*eV, 2.26662*eV, 2.27077*eV, 2.27494*eV, 2.27912*eV, 2.28332*eV, 2.28753*eV, 2.29176*eV,
      2.296*eV, 2.30026*eV, 2.30454*eV, 2.30883*eV, 2.31314*eV, 2.31746*eV, 2.3218*eV, 2.32616*eV, 2.33053*eV, 2.33492*eV,
      2.33932*eV, 2.34375*eV, 2.34819*eV, 2.35264*eV, 2.35711*eV, 2.3616*eV, 2.36611*eV, 2.37063*eV, 2.37518*eV, 2.37973*eV,
      2.38431*eV, 2.38891*eV, 2.39352*eV, 2.39815*eV, 2.40279*eV, 2.40746*eV, 2.41214*eV, 2.41685*eV, 2.42157*eV, 2.42631*eV,
      2.43106*eV, 2.43584*eV, 2.44063*eV, 2.44545*eV, 2.45028*eV, 2.45513*eV, 2.46*eV, 2.46489*eV, 2.4698*eV, 2.47473*eV,
      2.47968*eV, 2.48465*eV, 2.48964*eV, 2.49465*eV, 2.49968*eV, 2.50473*eV, 2.5098*eV, 2.51489*eV, 2.52*eV, 2.52514*eV,
      2.53029*eV, 2.53546*eV, 2.54066*eV, 2.54588*eV, 2.55111*eV, 2.55637*eV, 2.56166*eV, 2.56696*eV, 2.57229*eV, 2.57763*eV,
      2.583*eV, 2.5884*eV, 2.59381*eV, 2.59925*eV, 2.60471*eV, 2.61019*eV, 2.6157*eV, 2.62123*eV, 2.62678*eV, 2.63236*eV,
      2.63796*eV, 2.64359*eV, 2.64923*eV, 2.65491*eV, 2.6606*eV, 2.66633*eV, 2.67207*eV, 2.67784*eV, 2.68364*eV, 2.68946*eV,
      2.69531*eV, 2.70118*eV, 2.70708*eV, 2.713*eV, 2.71895*eV, 2.72493*eV, 2.73093*eV, 2.73696*eV, 2.74301*eV, 2.7491*eV,
      2.7552*eV, 2.76134*eV, 2.7675*eV, 2.7737*eV, 2.77991*eV, 2.78616*eV, 2.79244*eV, 2.79874*eV, 2.80507*eV, 2.81143*eV,
      2.81782*eV, 2.82424*eV, 2.83069*eV, 2.83717*eV, 2.84367*eV, 2.85021*eV, 2.85678*eV, 2.86338*eV, 2.87*eV, 2.87666*eV,
      2.88335*eV, 2.89007*eV, 2.89683*eV, 2.90361*eV, 2.91043*eV, 2.91727*eV, 2.92416*eV, 2.93107*eV, 2.93801*eV, 2.94499*eV,
      2.952*eV, 2.95905*eV, 2.96613*eV, 2.97324*eV, 2.98039*eV, 2.98757*eV, 2.99479*eV, 3.00204*eV, 3.00932*eV, 3.01665*eV,
      3.024*eV, 3.0314*eV, 3.03883*eV, 3.04629*eV, 3.0538*eV, 3.06134*eV, 3.06892*eV, 3.07653*eV, 3.08418*eV, 3.09187*eV,
      3.0996*eV, 3.10737*eV, 3.11518*eV, 3.12303*eV, 3.13091*eV, 3.13884*eV, 3.14681*eV, 3.15481*eV, 3.16286*eV, 3.17095*eV,
      3.17908*eV, 3.18725*eV, 3.19547*eV, 3.20373*eV, 3.21203*eV, 3.22037*eV, 3.22875*eV, 3.23719*eV, 3.24566*eV, 3.25418*eV,
      3.26274*eV, 3.27135*eV, 3.28*eV, 3.28871*eV, 3.29745*eV, 3.30624*eV, 3.31509*eV, 3.32397*eV, 3.33291*eV, 3.34189*eV,
      3.35092*eV, 3.36001*eV, 3.36914*eV, 3.37832*eV, 3.38755*eV, 3.39683*eV, 3.40616*eV, 3.41554*eV, 3.42498*eV, 3.43447*eV,
      3.44401*eV, 3.4536*eV, 3.46325*eV, 3.47295*eV, 3.4827*eV, 3.49251*eV, 3.50238*eV, 3.5123*eV, 3.52228*eV, 3.53231*eV,
      3.54241*eV, 3.55256*eV, 3.56276*eV, 3.57303*eV, 3.58336*eV, 3.59374*eV, 3.60419*eV, 3.6147*eV, 3.62527*eV, 3.6359*eV,
      3.64659*eV, 3.65735*eV, 3.66817*eV, 3.67906*eV, 3.69001*eV, 3.70102*eV, 3.7121*eV, 3.72325*eV, 3.73446*eV, 3.74575*eV,
      3.7571*eV, 3.76852*eV, 3.78001*eV, 3.79157*eV, 3.8032*eV, 3.8149*eV, 3.82667*eV, 3.83852*eV, 3.85044*eV, 3.86244*eV,
      3.87451*eV, 3.88665*eV, 3.89887*eV, 3.91117*eV, 3.92355*eV, 3.93601*eV, 3.94854*eV, 3.96116*eV, 3.97385*eV, 3.98663*eV,
      3.99949*eV, 4.01243*eV, 4.02546*eV, 4.03857*eV, 4.05177*eV, 4.06506*eV, 4.07843*eV, 4.09189*eV, 4.10544*eV, 4.11908*eV,
      4.13281*eV, 4.14663*eV, 4.16054*eV, 4.17455*eV, 4.18865*eV, 4.20285*eV, 4.21715*eV, 4.23154*eV, 4.24603*eV, 4.26062*eV,
      4.27532*eV, 4.29011*eV, 4.30501*eV, 4.32001*eV, 4.33511*eV, 4.35032*eV, 4.36564*eV, 4.38107*eV, 4.3966*eV, 4.41225*eV,
      4.42801*eV, 4.44388*eV, 4.45986*eV, 4.47596*eV, 4.49218*eV, 4.50852*eV, 4.52497*eV, 4.54155*eV, 4.55824*eV, 4.57506*eV,
      4.59201*eV, 4.60908*eV, 4.62628*eV, 4.6436*eV, 4.66106*eV, 4.67865*eV, 4.69637*eV, 4.71423*eV, 4.73222*eV, 4.75035*eV,
      4.76862*eV, 4.78703*eV, 4.80559*eV, 4.82429*eV, 4.84313*eV, 4.86212*eV, 4.88127*eV, 4.90056*eV, 4.92001*eV, 4.93961*eV,
      4.95937*eV, 4.97928*eV, 4.99936*eV, 5.0196*eV, 5.04001*eV, 5.06058*eV, 5.08132*eV, 5.10223*eV, 5.12331*eV, 5.14457*eV,
      5.16601*eV, 5.18762*eV, 5.20942*eV, 5.2314*eV, 5.25357*eV, 5.27592*eV, 5.29847*eV, 5.32121*eV, 5.34415*eV, 5.36728*eV,
      5.39062*eV, 5.41416*eV, 5.4379*eV, 5.46186*eV, 5.48603*eV, 5.51041*eV, 5.53501*eV, 5.55983*eV, 5.58487*eV, 5.61014*eV,
      5.63564*eV, 5.66138*eV, 5.68735*eV, 5.71356*eV, 5.74001*eV, 5.76671*eV, 5.79365*eV, 5.82085*eV, 5.84831*eV, 5.87603*eV,
      5.90401*eV, 5.93226*eV, 5.96078*eV, 5.98957*eV, 6.01865*eV, 6.04801*eV, 6.07766*eV, 6.1076*eV, 6.13783*eV, 6.16837*eV,
      6.19921*eV };
  G4double FastComponent[nEntries_FAST] =
    { 5.48303e-45, 1.10277e-44, 2.21239e-44, 4.42745e-44, 8.83811e-44, 1.75987e-43, 3.49554e-43, 6.92569e-43, 1.36876e-42, 2.69838e-42,
      5.30634e-42, 1.04088e-41, 2.03667e-41, 3.97517e-41, 7.73935e-41, 1.50303e-40, 2.91169e-40, 5.62647e-40, 1.08453e-39, 2.08527e-39,
      3.99941e-39, 7.65147e-39, 1.46018e-38, 2.77962e-38, 5.27808e-38, 9.99728e-38, 1.88887e-37, 3.55988e-37, 6.69243e-37, 1.25501e-36,
      2.3476e-36, 4.38041e-36, 8.15305e-36, 1.5137e-35, 2.80333e-35, 5.17872e-35, 9.543e-35, 1.75413e-34, 3.21627e-34, 5.88244e-34,
      1.07319e-33, 1.95304e-33, 3.54535e-33, 6.4198e-33, 1.15957e-32, 2.08924e-32, 3.75486e-32, 6.73153e-32, 1.20378e-31, 2.14731e-31,
      3.82083e-31, 6.78163e-31, 1.20067e-30, 2.12046e-30, 3.7355e-30, 6.56421e-30, 1.15062e-29, 2.01183e-29, 3.50888e-29, 6.10463e-29,
      1.05941e-28, 1.83393e-28, 3.16677e-28, 5.45461e-28, 9.37186e-28, 1.60621e-27, 2.74595e-27, 4.68271e-27, 7.96556e-27, 1.3516e-26,
      2.28769e-26, 3.86241e-26, 6.50481e-26, 1.09276e-25, 1.83117e-25, 3.06089e-25, 5.10365e-25, 8.48845e-25, 1.40828e-24, 2.33059e-24,
      3.8473e-24, 6.3352e-24, 1.04059e-23, 1.70495e-23, 2.7865e-23, 4.54277e-23, 7.38748e-23, 1.19836e-22, 1.93906e-22, 3.12974e-22,
      5.03897e-22, 8.09261e-22, 1.29643e-21, 2.07169e-21, 3.30229e-21, 5.25072e-21, 8.32794e-21, 1.31756e-20, 2.0793e-20, 3.27324e-20,
      5.13989e-20, 8.05088e-20, 1.2579e-19, 1.96049e-19, 3.04788e-19, 4.72655e-19, 7.31148e-19, 1.12819e-18, 1.73648e-18, 2.66608e-18,
      4.08312e-18, 6.2377e-18, 9.50541e-18, 1.44488e-17, 2.19082e-17, 3.31357e-17, 4.99919e-17, 7.52346e-17, 1.1294e-16, 1.6912e-16,
      2.52614e-16, 3.76384e-16, 5.59398e-16, 8.29324e-16, 1.22643e-15, 1.80915e-15, 2.66207e-15, 3.90734e-15, 5.72078e-15, 8.35496e-15,
      1.21716e-14, 1.76875e-14, 2.56388e-14, 3.70718e-14, 5.34692e-14, 7.69269e-14, 1.10399e-13, 1.58041e-13, 2.25677e-13, 3.21454e-13,
      4.56736e-13, 6.4733e-13, 9.15166e-13, 1.29059e-12, 1.81548e-12, 2.54747e-12, 3.56566e-12, 4.97836e-12, 6.9334e-12, 9.63209e-12,
      1.33478e-11, 1.84507e-11, 2.54407e-11, 3.49913e-11, 4.80072e-11, 6.57001e-11, 8.96892e-11, 1.22132e-10, 1.65894e-10, 2.24775e-10,
      3.03794e-10, 4.09567e-10, 5.50788e-10, 7.38854e-10, 9.8866e-10, 1.31962e-09, 1.75698e-09, 2.33344e-09, 3.09131e-09, 4.0851e-09,
      5.38488e-09, 7.0805e-09, 9.28681e-09, 1.21502e-08, 1.58567e-08, 2.06424e-08, 2.68052e-08, 3.4721e-08, 4.48622e-08, 5.78206e-08,
      7.4336e-08, 9.533e-08, 1.21948e-07, 1.55609e-07, 1.98065e-07, 2.51475e-07, 3.18491e-07, 4.02359e-07, 5.07043e-07, 6.37367e-07,
      7.99187e-07, 9.9959e-07, 1.24712e-06, 1.55207e-06, 1.92676e-06, 2.38593e-06, 2.94715e-06, 3.6313e-06, 4.46308e-06, 5.4717e-06,
      6.69151e-06, 8.16282e-06, 9.93277e-06, 1.20563e-05, 1.45973e-05, 1.76298e-05, 2.1239e-05, 2.55232e-05, 3.05951e-05, 3.65832e-05,
      4.36341e-05, 5.19141e-05, 6.1611e-05, 7.29365e-05, 8.61284e-05, 0.0001015, 0.0001192, 0.0001397, 0.0001633, 0.0001905,
      0.0002216, 0.0002571, 0.0002976, 0.0003436, 0.0003958, 0.0004547, 0.000521, 0.0005956, 0.0006791, 0.0007725,
      0.0008764, 0.0009919, 0.0011197, 0.0012609, 0.0014164, 0.001587, 0.0017737, 0.0019775, 0.0021992, 0.0024396,
      0.0026995, 0.0029797, 0.0032808, 0.0036032, 0.0039475, 0.0043139, 0.0047025, 0.0051132, 0.005546, 0.0060005,
      0.0064759, 0.0069715, 0.0074864, 0.0080192, 0.0085684, 0.0091325, 0.0097093, 0.0102968, 0.0108926, 0.0114941,
      0.0120985, 0.012703, 0.0133043, 0.0138992, 0.0144846, 0.0150569, 0.0156127, 0.0161486, 0.0166612, 0.0171472,
      0.0176033, 0.0180263, 0.0184135, 0.018762, 0.0190694, 0.0193334, 0.0195521, 0.019724, 0.0198476, 0.0199222,
      0.0199471, 0.0199222, 0.0198476, 0.019724, 0.0195521, 0.0193334, 0.0190694, 0.018762, 0.0184135, 0.0180263,
      0.0176033, 0.0171472, 0.0166612, 0.0161486, 0.0156127, 0.0150569, 0.0144846, 0.0138992, 0.0133043, 0.012703,
      0.0120985, 0.0114941, 0.0108926, 0.0102968, 0.0097093, 0.0091325, 0.0085684, 0.0080192, 0.0074864, 0.0069715,
      0.0064759, 0.0060005, 0.005546, 0.0051132, 0.0047025, 0.0043139, 0.0039475, 0.0036032, 0.0032808, 0.0029797,
      0.0026995, 0.0024396, 0.0021992, 0.0019775, 0.0017737, 0.001587, 0.0014164, 0.0012609, 0.0011197, 0.0009919,
      0.0008764, 0.0007725, 0.0006791, 0.0005956, 0.000521, 0.0004547, 0.0003958, 0.0003436, 0.0002976, 0.0002571,
      0.0002216, 0.0001905, 0.0001633, 0.0001397, 0.0001192, 0.0001015, 8.61284e-05, 7.29365e-05, 6.1611e-05, 5.19141e-05,
      4.36341e-05, 3.65832e-05, 3.05951e-05, 2.55232e-05, 2.1239e-05, 1.76298e-05, 1.45973e-05, 1.20563e-05, 9.93277e-06, 8.16282e-06,
      6.69151e-06, 5.4717e-06, 4.46308e-06, 3.6313e-06, 2.94715e-06, 2.38593e-06, 1.92676e-06, 1.55207e-06, 1.24712e-06, 9.9959e-07,
      7.99187e-07, 6.37367e-07, 5.07043e-07, 4.02359e-07, 3.18491e-07, 2.51475e-07, 1.98065e-07, 1.55609e-07, 1.21948e-07, 9.533e-08,
      7.4336e-08, 5.78206e-08, 4.48622e-08, 3.4721e-08, 2.68052e-08, 2.06424e-08, 1.58567e-08, 1.21502e-08, 9.28681e-09, 7.0805e-09,
      5.38488e-09, 4.0851e-09, 3.09131e-09, 2.33344e-09, 1.75698e-09, 1.31962e-09, 9.8866e-10, 7.38854e-10, 5.50788e-10, 4.09567e-10,
      3.03794e-10, 2.24775e-10, 1.65894e-10, 1.22132e-10, 8.96892e-11, 6.57001e-11, 4.80072e-11, 3.49913e-11, 2.54407e-11, 1.84507e-11,
      1.33478e-11, 9.63209e-12, 6.9334e-12, 4.97836e-12, 3.56566e-12, 2.54747e-12, 1.81548e-12, 1.29059e-12, 9.15166e-13, 6.4733e-13,
      4.56736e-13, 3.21454e-13, 2.25677e-13, 1.58041e-13, 1.10399e-13, 7.69269e-14, 5.34692e-14, 3.70718e-14, 2.56388e-14, 1.76875e-14,
      1.21716e-14, 8.35496e-15, 5.72078e-15, 3.90734e-15, 2.66207e-15, 1.80915e-15, 1.22643e-15, 8.29324e-16, 5.59398e-16, 3.76384e-16,
      2.52614e-16, 1.6912e-16, 1.1294e-16, 7.52346e-17, 4.99919e-17, 3.31357e-17, 2.19082e-17, 1.44488e-17, 9.50541e-18, 6.2377e-18,
      4.08312e-18, 2.66608e-18, 1.73648e-18, 1.12819e-18, 7.31148e-19, 4.72655e-19, 3.04788e-19, 1.96049e-19, 1.2579e-19, 8.05088e-20,
      5.13989e-20, 3.27324e-20, 2.0793e-20, 1.31756e-20, 8.32794e-21, 5.25072e-21, 3.30229e-21, 2.07169e-21, 1.29643e-21, 8.09261e-22,
      5.03897e-22, 3.12974e-22, 1.93906e-22, 1.19836e-22, 7.38748e-23, 4.54277e-23, 2.7865e-23, 1.70495e-23, 1.04059e-23, 6.3352e-24,
      3.8473e-24, 2.33059e-24, 1.40828e-24, 8.48845e-25, 5.10365e-25, 3.06089e-25, 1.83117e-25, 1.09276e-25, 6.50481e-26, 3.86241e-26,
      2.28769e-26, 1.3516e-26, 7.96556e-27, 4.68271e-27, 2.74595e-27, 1.60621e-27, 9.37186e-28, 5.45461e-28, 3.16677e-28, 1.83393e-28,
      1.05941e-28 };
  
  G4double PbWO_indexZero = 1.5861;
  G4double PbWO_nVec[1]   = { 1.1062 };
  G4double PbWO_lVec[1]   = { 270.63 };
  int sizeVect = sizeof(PbWO_nVec)/sizeof(*PbWO_nVec);
  
  const G4int nEntries_RI = 5;
  G4double PhotonEnergy_RI[nEntries_RI] =
    { 0.0001 * eV, 1.0 * eV, 1.84 * eV, 2.952 * eV, 4.08 * eV };
  G4double RefractiveIndex[nEntries_RI] =
    { CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[0])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[1])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[2])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[3])),
      CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(PhotonEnergy_RI[4])) };
  
  const G4int nEntries_ABS = 70;
  G4double PhotonEnergy_ABS[nEntries_ABS] =
    { 1.25237 * eV, 1.26514 * eV, 1.27819 * eV, 1.2915 * eV, 1.3051 * eV, 1.31898 * eV, 1.33316 * eV, 1.34765 * eV, 1.36246 * eV, 1.3776 * eV,
      1.39308 * eV, 1.40891 * eV, 1.42511 * eV, 1.44168 * eV, 1.45864 * eV, 1.476 * eV, 1.49379 * eV, 1.512 * eV, 1.53067 * eV, 1.5498 * eV,
      1.56942 * eV, 1.58954 * eV, 1.61018 * eV, 1.63137 * eV, 1.65312 * eV, 1.67546 * eV, 1.69841 * eV, 1.722 * eV, 1.74626 * eV, 1.7712 * eV,
      1.79687 * eV, 1.8233 * eV, 1.85051 * eV, 1.87855 * eV, 1.90745 * eV, 1.93725 * eV, 1.968 * eV, 1.99974 * eV, 2.03253 * eV, 2.0664 * eV,
      2.10143 * eV, 2.13766 * eV, 2.17516 * eV, 2.214 * eV, 2.25426 * eV, 2.296 * eV, 2.33932 * eV, 2.38431 * eV, 2.43106 * eV, 2.47968 * eV,
      2.53029 * eV, 2.583 * eV, 2.63796 * eV, 2.69531 * eV, 2.7552 * eV, 2.81782 * eV, 2.88335 * eV, 2.952 * eV, 3.024 * eV, 3.0996 * eV,
      3.17908 * eV, 3.26274 * eV, 3.35092 * eV, 3.44401 * eV, 3.54241 * eV, 3.64659 * eV, 3.7571 * eV, 3.87451 * eV, 3.99949 * eV, 4.13281 * eV };
  G4double Absorption[nEntries_ABS] =
    { 3110 * mm, 3110 * mm, 3110 * mm, 3110 * mm, 3110 * mm, 3105 * mm, 3105 * mm, 3105 * mm, 3105 * mm, 3105 * mm,
      3105 * mm, 2745 * mm, 2460 * mm, 2230 * mm, 2039 * mm, 1877 * mm, 1859 * mm, 1826 * mm, 1764 * mm, 1760 * mm,
      1664 * mm, 1585 * mm, 1471 * mm, 1376 * mm, 1272 * mm, 1187 * mm, 1114 * mm, 1046 * mm, 993.2 * mm, 942.9 * mm,
      898.8 * mm, 856.9 * mm, 821.7 * mm, 794.2 * mm, 767.7 * mm, 746.5 * mm, 725.6 * mm, 710.7 * mm, 695.3 * mm, 686.2 * mm,
      674.8 * mm, 663.5 * mm, 648.3 * mm, 633.4 * mm, 622.3 * mm, 607.8 * mm, 590.9 * mm, 568.9 * mm, 541.4 * mm, 502.9 * mm,
      467 * mm, 430.2 * mm, 390.1 * mm, 345.3 * mm, 298.9 * mm, 256.7 * mm, 219.8 * mm, 185.4 * mm, 150.9 * mm, 116.4 * mm,
      84.8 * mm, 59.4 * mm, 41.1 * mm, 27.5 * mm, 24.2 * mm, 24.2 * mm, 24.3 * mm, 24.3 * mm, 24.4 * mm, 24.6 * mm };
  
  const G4int nEntries_SCY = 12;
  G4double ElectronEnergy_SCY[nEntries_SCY] =
    { 0.000 * MeV, 0.015 * MeV, 0.020 * MeV, 0.030 * MeV,
      0.040 * MeV, 0.060 * MeV, 0.080 * MeV, 0.090 * MeV,
      0.105 * MeV, 0.300 * MeV, 0.500 * MeV, 1.000 * MeV };
  G4double ScintilYield[nEntries_SCY] =
    { 0.10, 0.46, 0.60, 0.68,
      0.74, 0.80, 0.82, 0.84,
      0.87,  0.96,  0.98,  1.00 };
  for(int i = 0; i < nEntries_SCY; i++)
    ScintilYield[i] = 60000.0 * MeV * ScintilYield[i] * ElectronEnergy_SCY[i];
  
  G4MaterialPropertiesTable* myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty ("FASTCOMPONENT", PhotonEnergy_FAST, FastComponent,   nEntries_FAST);
  myMPT->AddProperty ("RINDEX",        PhotonEnergy_RI,   RefractiveIndex, nEntries_RI);
  myMPT->AddProperty ("ABSLENGTH",     PhotonEnergy_ABS,  Absorption,      nEntries_ABS);
  myMPT->AddProperty ("ELECTRONSCINTILLATIONYIELD", ElectronEnergy_SCY, ScintilYield, nEntries_SCY);
  myMPT->AddConstProperty ("SCINTILLATIONYIELD", 60000./MeV);
  myMPT->AddConstProperty ("RESOLUTIONSCALE", 3.2);
  myMPT->AddConstProperty ("FASTTIMECONSTANT", 40.*ns);
  myMPT->AddConstProperty ("YIELDRATIO", 1.0);
  myMPT->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * ns);
  
  mat->SetMaterialPropertiesTable (myMPT);
  
  return mat;
}



G4double MyMaterials::CalculateSellmeier (int size, G4double indexZero, G4double *nVec, G4double *lVec, G4double wavelength)
{
  /*------http://gentitfx.fr/SLitrani/code/SLitraniCode/TLitSellmeier.html----*/
  
  float partial = indexZero * indexZero;
  float sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += nVec[i] * nVec[i] / (1 - lVec[i] * lVec[i] / (wavelength*wavelength));
  }
  
  partial += sum;
  partial += 1;
  
  //G4cout << "Wavelength: " << wavelength << " -> rifr. index: " << sqrt(partial) << G4endl;
  
  return sqrt(partial);
}



G4double MyMaterials::fromEvToNm (G4double energy)
{
  return 1239.84187 / energy;
}

G4double MyMaterials::fromNmToEv (G4double wavelength)
{
  return 1239.84187 / wavelength;
}
