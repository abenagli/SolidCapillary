//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: DetectorConstruction.hh,v 1.5 2006-06-29 17:53:55 gunter Exp $
// GEANT4 tag $Name: not supported by cvs2svn $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include <iostream>
#include <string>
#include <fstream>
#include <utility>

#include "ConfigFile.hh"
#include "MyMaterials.hh"
#include "LedFiberTiming.hh"

#include "G4Material.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4SubtractionSolid.hh"
#include "G4VisAttributes.hh"
#include "G4UniformMagField.hh"



class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  
  //! ctor
  DetectorConstruction();
  DetectorConstruction(const string& configFileName);
  
  //! dtor
  ~DetectorConstruction();
  
  //! construct method
  G4VPhysicalVolume* Construct();
  
  //! other methods
  void initializeMaterials();
  void ConstructField();
  
  Fiber* GetFiber() { return &fib; };
  
  
private:
  G4bool    checkOverlaps;
  
  G4double  expHall_x;
  G4double  expHall_y;
  G4double  expHall_z;
  
  G4int    world_material;
  G4double fibre_length;      
  G4int    detector;
  
  G4double core_radius;
  G4int    core_material;
  G4double core_rIndex;
  G4double core_absLength;
  
  G4double capillary_thickness;
  G4int    capillary_material;
  G4double capillary_rIndex;
  G4double capillary_absLength;
  
  G4double cladding_thickness;
  G4int    cladding_material;
  G4double cladding_rIndex;
  G4double cladding_absLength;
  
  G4int    gap_material;
  G4double gap_l;
  
  G4int    det_material;
  G4double det_l;
    
  G4double depth;
  
  G4UniformMagField* B_field;
  G4bool   B_field_IsInitialized; 
  G4double B_field_intensity;     // magnetic field, in units of Tesla
  
  Fiber fib;
  
  //Materials
  G4Material* WoMaterial;
  G4Material* CoMaterial;
  G4Material* CaMaterial;
  G4Material* ClMaterial;
  G4Material* GaMaterial;
  G4Material* DeMaterial;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif /*DetectorConstruction_h*/
