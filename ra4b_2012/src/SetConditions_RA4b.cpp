#include "TSystem.h"
#include "Math/VectorUtil.h"
#include "NtupleTools2_h.h"
#include "ConfigReader.h"
#include "CutFlow.h"
#include "THTools.h"
#include "eventselection.h"
#include "SampleInformation.h"

using namespace std;
using namespace ROOT::Math::VectorUtil;


//WHAT ESTIMATION AND WHAT SAMPLE

void SetConditions_RA4b(SampleInformation mySampleInformation){
//SetOfCuts SetConditions_RA4b(string Sample,string SubSample,string WhatEstimation){

  ConfigReader config;
  //  SetOfCuts mySetOfCuts;


  if(mySampleInformation.GetEstimation()=="RA4b-mu" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(2,"above","jets>2");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(300.0,"above","HT above 300");
    //<<<<<<< SetConditions_RA4b.cpp
    SetOfCuts::Event.MET.Set(60.0,"above","MET above 60");
    //============================================
  }



  else if(mySampleInformation.GetEstimation()=="RA4b-mu-4Jets" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1.0,"above","HT above 300");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    //============================================
  }



  else if(mySampleInformation.GetEstimation()=="CR1" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(2,"below","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(2,"below","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(0,"equal","exacxtly 0 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(100.,"above","MT2 above 120");
    //============================================

  }  

  else if(mySampleInformation.GetEstimation()=="CR1Muons-NoMT2" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(0,"equal","exacxtly 0 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(-1.,"above","No MT2 Cut");
    //============================================


  }  



  else if(mySampleInformation.GetEstimation()=="CR1Electrons-baseline" ){
    

    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(-1,"above","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(-1,"above","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(50.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(-1.,"above","No MT2 Cut");
    //============================================


  }



  else if(mySampleInformation.GetEstimation()=="CR1Muons-baseline" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(-1,"above","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(-1,"above","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(50.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(-1.,"above","No MT2 Cut");
    //============================================


  }



  else if(mySampleInformation.GetEstimation()=="CR1Muons-NoMT2-2btags" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(2,"below","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(2,"below","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(2,"equal","exactly 2 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(-1.,"above","No MT2 Cut");
    //============================================


  }  


  else if(mySampleInformation.GetEstimation()=="CR1Muons" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(0,"equal","exacxtly 0 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(100.,"above","MT2 above 120");
    //============================================

  }


  else if(mySampleInformation.GetEstimation()=="CRFMuons" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(2,"equal","exactly 2 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(100.,"above","MT2 above 120");
    //============================================
  }





  else if(mySampleInformation.GetEstimation()=="CR1Electrons" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(0,"equal","exacxtly 0 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(100.,"above","MT2 above 120");
    //============================================

  }



  else if(mySampleInformation.GetEstimation()=="CR1Electrons-NoMT2" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(0,"equal","exacxtly 0 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(-1.,"above","no MT2 cut");
    //============================================

  }


  else if(mySampleInformation.GetEstimation()=="CRFElectrons" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(2,"equal","exactly 2 btags");
    SetOfCuts::Event.HT.Set(-1,"above","Any HT");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    SetOfCuts::Event.MT2.Set(100.,"above","MT2 above 120");
    //============================================
  }






  else if(mySampleInformation.GetEstimation()=="RA4b-el" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"equal","one signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","no muons");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(2,"above","jets>2");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(300.0,"above","HT above 300");
    SetOfCuts::Event.MET.Set(60.,"above","MET above 100");
    //============================================
  }

  else if(mySampleInformation.GetEstimation()=="RA4b-el-4Jets" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"equal","one signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","no signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(3,"above","jets>3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(0.0,"above","HT above 300");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    //============================================
  }
  
  
  else if(mySampleInformation.GetEstimation()=="RA4b-singleLep" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(-1,"above","one signal electron");
    SetOfCuts::WideElectrons.NUM.Set(-1,"above","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(-1,"above","no muons");
    SetOfCuts::WideMuons.NUM.Set(-1,"above","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(2,"above","jets>2");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(0,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1.0,"above","HT above 300");
    SetOfCuts::Event.MET.Set(50.,"above","MET above 50");
    //============================================


  }
  else if(mySampleInformation.GetEstimation()=="RA4b-mu-HighPt" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    //
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(2,"above","jets>2");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(300.0,"above","HT above 300");
    SetOfCuts::Event.MET.Set(100.,"above","MET above 100");
    //============================================

  }  
  else if(mySampleInformation.GetEstimation()=="RA4b-el-HighPt" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"equal","one signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","no muons");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(2,"above","jets>2");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(300.0,"above","HT above 300");
    SetOfCuts::Event.MET.Set(60.,"above","MET above 100");
    //============================================
    
  }
  else if(mySampleInformation.GetEstimation()=="STOP-mu" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","no signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","no wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"equal","one signal muon");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","no wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"equal","one single lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(2,"above","jets>=3");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1.,"above","HT above 0");
    SetOfCuts::Event.MET.Set(-1.,"above","MET above 0");
    //============================================
    
  }
  else if(mySampleInformation.GetEstimation()=="RA4b-diMuSync" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(-1,"above","Any tight electrons");
    SetOfCuts::WideElectrons.NUM.Set(-1,"above","Any wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(1,"above","Two or more tight muons");
    SetOfCuts::WideMuons.NUM.Set(-1,"above","Any wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"above","more than one tight lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(-1,"above","jets>=0");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1.,"above","HT above 0");
    SetOfCuts::Event.MET.Set(-1.,"above","MET above 0");
    //============================================
    
  }
  else if(mySampleInformation.GetEstimation()=="RA4b-diElSync" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(1,"above","Two or more tight electrons");
    SetOfCuts::WideElectrons.NUM.Set(-1,"above","Any wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(-1,"above","Any tight muons");
    SetOfCuts::WideMuons.NUM.Set(-1,"above","Any wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"above","more than one tight lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(-1,"above","jets>=0");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(0.,"above","HT above 0");
    SetOfCuts::Event.MET.Set(0.,"above","MET above 0");
    //============================================
    
  }
  else if(mySampleInformation.GetEstimation()=="RA4b-MuEGSync" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"above","One or more tight electrons");
    SetOfCuts::WideElectrons.NUM.Set(-1,"above","Any wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"above","One or more tight muons");
    SetOfCuts::WideMuons.NUM.Set(-1,"above","Any wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"above","more than one tight lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(1,"above","jets>1");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(0.,"above","HT above 0");
    SetOfCuts::Event.MET.Set(0.,"above","MET above 0");
    //============================================
    
  }
  else if(mySampleInformation.GetEstimation()=="RA4b-diMu" ){
    
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","Exactly zero signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","any wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(2,"equal","Exactly two muons");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","No wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(1,"above","more than one lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(1,"above","jets>1");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(0.,"above","HT above 0");
    SetOfCuts::Event.MET.Set(0.,"above","MET above 0");
    //============================================
    
  }
    else if(mySampleInformation.GetEstimation()=="TrigStudy-mu" ){
      
      //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(0,"equal","Exactly zero signal electron");
    SetOfCuts::WideElectrons.NUM.Set(0,"equal","any wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(2,"equal","Exactly two muons");
    SetOfCuts::WideMuons.NUM.Set(-1,"above","No wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(-1,"above","more than one lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(-1,"above","jets>=0");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1.,"above","HT above -1");
    SetOfCuts::Event.MET.Set(0.,"above","MET above 0");
    //============================================
  }
  else if(mySampleInformation.GetEstimation()=="TrigStudy-el" ){
      
    //============================================
    //ELECTRONS
    //============================================
    SetOfCuts::SignalElectrons.NUM.Set(2,"equal","Exactly two signal electron");
    SetOfCuts::WideElectrons.NUM.Set(-1,"above","No wider electrons");
    //============================================
    // MUONS
    //============================================
    SetOfCuts::SignalMuons.NUM.Set(0,"equal","Exactly zero muons");
    SetOfCuts::WideMuons.NUM.Set(0,"equal","any wider muons");
    //============================================
    //LEPTONS
    //============================================
    SetOfCuts::Leptons.NUM.Set(-1,"above","more than one lepton");
    //============================================
    //JETS
    //============================================
    SetOfCuts::Jets.NUM.Set(-1,"above","jets>=0");
    //============================================
    //EVENT
    //============================================
    SetOfCuts::Event.NumberOfBtags.Set(-1,"above","any number of btags");
    SetOfCuts::Event.HT.Set(-1.,"above","HT above -1");
    SetOfCuts::Event.MET.Set(0.,"above","MET above 0");
    //============================================
  }
  
  else{
    cout<<"The estimation "<<mySampleInformation.GetEstimation()<<" does not exist"<<endl;
    exit(1);
  }
  }








