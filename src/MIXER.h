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

#ifndef _MIXER_H_
#define _MIXER_H_

#include "cfb.h"
#include "typelib.h"
#include "forte_any.h"
// #error type contains variables of type ANY. Please check the usage of these variables as we can not gurantee correct usage on export!
#include "forte_bool.h"
#include "forte_time.h"
#include "forte_uint.h"
#include "forte_wstring.h"
#include "forte_array_at.h"


class FORTE_MIXER: public CCompositeFB {
  DECLARE_FIRMWARE_FB(FORTE_MIXER)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventR_SD1ID = 1;
  static const TEventID scm_nEventR_SD2ID = 2;
  static const TEventID scm_nEventR_SD3ID = 3;
  static const TEventID scm_nEventR_SD4ID = 4;
  static const TEventID scm_nEventR_SD5ID = 5;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  static const SCFB_FBInstanceData scm_astInternalFBs[];
  static const SCFB_FBParameter scm_astParamters[];
  static const SCFB_FBConnectionData scm_astEventConnections[];
  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];
  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

  CIEC_TIME &st_ROUND_CYC() {
    return *static_cast<CIEC_TIME*>(getDI(0));
  }
  
  CIEC_TIME &st_TX_DELAY_TRG() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  }
  
  CIEC_TIME &st_RD_TRG_CYC() {
    return *static_cast<CIEC_TIME*>(getDI(2));
  }
  
  CIEC_BOOL &st_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(3));
  }
  
  CIEC_UINT &st_NodeID() {
    return *static_cast<CIEC_UINT*>(getDI(4));
  }
  
  CIEC_UINT &st_TotalNode() {
    return *static_cast<CIEC_UINT*>(getDI(5));
  }
  
  CIEC_WSTRING &st_RD_Port_ID() {
    return *static_cast<CIEC_WSTRING*>(getDI(6));
  }
  
  CIEC_WSTRING &st_SD_Port_ID() {
    return *static_cast<CIEC_WSTRING*>(getDI(7));
  }
  
  CIEC_ANY &st_SD_1() {
    return *static_cast<CIEC_ANY*>(getDI(8));
  }
  
  CIEC_ANY &st_SD_2() {
    return *static_cast<CIEC_ANY*>(getDI(9));
  }
  
  CIEC_ANY &st_SD_3() {
    return *static_cast<CIEC_ANY*>(getDI(10));
  }
  
  CIEC_ANY &st_SD_4() {
    return *static_cast<CIEC_ANY*>(getDI(11));
  }
  
  CIEC_ANY &st_SD_5() {
    return *static_cast<CIEC_ANY*>(getDI(12));
  }
  
  CIEC_WSTRING &st_TrsRcvID() {
    return *static_cast<CIEC_WSTRING*>(getDI(13));
  }
  
  CIEC_BOOL &st_QO_RX() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_BOOL &st_QO_TX() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  }
  
  CIEC_WSTRING &st_RX_STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(2));
  }
  
  CIEC_WSTRING &st_TX_STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(3));
  }
  
  CIEC_ANY &st_RD_1() {
    return *static_cast<CIEC_ANY*>(getDO(4));
  }
  
  CIEC_ANY &st_RD_2() {
    return *static_cast<CIEC_ANY*>(getDO(5));
  }
  
  CIEC_ANY &st_RD_3() {
    return *static_cast<CIEC_ANY*>(getDO(6));
  }
  
  CIEC_ANY &st_RD_4() {
    return *static_cast<CIEC_ANY*>(getDO(7));
  }
  
  CIEC_ANY &st_RD_5() {
    return *static_cast<CIEC_ANY*>(getDO(8));
  }
  

  FORTE_FB_DATA_ARRAY(2, 14, 9, 0);

public:
  FORTE_MIXER(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CCompositeFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, &scm_stFBNData, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_MIXER() = default;
};

#endif // _MIXER_H_


