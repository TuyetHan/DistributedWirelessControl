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

#ifndef _MIXER_TIMER_H_
#define _MIXER_TIMER_H_

#include "cfb.h"
#include "typelib.h"
#include "forte_time.h"
#include "forte_array_at.h"


class FORTE_Mixer_Timer: public CCompositeFB {
  DECLARE_FIRMWARE_FB(FORTE_Mixer_Timer)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventESDID = 1;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventROUND_STARTID = 0;
  static const TEventID scm_nEventTRANSMIT_TRGID = 1;
  static const TEventID scm_nEventSEND_RDID = 2;
  
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
  

  FORTE_FB_DATA_ARRAY(3, 3, 0, 0);

public:
  FORTE_Mixer_Timer(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CCompositeFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, &scm_stFBNData, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Mixer_Timer() = default;
};

#endif // _MIXER_TIMER_H_


