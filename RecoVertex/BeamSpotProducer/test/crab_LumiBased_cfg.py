from CRABClient.UserUtilities import config

config = config()

config.General.transferOutputs = True
config.General.requestName     = 'Run2015A_6Oct15_74X_dataRun2_Candidate_2015_10_06_09_25_21'
config.General.workArea        = 'bs_crab'

config.JobType.psetName        = 'BeamFit_LumiBased_NewAlignWorkflow.py'
config.JobType.pluginName      = 'Analysis'
config.JobType.outputFiles     = ['BeamFit_LumiBased_NewAlignWorkflow_alcareco.txt']

config.Data.inputDataset       = '/ZeroBias/Run2015A-PromptReco-v1/RECO'
config.Data.unitsPerJob        = 10
config.Data.splitting          = 'LumiBased'
config.Data.lumiMask           = 'total_DCS_json_upTo256869.txt'
# config.Data.runRange           = '246908-247644'
config.Data.publication        = False
config.Data.outLFNDirBase      = '/store/group/phys_tracking/beamspot/'

config.Site.storageSite        = 'T2_CH_CERN'
