/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: MIXER
 *** Description: Mixer Communication Block V1
 *** Version:
***     1.0: 2023-08-25/ADMIN -  - 
 *************************************************************************/

#include "MIXER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MIXER_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_MIXER, g_nStringIdMIXER)

const CStringDictionary::TStringId FORTE_MIXER::scm_anDataInputNames[] = {g_nStringIdROUND_CYC, g_nStringIdTX_DELAY_TRG, g_nStringIdRD_TRG_CYC, g_nStringIdQI, g_nStringIdNodeID, g_nStringIdTotalNode, g_nStringIdRD_Port_ID, g_nStringIdSD_Port_ID, g_nStringIdSD_1, g_nStringIdSD_2, g_nStringIdSD_3, g_nStringIdSD_4, g_nStringIdSD_5, g_nStringIdTrsRcvID};

const CStringDictionary::TStringId FORTE_MIXER::scm_anDataInputTypeIds[] = {g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdWSTRING};

const CStringDictionary::TStringId FORTE_MIXER::scm_anDataOutputNames[] = {g_nStringIdQO_RX, g_nStringIdQO_TX, g_nStringIdRX_STATUS, g_nStringIdTX_STATUS, g_nStringIdRD_1, g_nStringIdRD_2, g_nStringIdRD_3, g_nStringIdRD_4, g_nStringIdRD_5};

const CStringDictionary::TStringId FORTE_MIXER::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY};

const TDataIOID FORTE_MIXER::scm_anEIWith[] = {3, 4, 5, 13, 0, 1, 2, 6, 7, 255, 8, 255, 9, 255, 10, 255, 11, 255, 12, 255};
const TForteInt16 FORTE_MIXER::scm_anEIWithIndexes[] = {0, 10, 12, 14, 16, 18};
const CStringDictionary::TStringId FORTE_MIXER::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdR_SD1, g_nStringIdR_SD2, g_nStringIdR_SD3, g_nStringIdR_SD4, g_nStringIdR_SD5};

const TDataIOID FORTE_MIXER::scm_anEOWith[] = {0, 2, 4, 5, 6, 7, 8, 3, 1, 255};
const TForteInt16 FORTE_MIXER::scm_anEOWithIndexes[] = {-1, 0};
const CStringDictionary::TStringId FORTE_MIXER::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_MIXER::scm_stFBInterfaceSpec = {
  6, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  14, scm_anDataInputNames, scm_anDataInputTypeIds,
  9, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

const SCFB_FBInstanceData FORTE_MIXER::scm_astInternalFBs[] = {
  {g_nStringIdROUND_CYCLE, g_nStringIdE_CYCLE},
  {g_nStringIdTX_TRIGGER, g_nStringIdE_DELAY},
  {g_nStringIdPUBLISH_1, g_nStringIdPUBLISH_1},
  {g_nStringIdSUBSCRIBE_1, g_nStringIdSUBSCRIBE_1},
  {g_nStringIdE_MERGE, g_nStringIdE_MERGE},
  {g_nStringIdDataProcessing_1, g_nStringIdMixer_Main},
  {g_nStringIdE_DELAY_1, g_nStringIdE_DELAY},
  {g_nStringIdRD_SEND_CYCLE, g_nStringIdE_CYCLE}
};

const SCFB_FBParameter FORTE_MIXER::scm_astParamters[] = {
  {2, g_nStringIdQI, "1"},
  {3, g_nStringIdQI, "1"},
  {6, g_nStringIdDT, "T#5ms"},
};

const SCFB_FBConnectionData FORTE_MIXER::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdROUND_CYCLE, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTX_TRIGGER, g_nStringIdSTART), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdINIT), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdESD), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTX_TRIGGER, g_nStringIdEO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEI1), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEO), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdTRANSMIT_TRG), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdEO), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEI1), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdR_SD1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdREQ1), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdR_SD2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdREQ2), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdR_SD3), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdREQ3), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdR_SD4), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdREQ4), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdR_SD5), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdREQ5), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdIND), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdREQ_RD), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdINITO), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdRD_SEND_CYCLE, g_nStringIdEO), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSEND_RD), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdERD), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_MIXER::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdROUND_START), 5},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdROUND_CYCLE, g_nStringIdSTART), 0},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdRD_SEND_CYCLE, g_nStringIdSTART), 7},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdINIT), 3},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdINIT), 2},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY_1, g_nStringIdSTART), 6},
};

const SCFB_FBConnectionData FORTE_MIXER::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdSTATUS), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRX_STATUS), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdSTATUS), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTX_STATUS), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdQO), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO_RX), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdQO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO_TX), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTrsRcvID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdID), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSD_OUT), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdSD_1), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdQI), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdNodeID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdNodeID), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTotalNode), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdTotalNode), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdRD_1), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdRD_IN), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_Port_ID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdRD_OUT_ID), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD_Port_ID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSD_IN_ID), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD_1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSD_IN_1), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD_2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSD_IN_2), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD_3), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSD_IN_3), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD_4), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSD_IN_4), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD_5), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdSD_IN_5), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_TRG_CYC), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdRD_SEND_CYCLE, g_nStringIdDT), 7},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdROUND_CYC), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdROUND_CYCLE, g_nStringIdDT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTX_DELAY_TRG), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTX_TRIGGER, g_nStringIdDT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdRD_OUT_5), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_5), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdRD_OUT_4), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_4), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdRD_OUT_3), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_3), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdRD_OUT_2), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_2), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing_1, g_nStringIdRD_OUT_1), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_1), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_MIXER::scm_astFannedOutDataConnections[] = {
  {4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdID), 2},
};

const SCFB_FBNData FORTE_MIXER::scm_stFBNData = {
  8, scm_astInternalFBs,
  15, scm_astEventConnections,
  6, scm_astFannedOutEventConnections,
  25, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  3, scm_astParamters
};



