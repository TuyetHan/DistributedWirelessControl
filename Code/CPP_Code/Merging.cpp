/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Merging
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2023-10-14/ADMIN -  - 
 *************************************************************************/

#include "Merging.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Merging_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Merging, g_nStringIdMerging)

const CStringDictionary::TStringId FORTE_Merging::scm_anDataInputNames[] = {g_nStringIdPORT_ID1, g_nStringIdSD1, g_nStringIdPORT_ID2, g_nStringIdSD2, g_nStringIdPORT_ID3, g_nStringIdSD3, g_nStringIdPORT_ID4, g_nStringIdSD4, g_nStringIdPORT_ID5, g_nStringIdSD5};

const CStringDictionary::TStringId FORTE_Merging::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdANY, g_nStringIdUINT, g_nStringIdANY, g_nStringIdUINT, g_nStringIdANY, g_nStringIdUINT, g_nStringIdANY, g_nStringIdUINT, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_Merging::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdPORT_IDO, g_nStringIdSDO};

const CStringDictionary::TStringId FORTE_Merging::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdUINT, g_nStringIdANY};

const TDataIOID FORTE_Merging::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255, 0, 1, 255, 2, 3, 255, 4, 5, 255, 6, 7, 255, 8, 9, 255};
const TForteInt16 FORTE_Merging::scm_anEIWithIndexes[] = {0, 11, 14, 17, 20, 23};
const CStringDictionary::TStringId FORTE_Merging::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ1, g_nStringIdREQ2, g_nStringIdREQ3, g_nStringIdREQ4, g_nStringIdREQ5};

const TDataIOID FORTE_Merging::scm_anEOWith[] = {0, 1, 2, 3, 255, 2, 3, 255};
const TForteInt16 FORTE_Merging::scm_anEOWithIndexes[] = {0, 5};
const CStringDictionary::TStringId FORTE_Merging::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_Merging::scm_stFBInterfaceSpec = {
  6, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  10, scm_anDataInputNames, scm_anDataInputTypeIds,
  4, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_Merging::setInitialValues() {
}

void FORTE_Merging::alg_initialize(void) {
}

void FORTE_Merging::alg_deInitialize(void) {
  st_QO() = false;
}

void FORTE_Merging::alg_Input1_out(void) {
  st_QO() = 1;
  st_STATUS() = "NORMAL";
  st_PORT_IDO() = st_PORT_ID1();
  st_SDO().saveAssign(st_SD1());

  // st_SDO().setValue(st_SD1());
  // st_SDO() = st_SD1();
}

void FORTE_Merging::alg_Input3_out(void) {
  st_QO() = 1;
  st_STATUS() = "NORMAL";
  st_PORT_IDO() = st_PORT_ID3();
  st_SDO().saveAssign(st_SD3());
  // st_SDO() = st_SD3();
}

void FORTE_Merging::alg_Input2_out(void) {
  st_QO() = 1;
  st_STATUS() = "NORMAL";
  st_PORT_IDO() = st_PORT_ID2();
  st_SDO().saveAssign(st_SD2());
  // st_SDO() = st_SD2();
}

void FORTE_Merging::alg_Input4_out(void) {
  st_QO() = 1;
  st_STATUS() = "NORMAL";
  st_PORT_IDO() = st_PORT_ID4();
  st_SDO().saveAssign(st_SD4());
  // st_SDO() = st_SD4();
}

void FORTE_Merging::alg_Input5_out(void) {
  st_QO() = 1;
  st_STATUS() = "NORMAL";
  st_PORT_IDO() = st_PORT_ID5();
  st_SDO().saveAssign(st_SD5());
  // st_SDO() = st_SD5();
}


void FORTE_Merging::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Merging::enterStateInit(void) {
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent(scm_nEventINITOID);
}

void FORTE_Merging::enterStateINPUT1(void) {
  m_nECCState = scm_nStateINPUT1;
  alg_Input1_out();
  sendOutputEvent(scm_nEventCNFID);
}

void FORTE_Merging::enterStateInitialized(void) {
  m_nECCState = scm_nStateInitialized;
}

void FORTE_Merging::enterStateINPUT2(void) {
  m_nECCState = scm_nStateINPUT2;
  alg_Input2_out();
  sendOutputEvent(scm_nEventCNFID);
}

void FORTE_Merging::enterStateINPUT3(void) {
  m_nECCState = scm_nStateINPUT3;
  alg_Input3_out();
  sendOutputEvent(scm_nEventCNFID);
}

void FORTE_Merging::enterStateINPUT4(void) {
  m_nECCState = scm_nStateINPUT4;
  alg_Input4_out();
  sendOutputEvent(scm_nEventCNFID);
}

void FORTE_Merging::enterStateINPUT5(void) {
  m_nECCState = scm_nStateINPUT5;
  alg_Input5_out();
  sendOutputEvent(scm_nEventCNFID);
}


void FORTE_Merging::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINPUT1:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if(scm_nEventREQ1ID == pa_nEIID)
          enterStateINPUT1();
        else
        if(scm_nEventREQ2ID == pa_nEIID)
          enterStateINPUT2();
        else
        if(scm_nEventREQ3ID == pa_nEIID)
          enterStateINPUT3();
        else
        if(scm_nEventREQ4ID == pa_nEIID)
          enterStateINPUT4();
        else
        if(scm_nEventREQ5ID == pa_nEIID)
          enterStateINPUT5();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINPUT2:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINPUT3:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINPUT4:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINPUT5:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 8.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


