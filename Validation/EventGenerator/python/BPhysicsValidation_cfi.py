import FWCore.ParameterSet.Config as cms

from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer
JPsiMuMuValidation = DQMEDAnalyzer('BPhysicsValidation',
                                    genparticleCollection = cms.InputTag("genParticles",""),
                                    name = cms.string("JPsiMuMuValidation"),
                                    pname = cms.string("J/#Psi"),
                                    pdgid = cms.int32(443),
                                    massmin = cms.double(3.0),
                                    massmax = cms.double(4.0),
                                    daughters = cms.vstring("muminus","muplus"),
                                    muminus = cms.untracked.PSet(pname = cms.string("#mu^{-}"),
                                                                 pdgid = cms.int32(13),
                                                                 massmin = cms.double(0.1),
                                                                 massmax = cms.double(0.2),

                                                                 ),
                                    muplus = cms.untracked.PSet(pname = cms.string("#mu^{+}"),
                                                                pdgid = cms.int32(-13),
                                                                 massmin = cms.double(0.1),
                                                                 massmax = cms.double(0.2),
                                                                )
                                    )

from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer
LambdabPiPiMuMuValidation = DQMEDAnalyzer('BPhysicsValidation',
                                           genparticleCollection = cms.InputTag("genParticles",""),
                                           name = cms.string("LambdabPiPiMuMuValidation"),
                                           pname = cms.string("#Lambda_{b}"),
                                           pdgid = cms.int32(5122),
                                           massmin = cms.double(5.5),
                                           massmax = cms.double(6.0),
                                           daughters = cms.vstring("muminus","muplus","piminus","piplus","pminus","pplus","Lambda","Lambdabar"),
                                           muminus = cms.untracked.PSet(pname = cms.string("#mu^{-}"),
                                                                        pdgid = cms.int32(13),
                                                                        massmin = cms.double(0.1),
                                                                        massmax = cms.double(0.2),
                                                                        ),
                                           muplus = cms.untracked.PSet(pname = cms.string("#mu^{+}"),
                                                                       pdgid = cms.int32(-13),
                                                                       massmin = cms.double(0.1),
                                                                       massmax = cms.double(0.2),
                                                                       ),
                                           piminus = cms.untracked.PSet(pname = cms.string("#pi^{-}"),
                                                                        pdgid = cms.int32(-211),
                                                                        massmin = cms.double(0.1),
                                                                        massmax = cms.double(0.2),
                                                                        ),
                                           piplus = cms.untracked.PSet(pname = cms.string("#pi^{+}"),
                                                                       pdgid = cms.int32(211),
                                                                       massmin = cms.double(0.1),
                                                                       massmax = cms.double(0.2),
                                                                       ),
                                           pminus = cms.untracked.PSet(pname = cms.string("p^{-}"),
                                                                       pdgid = cms.int32(-2212),
                                                                       massmin = cms.double(0.9),
                                                                       massmax = cms.double(1.1),
                                                                       ),
                                           pplus = cms.untracked.PSet(pname = cms.string("p^{+}"),
                                                                      pdgid = cms.int32(2212),
                                                                      massmin = cms.double(0.9),
                                                                      massmax = cms.double(1.1),
                                                                      ),
                                           Lambda = cms.untracked.PSet(pname = cms.string("#Lambda"),
                                                                       pdgid = cms.int32(3122),
                                                                       massmin = cms.double(1.0),
                                                                       massmax = cms.double(1.2),
                                                                       ),
                                           Lambdabar = cms.untracked.PSet(pname = cms.string("#bar{#Lambda}"),
                                                                          pdgid = cms.int32(-3122),
                                                                          massmin = cms.double(1.0),
                                                                          massmax = cms.double(1.2),
                                                                          )
                                           )



from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer
PsiSpectrum = DQMEDAnalyzer('BPhysicsSpectrum',
                             genparticleCollection = cms.InputTag("genParticles",""),
                             name = cms.string("JPsiSpectrum"),
                             pdgids = cms.vint32(443,100443,30443,9000443,9010443,9020443),
                             massmin = cms.double(3.0),
                             massmax = cms.double(4.5)
                             )

from DQMServices.Core.DQMEDAnalyzer import DQMEDAnalyzer
LambdaSpectrum = DQMEDAnalyzer('BPhysicsSpectrum',
                             genparticleCollection = cms.InputTag("genParticles",""),
                             name = cms.string("LambdaSpectrum"),
                             pdgids = cms.vint32(5122),
                             massmin = cms.double(5.5),
                             massmax = cms.double(6.0)
                             )
