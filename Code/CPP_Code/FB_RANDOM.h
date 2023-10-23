/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FB_RANDOM
 *** Description: Adds two REAL values
 *** Version:
***     1.0: 2012-05-31/Gerhard Ebenhofer - Profactor GmbH - 
 *************************************************************************/

#ifndef _FB_RANDOM_H_
#define _FB_RANDOM_H_

#include "basicfb.h"
#include "forte_real.h"
#include "forte_uint.h"
#include "forte_array_at.h"


class FORTE_FB_RANDOM: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_FB_RANDOM)

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

virtual void setInitialValues();
  CIEC_UINT &st_SEED() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  }
  
  CIEC_REAL &st_VAL() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  }
  

  void alg_INIT(void);
  void alg_REQ(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateState = 2;
  
  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateState(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(2, 1, 1, 0, 0);

public:
  FORTE_FB_RANDOM(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_FB_RANDOM() = default;
};

#endif // _FB_RANDOM_H_


