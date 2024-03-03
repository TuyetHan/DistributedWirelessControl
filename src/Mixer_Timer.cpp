/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Mixer_Timer
 *** Description: Composite FB wrapping other FBs
 *** Version:
***     1.0: 2024-02-16/ADMIN -  - 
 *************************************************************************/

#include "Mixer_Timer.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Mixer_Timer_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Mixer_Timer, g_nStringIdMixer_Timer)

const CStringDictionary::TStringId FORTE_Mixer_Timer::scm_anDataInputNames[] = {g_nStringIdROUND_CYC, g_nStringIdTX_DELAY_TRG, g_nStringIdRD_TRG_CYC};

const CStringDictionary::TStringId FORTE_Mixer_Timer::scm_anDataInputTypeIds[] = {g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME};


const TDataIOID FORTE_Mixer_Timer::scm_anEIWith[] = {0, 1, 2, 255};
const TForteInt16 FORTE_Mixer_Timer::scm_anEIWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_Mixer_Timer::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdESD};

const TForteInt16 FORTE_Mixer_Timer::scm_anEOWithIndexes[] = {-1, -1, -1};
const CStringDictionary::TStringId FORTE_Mixer_Timer::scm_anEventOutputNames[] = {g_nStringIdROUND_START, g_nStringIdTRANSMIT_TRG, g_nStringIdSEND_RD};


const SFBInterfaceSpec FORTE_Mixer_Timer::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  3, scm_anEventOutputNames, nullptr, scm_anEOWithIndexes,
  3, scm_anDataInputNames, scm_anDataInputTypeIds,
  0, nullptr, nullptr,
  0, nullptr
};

const SCFB_FBInstanceData FORTE_Mixer_Timer::scm_astInternalFBs[] = {
  {g_nStringIdROUND_CYC, g_nStringIdE_CYCLE},
  {g_nStringIdTx_DELAY, g_nStringIdE_DELAY},
  {g_nStringIdE_MERGE, g_nStringIdE_MERGE},
  {g_nStringIdTx_Cyc, g_nStringIdE_DELAY},
  {g_nStringIdRx_TRG_CYC, g_nStringIdE_CYCLE}
};

const SCFB_FBParameter FORTE_Mixer_Timer::scm_astParamters[] = {
  {3, g_nStringIdDT, "T#5ms"},
};

const SCFB_FBConnectionData FORTE_Mixer_Timer::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTx_DELAY, g_nStringIdEO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEI1), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdROUND_CYC, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTx_DELAY, g_nStringIdSTART), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTx_Cyc, g_nStringIdEO), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEI2), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdROUND_CYC, g_nStringIdSTART), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_MERGE, g_nStringIdEO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTRANSMIT_TRG), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdRx_TRG_CYC, g_nStringIdEO), 4, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSEND_RD), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdESD), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTx_Cyc, g_nStringIdSTART), 3},
};

const SCFB_FBFannedOutConnectionData FORTE_Mixer_Timer::scm_astFannedOutEventConnections[] = {
  {1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdROUND_START), -1},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdRx_TRG_CYC, g_nStringIdSTART), 4},
};

const SCFB_FBConnectionData FORTE_Mixer_Timer::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdROUND_CYC), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdROUND_CYC, g_nStringIdDT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTX_DELAY_TRG), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTx_DELAY, g_nStringIdDT), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRD_TRG_CYC), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdRx_TRG_CYC, g_nStringIdDT), 4},
};

const SCFB_FBNData FORTE_Mixer_Timer::scm_stFBNData = {
  5, scm_astInternalFBs,
  7, scm_astEventConnections,
  2, scm_astFannedOutEventConnections,
  3, scm_astDataConnections,
  0, nullptr,
  1, scm_astParamters
};



