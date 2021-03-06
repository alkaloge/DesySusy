#ifndef makeElectrons_h
#define makeElectrons_h

#include "NtupleTools2_h.h"
#include "Electron.h"
#include "Muon.h"

vector<Electron> makeAllElectrons(EasyChain* tree );
bool makeLooseElectrons(EasyChain* tree, vector<Electron>& AllElectrons, vector<Electron*>&  LooseElectrons);
bool makeTightElectrons(EasyChain* tree, vector<Electron>& AllElectrons, vector<Electron*>&  TightElectrons, CutSet* flow_in = 0);
bool makeVetoElectrons(EasyChain* tree, vector<Electron>& AllElectrons,  vector<Electron*>&  VetoElectrons, CutSet* flow_in = 0);
void makeCleanedElectrons(vector<Electron*>& Electrons_In, vector<Electron*>& Electrons_Out, vector<Muon>& Muons, CutSet* flow_in = 0);


bool makeGoodElectrons(EasyChain* tree, vector<Electron>& allElectrons, vector<Electron*>&  goodElectrons, CutSet* flow_in = 0);
bool makeSelectedElectrons(EasyChain* tree, vector<Electron>& allElectrons, vector<Electron*>&  selectedElectrons, CutSet* flow_in = 0);
bool makeCleanElectrons( vector<Electron>& allElectrons, vector<Electron*>& cleanElectrons, vector<Muon*>& muons, CutSet* flow_in = 0);

#endif
