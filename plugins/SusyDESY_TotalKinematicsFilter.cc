#include "SUSYBSMAnalysis/DesySusy/interface/SusyDESY_TotalKinematicsFilter.h"

//using namespace edm;

SusyDESY_TotalKinematicsFilterResult::SusyDESY_TotalKinematicsFilterResult(const edm::ParameterSet& iPSet) :  
   Prefix( iPSet.getParameter<string> ("Prefix") ),
   Suffix( iPSet.getParameter<string> ("Suffix") ),
   src_(iPSet.getParameter<edm::InputTag>("src")),
   tolerance_(iPSet.getParameter<double>("tolerance")),
   verbose_(iPSet.getUntrackedParameter<bool>("verbose"))
{
  produces <bool>                 ( Prefix + "GenParticleHandleValid"  + Suffix );
  produces <bool>                 ( Prefix + "Passed"  + Suffix );
}

SusyDESY_TotalKinematicsFilterResult::~SusyDESY_TotalKinematicsFilterResult() {}

void SusyDESY_TotalKinematicsFilterResult::produce(edm::Event& iEvent,const edm::EventSetup& iSetup)
{ 

  float nEcms = 0.;
  unsigned int nInit = 0;

  std::vector<float> p4tot(4,0.);
  unsigned int nPart = 0;

  edm::Handle<reco::GenParticleCollection> genParticles;
  iEvent.getByLabel(src_, genParticles );

  std::auto_ptr<bool> handleValid ( new bool(false) );
  std::auto_ptr<bool> passed      ( new bool(false)  );
  if(genParticles.isValid()) {
    *handleValid.get() = true;

    for (reco::GenParticleCollection::const_iterator iter=genParticles->begin();iter!=genParticles->end();++iter){
      if ( nInit < 3 && (*iter).status() == 3 && (*iter).pdgId() == 2212 ) {
	nInit++;
	nEcms += (*iter).energy();
      }
      if ( (*iter).status() == 1) { 
	nPart++;
	if (verbose_) {
	  std::cout << "Status 1 part # " << std::setw(4) << std::fixed << nPart 
		    << std::setw(14) << std::fixed << (*iter).pdgId() 
		    << std::setw(14) << std::fixed << (*iter).px() 
		    << std::setw(14) << std::fixed << (*iter).py() 
		    << std::setw(14) << std::fixed << (*iter).pz() << std::endl;
	}
	p4tot[0] += (*iter).px();
	p4tot[1] += (*iter).py();
	p4tot[2] += (*iter).pz();
	p4tot[3] += std::sqrt( (*iter).px()*(*iter).px() + 
			       (*iter).py()*(*iter).py() + 
			       (*iter).pz()*(*iter).pz() + 
			       (*iter).mass()*(*iter).mass()) ; 
      }
    }
    
    if ( verbose_ ) {
      std::cout << "Initial sqrt(s) = " << nEcms << std::endl;
      for (unsigned int i=0; i<4; i++) {
	std::cout << "p4tot["<<i<<"] = " << p4tot[i] << std::endl;
      }
    }
    
    bool pass = true;
    if ( std::abs(p4tot[0]) > tolerance_ || std::abs(p4tot[1]) > tolerance_ || std::abs(p4tot[2]) > tolerance_ || std::abs(p4tot[3]-nEcms) > tolerance_ ) 
      { pass = false; 
	if ( verbose_ )
	   std::cout<<"totalKinematics failed"<<std::endl;
      }
    *passed.get() = pass;
  }

  iEvent.put( handleValid , Prefix + "GenParticleHandleValid" + Suffix );
  iEvent.put( passed      , Prefix + "Passed"                 + Suffix );

  //return pass;
  
}

void SusyDESY_TotalKinematicsFilterResult::beginJob(){}
