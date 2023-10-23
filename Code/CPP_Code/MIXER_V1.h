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

#ifndef _MIXER_V1_H_
#define _MIXER_V1_H_

#include "cfb.h"
#include "typelib.h"
#include "forte_bool.h"
#include "forte_uint.h"
#include "forte_wstring.h"
#include "forte_array_at.h"


class FORTE_MIXER_V1: public CCompositeFB {
  DECLARE_FIRMWARE_FB(FORTE_MIXER_V1)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  
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

  CIEC_BOOL &st_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  
  CIEC_UINT &st_NodeID() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  }
  
  CIEC_UINT &st_TotalNode() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  }
  
  CIEC_WSTRING &st_TrsRcvID() {
    return *static_cast<CIEC_WSTRING*>(getDI(3));
  }
  
  CIEC_BOOL &st_SD() {
    return *static_cast<CIEC_BOOL*>(getDI(4));
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
  
  CIEC_BOOL &st_RD() {
    return *static_cast<CIEC_BOOL*>(getDO(4));
  }
  

  FORTE_FB_DATA_ARRAY(2, 5, 5, 0);

public:
  FORTE_MIXER_V1(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CCompositeFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, &scm_stFBNData, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_MIXER_V1() = default;
};

#endif // _MIXER_V1_H_


