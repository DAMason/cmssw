#ifndef DATACERTIFICATIONJETMET_H
#define DATACERTIFICATIONJETMET_H

// author: Kenichi Hatakeyama (Rockefeller U.)

// system include files
#include <memory>
#include <stdio.h>
#include <math.h>
#include <sstream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

//
// class decleration
//

class DataCertificationJetMET : public edm::EDAnalyzer {
   public:
      explicit DataCertificationJetMET(const edm::ParameterSet&);
      ~DataCertificationJetMET();

   private:
      virtual void beginJob(void) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      virtual void beginRun(const edm::Run&, const edm::EventSetup&) ;
      virtual void endRun(const edm::Run&, const edm::EventSetup&) ;

      virtual void beginLuminosityBlock(const edm::LuminosityBlock&, const edm::EventSetup&);
      virtual void endLuminosityBlock(const edm::LuminosityBlock&, const edm::EventSetup&);

   // ----------member data ---------------------------

   edm::ParameterSet conf_;
   DQMStore * dbe_;
   edm::Service<TFileService> fs_;

   int verbose_;
   bool InMemory_;
   bool isData;
   std::string metFolder;

   bool caloJetMeanTest;
   bool caloJetKSTest;
   bool pfJetMeanTest;
   bool pfJetKSTest;
   bool jptJetMeanTest;
   bool jptJetKSTest;
   bool caloMETMeanTest;
   bool caloMETKSTest;
   bool pfMETMeanTest;
   bool pfMETKSTest;
   bool tcMETMeanTest;
   bool tcMETKSTest;
   bool muMETMeanTest;
   bool muMETKSTest;

   bool jetTests[5][2];  //one for each type of jet certification/test type
   bool metTests[5][2];  //one for each type of met certification/test type

};

#endif
