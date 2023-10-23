/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: MIXER_V1
 *** Description: Mixer Communication Block V1
 *** Version:
***     1.0: 2023-08-25/ADMIN -  - 
 *************************************************************************/

#include "MIXER_V1.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MIXER_V1_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_MIXER_V1, g_nStringIdMIXER_V1)

const CStringDictionary::TStringId FORTE_MIXER_V1::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdNodeID, g_nStringIdTotalNode, g_nStringIdTrsRcvID, g_nStringIdSD};

const CStringDictionary::TStringId FORTE_MIXER_V1::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdWSTRING, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_MIXER_V1::scm_anDataOutputNames[] = {g_nStringIdQO_RX, g_nStringIdQO_TX, g_nStringIdRX_STATUS, g_nStringIdTX_STATUS, g_nStringIdRD};

const CStringDictionary::TStringId FORTE_MIXER_V1::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdBOOL};

const TDataIOID FORTE_MIXER_V1::scm_anEIWith[] = {0, 1, 2, 3, 255, 0, 4, 255};
const TForteInt16 FORTE_MIXER_V1::scm_anEIWithIndexes[] = {0, 5};
const CStringDictionary::TStringId FORTE_MIXER_V1::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_MIXER_V1::scm_anEOWith[] = {0, 2, 255, 0, 2, 4, 255};
const TForteInt16 FORTE_MIXER_V1::scm_anEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_MIXER_V1::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_MIXER_V1::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  5, scm_anDataInputNames, scm_anDataInputTypeIds,
  5, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

const SCFB_FBInstanceData FORTE_MIXER_V1::scm_astInternalFBs[] = {
  {g_nStringIdE_CYCLE, g_nStringIdE_CYCLE},
  {g_nStringIdE_DELAY, g_nStringIdE_DELAY},
  {g_nStringIdPUBLISH_1, g_nStringIdPUBLISH_1},
  {g_nStringIdSUBSCRIBE_1, g_nStringIdSUBSCRIBE_1},
  {g_nStringIdE_MERGE, g_nStringIdE_MERGE},
  {g_nStringIdDataProcessing, g_nStringIdDataProcessing}
};

const SCFB_FBParameter FORTE_MIXER_V1::scm_astParamters[] = {
  {0, g_nStringIdDT, "T#1s"},
  {1, g_nStringIdDT, "T#0.8s"},
  {2, g_nStringIdQI, "1"},
  {3, g_nStringIdQI, "1"},
};

const SCFB_FBConnectionData FORTE_MIXER_V1::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CYCLE, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdINITO), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdINIT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdIND), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEI2), 4},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEI1), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdINITO), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdINIT), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdESD), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdERD), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdINIT), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEO), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdREQ), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdEO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdTRANSMIT_TRG), 5},
};

const SCFB_FBFannedOutConnectionData FORTE_MIXER_V1::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdROUND_START), 5},
};

const SCFB_FBConnectionData FORTE_MIXER_V1::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdSTATUS), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRX_STATUS), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdSTATUS), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTX_STATUS), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdSD_OUT), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdSD_1), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdRD_OUT), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdQI), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSD), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdSD_IN), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdRD_1), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdRD_IN), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdNodeID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdNodeID), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTotalNode), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDataProcessing, g_nStringIdTotalNode), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdQO), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO_RX), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdQO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO_TX), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTrsRcvID), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSUBSCRIBE_1, g_nStringIdID), 3},
};

const SCFB_FBFannedOutConnectionData FORTE_MIXER_V1::scm_astFannedOutDataConnections[] = {
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPUBLISH_1, g_nStringIdID), 2},
};

const SCFB_FBNData FORTE_MIXER_V1::scm_stFBNData = {
  6, scm_astInternalFBs,
  11, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  12, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  4, scm_astParamters
};



