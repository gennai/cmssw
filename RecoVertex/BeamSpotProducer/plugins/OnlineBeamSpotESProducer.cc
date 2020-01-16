#include "RecoVertex/BeamSpotProducer/OnlineBeamSpotESProducer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/Framework/interface/ESProducer.h"

#include <iostream>
#include <memory>
#include <string>

using namespace edm;

OnlineBeamSpotESProducer::OnlineBeamSpotESProducer(const edm::ParameterSet& p){
label_HLT_        = p.getParameter<std::string>("Label_HLT");
label_HTEnriched_ = p.getParameter<std::string>("Label_HTEnriched");
label_Legacy_     = p.getParameter<std::string>("Label_Legacy");
setWhatProduced(this, label_HLT_);
}

OnlineBeamSpotESProducer::~OnlineBeamSpotESProducer() {}

std::unique_ptr<BeamSpotObjects> OnlineBeamSpotESProducer::produce(const BeamSpotObjectsRcd& iRecord) {

  ESHandle<BeamSpotObjects> pl_HTEnriched_;
  ESHandle<BeamSpotObjects> pl_Legacy_;
   
  iRecord.getRecord<BeamSpotObjectsRcd>().get(label_HTEnriched_, pl_HTEnriched_);
  iRecord.getRecord<BeamSpotObjectsRcd>().get(label_Legacy_, pl_Legacy_);

 const BeamSpotObjects* spot_HTEnriched_ = pl_HTEnriched_.product();  
 const BeamSpotObjects* spot_Legacy_ = pl_Legacy_.product();  
 const BeamSpotObjects*  spotDB_ = new BeamSpotObjects();
 //put it down the logic you want
 spotDB_ = pl_HTEnriched_

  //    BtagWorkingPoint wp;
    //how to write it out with a label?
  return std::make_unique<BeamSpotObjects>(*spotDB_,label_HLT_);
}

DEFINE_FWK_EVENTSETUP_MODULE(OnlineBeamSpotESProducer);