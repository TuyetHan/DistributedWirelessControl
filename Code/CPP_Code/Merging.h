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

#ifndef _MERGING_H_
#define _MERGING_H_

#include "basicfb.h"
#include "forte_any.h"
// #error type contains variables of type ANY. Please check the usage of these variables as we can not gurantee correct usage on export!
#include "forte_bool.h"
#include "forte_uint.h"
#include "forte_wstring.h"
#include "forte_array_at.h"


class FORTE_Merging: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_Merging)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQ1ID = 1;
  static const TEventID scm_nEventREQ2ID = 2;
  static const TEventID scm_nEventREQ3ID = 3;
  static const TEventID scm_nEventREQ4ID = 4;
  static const TEventID scm_nEventREQ5ID = 5;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_UINT &st_PORT_ID1() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  }
  
  CIEC_ANY &st_SD1() {
    return *static_cast<CIEC_ANY*>(getDI(1));
  }
  
  CIEC_UINT &st_PORT_ID2() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  }
  
  CIEC_ANY &st_SD2() {
    return *static_cast<CIEC_ANY*>(getDI(3));
  }
  
  CIEC_UINT &st_PORT_ID3() {
    return *static_cast<CIEC_UINT*>(getDI(4));
  }
  
  CIEC_ANY &st_SD3() {
    return *static_cast<CIEC_ANY*>(getDI(5));
  }
  
  CIEC_UINT &st_PORT_ID4() {
    return *static_cast<CIEC_UINT*>(getDI(6));
  }
  
  CIEC_ANY &st_SD4() {
    return *static_cast<CIEC_ANY*>(getDI(7));
  }
  
  CIEC_UINT &st_PORT_ID5() {
    return *static_cast<CIEC_UINT*>(getDI(8));
  }
  
  CIEC_ANY &st_SD5() {
    return *static_cast<CIEC_ANY*>(getDI(9));
  }
  
  CIEC_BOOL &st_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_WSTRING &st_STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(1));
  }
  
  CIEC_UINT &st_PORT_IDO() {
    return *static_cast<CIEC_UINT*>(getDO(2));
  }
  
  CIEC_ANY &st_SDO() {
    return *static_cast<CIEC_ANY*>(getDO(3));
  }
  

  void alg_initialize(void);
  void alg_deInitialize(void);
  void alg_Input1_out(void);
  void alg_Input3_out(void);
  void alg_Input2_out(void);
  void alg_Input4_out(void);
  void alg_Input5_out(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateINPUT1 = 2;
  static const TForteInt16 scm_nStateInitialized = 3;
  static const TForteInt16 scm_nStateINPUT2 = 4;
  static const TForteInt16 scm_nStateINPUT3 = 5;
  static const TForteInt16 scm_nStateINPUT4 = 6;
  static const TForteInt16 scm_nStateINPUT5 = 7;
  
  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateINPUT1(void);
  void enterStateInitialized(void);
  void enterStateINPUT2(void);
  void enterStateINPUT3(void);
  void enterStateINPUT4(void);
  void enterStateINPUT5(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(2, 10, 4, 0, 0);

public:
  FORTE_Merging(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Merging() = default;
};

#endif // _MERGING_H_


