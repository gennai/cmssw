/** \class L1TkEleFilter
 *
 * See header file for documentation
 *
 *
 *  \author Martin Grunewald
 *
 */

#include "L1TkEleFilter.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"

#include "DataFormats/Common/interface/Handle.h"

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/HLTReco/interface/TriggerFilterObjectWithRefs.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

//
// constructors and destructor
//

L1TkEleFilter::L1TkEleFilter(const edm::ParameterSet& iConfig)
    : HLTFilter(iConfig),
      l1TkEleTag_(iConfig.getParameter<edm::InputTag>("inputTag")),
      tkEleToken_(consumes<TkEleCollection>(l1TkEleTag_)){
        min_Pt_= iConfig.getParameter<double>("MinPt");
        min_N_ = iConfig.getParameter<int>("MinN");
        min_Eta_=iConfig.getParameter<double>("MinEta");
        max_Eta_=iConfig.getParameter<double>("MaxEta");
        
        } 

L1TkEleFilter::~L1TkEleFilter() = default;

//
// member functions
//

void L1TkEleFilter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  makeHLTFilterDescription(desc);
  desc.add<double>("MinPt", -1.0);
  desc.add<double>("MinEta", -5.0);
  desc.add<double>("MaxEta", 5.0);
  desc.add<int>("MinN",1);
  desc.add<edm::InputTag>("inputTag",edm::InputTag("L1TkElectrons"));
  descriptions.add("L1TkEleFilter", desc);
}

// ------------ method called to produce the data  ------------
bool L1TkEleFilter::hltFilter(edm::Event& iEvent,
                            const edm::EventSetup& iSetup,
                            trigger::TriggerFilterObjectWithRefs& filterproduct) const {
  using namespace std;
  using namespace edm;
  using namespace reco;
  using namespace trigger;

  // All HLT filters must create and fill an HLT filter object,
  // recording any reconstructed physics objects satisfying (or not)
  // this HLT filter, and place it in the Event.

  // The filter object
  if (saveTags()) {
    filterproduct.addCollectionTag(l1TkEleTag_);
  }

  // Specific filter code

  // get hold of products from Event

  Handle<l1t::TkElectronCollection> tkEles;

  iEvent.getByToken(tkEleToken_,tkEles);


// trkEle
  int ntrkEle(0);
  auto atrkEles(tkEles->begin());
  auto otrkEles(tkEles->end());
  TkEleCollection::const_iterator itkEle;
  for (itkEle = atrkEles; itkEle != otrkEles; itkEle++) {
    if (itkEle->pt() >= min_Pt_ && itkEle->eta() <= max_Eta_ && itkEle->eta() >= min_Eta_) {
      ntrkEle++;
      l1t::TkElectronRef ref(l1t::TkElectronRef(tkEles, distance(atrkEles, itkEle)));
      filterproduct.addObject(-78, ref);
    }
  }


  // error case
  // filterproduct.addObject(0,Ref<vector<int> >());

  // final filter decision:
  const bool accept(ntrkEle >= min_N_);


  // return with final filter decision
  return accept;
}
