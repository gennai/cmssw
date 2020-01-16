#ifndef RecoVertex_BeamSpotProducer_OnlineBeamSpotESProducer_H
#define RecoVertex_BeamSpotProducer_OnlineBeamSpotESProducer_H

#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "CondFormats/DataRecord/interface/BeamSpotObjectsRcd.h"
#include "CondFormats/BeamSpotObjects/interface/BeamSpotObjects.h"

#include "FWCore/Framework/interface/ESProducer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <memory>

class OnlineBeamSpotESProducer : public edm::ESProducer {
public:
  OnlineBeamSpotESProducer(const edm::ParameterSet &p);
  ~OnlineBeamSpotESProducer() override;
  std::unique_ptr<BeamSpotObjects> produce(const BeamSpotObjectsRcd &);

private:
  edm::ParameterSet pset_;
  std::string label_;

};

#endif