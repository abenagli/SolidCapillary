SolidCapillary
==============

Simulation of a solid capillary fiber


Instructions to run the code on lxplus

1. download the code from github:
git clone git:github.com:/abenagli/SolidCapillary


2. enter the directory
cd SolidCapillary


3. source Geant4 installation at cern:
source myGeant4.sh


4. create build directory and compile the code:
mkdir build
cd build
source ../COMPILE.sh
make
cd..


5. execute it:
./build/SolidCapillary template.cfg
