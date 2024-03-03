/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Mixer_Main
 *** Description: Service Interface Function Block Type
 *** Version:
***     1.0: 2023-08-25/ADMIN -  - 
 *************************************************************************/

#ifndef _MIXER_MAIN_H_
#define _MIXER_MAIN_H_

#include "funcbloc.h"
#include "forte_any.h"
// #error type contains variables of type ANY. Please check the usage of these variables as we can not gurantee correct usage on export!
#include "forte_bool.h"
#include "forte_udint.h"
#include "forte_uint.h"
#include "forte_wstring.h"
#include "forte_array_at.h"

#include "../../core/utils/parameterParser.h"

/*****************************************************************************/
//Data Related Constant
#define MIXER_TOTAL_SLOTS           4   
// #define NUM_RD_PORT                 5
#define VALUE_BUFFER_SIZE           4

//General Mixer Parameters - If change perform in here need to review again Buffer Structure
#define MAXIMUM_NUMBER_NODES                255     // Maximum number of nodes in the network. Node ID is 8 bits
#define MAXIMUM_TRANSMIT_PORT_PERNODE       16      // Maximum number of port per node. Port ID is 8 bits
#define MAXIMUM_RECEIVE_PORT_PERNODE        16      // same as above
#define MAXIMUM_NUMBER_PORTS                256     
#define BUFFER_SIZE                         50  

    /****************Current Mixer Buffer Structure**************/ 
      // First buffer element: Info 1 -General Message Information
      /*|1 2         |3 4    |5 6           | 7 8    |*/
      /*|Round Number|Node ID|Message Length|Reserved|*/

      // Second buffer element: Info 2 - Sender ID
      /*|1 2        |3 4        |5 6        | 7 8       |*/
      /*|Sender ID 1|Sender ID 2|Sender ID 3|Sender ID 4|*/

      // Third buffer element: Info 3 - Number of port per sender
      /*|1  |2  |3  |4  |5 6 7 8 |*/
      /*|PN1|PN2|PN3|PN4|Reserved|*/
      
      // Other buffer element: Data
      /*|1 2    |3 4      | 5 6 7 8|*/
      /*|Port ID|Data Type| Data   |*/
      /*|            Data          |*/  //If requires more than 16 bits
      /**********************************************************/

#define NODE_HISTORY_SIZE               20 // Around double number of neighbors
#define MAXIMUM_INNOFORWARDING_SLOT     2

// Application Constant
#define NUM_INITIALIZE_PARAMETER    2
#define NODEID_POSITION             0
#define TOTAL_NODE_POSITION         1
// #define DENOMINATOR_N_TRANSMIT      6

#define MIXER_DEBUG_ON      1
#define MIXER_DEBUG_OFF     0
#define MIXER_DEBUG_MODE    MIXER_DEBUG_OFF

/*****************************************************************************/
class FORTE_Mixer_Main: public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_Mixer_Main)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventROUND_STARTID = 1;
  static const TEventID scm_nEventTRANSMIT_TRGID = 2;
  static const TEventID scm_nEventSEND_RDID = 3;
  static const TEventID scm_nEventREQ_RDID = 4;
  static const TEventID scm_nEventREQ1ID = 5;
  static const TEventID scm_nEventREQ2ID = 6;
  static const TEventID scm_nEventREQ3ID = 7;
  static const TEventID scm_nEventREQ4ID = 8;
  static const TEventID scm_nEventREQ5ID = 9;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventESDID = 1;
  static const TEventID scm_nEventERDID = 2;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  CIEC_BOOL &st_QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  
  CIEC_UINT &st_NodeID() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  }
  
  CIEC_UINT &st_TotalNode() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  }
  
  CIEC_WSTRING &st_RD_OUT_ID() {
    return *static_cast<CIEC_WSTRING*>(getDI(3));
  }
  
  CIEC_WSTRING &st_SD_IN_ID() {
    return *static_cast<CIEC_WSTRING*>(getDI(4));
  }
  
  CIEC_ANY &st_SD_IN_1() {
    return *static_cast<CIEC_ANY*>(getDI(5));
  }
  
  CIEC_ANY &st_SD_IN_2() {
    return *static_cast<CIEC_ANY*>(getDI(6));
  }
  
  CIEC_ANY &st_SD_IN_3() {
    return *static_cast<CIEC_ANY*>(getDI(7));
  }
  
  CIEC_ANY &st_SD_IN_4() {
    return *static_cast<CIEC_ANY*>(getDI(8));
  }
  
  CIEC_ANY &st_SD_IN_5() {
    return *static_cast<CIEC_ANY*>(getDI(9));
  }
  
  CIEC_UDINT &st_RD_IN() {
    return *static_cast<CIEC_UDINT*>(getDI(10));
  }
  
  CIEC_BOOL &st_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_WSTRING &st_STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(1));
  }
  
  CIEC_ANY &st_RD_OUT_1() {
    return *static_cast<CIEC_ANY*>(getDO(2));
  }
  
  CIEC_ANY &st_RD_OUT_2() {
    return *static_cast<CIEC_ANY*>(getDO(3));
  }
  
  CIEC_ANY &st_RD_OUT_3() {
    return *static_cast<CIEC_ANY*>(getDO(4));
  }
  
  CIEC_ANY &st_RD_OUT_4() {
    return *static_cast<CIEC_ANY*>(getDO(5));
  }
  
  CIEC_ANY &st_RD_OUT_5() {
    return *static_cast<CIEC_ANY*>(getDO(6));
  }
  
  CIEC_UDINT &st_SD_OUT() {
    return *static_cast<CIEC_UDINT*>(getDO(7));
  }
  

  FORTE_FB_DATA_ARRAY(3, 11, 8, 0);

  void executeEvent(int pa_nEIID);

  /************ Mixer Structure Definition ***********/
  struct SPortData{
    TForteUInt8 PortID;
    TForteUInt16 Value_Buffer[VALUE_BUFFER_SIZE];
    CIEC_ANY::EDataTypeID DataType;
  };

  struct SMixerSlot{
    TForteUInt8     SenderID;  
    CSinglyLinkedList<SPortData*> DatawPort;
  };
  typedef forte::core::util::CFixedCapazityVector<SMixerSlot, MIXER_TOTAL_SLOTS> Messages;

  struct SMixerDataMatrix{
    TForteUInt8     SenderID;  

    TForteUInt8 Flag_DataAvailable     :1;
    TForteUInt8 Flag_AppPiorityLoad    :1;
    TForteUInt8 Flag_NewData           :1;
    TForteUInt8 Flag_InnoForwLoad      ;  //3 levels
    TForteUInt8 Flag_Unused            :3;
    
    CSinglyLinkedList<SPortData*> DatawPort;
  };
  
  /************ End Structure Definition ***********/

  /*****************   Data Variable Definition   *********************/
  /* Transmission and Receive Buffer/Variable */
  TForteUInt32 m_TransBuffer[BUFFER_SIZE];
  TForteUInt32 m_RecvBuffer[BUFFER_SIZE];
  TForteUInt8  m_RecvIdx;
  TForteUInt8  m_TranIdx;

  /*This is Rx queue and Tx packet in the paper,
  Middle Structure to receive data from packet*/
  Messages Tx_Message;
  Messages Rx_Message;

  /*This is the main data matrix, contains all data from all nodes*/
  CSinglyLinkedList<SMixerDataMatrix*> MainCentralDataMatrix;

  /****************  End of Data Variable Definition   ****************/

  /****************   Control Variable Definition   *******************/
  TForteUInt8 NodeHistory[NODE_HISTORY_SIZE];
  TForteUInt8 ListReceivedPort[MAXIMUM_RECEIVE_PORT_PERNODE];
  TForteUInt8 ListTransmitPort[MAXIMUM_TRANSMIT_PORT_PERNODE];

  //TODO: Define Request, rank, neighbour here
  TForteUInt8 mNodeID;
  TForteUInt8 mTotalNumberNodes;
  TForteUInt8 mRoundNumber;   // This is Slot_No in original paper and in transmit mess.

  TForteUInt8 m_Trans_MessLength;
  bool Receive_Transmit_Flag;

  /**************  End of Control Variable Definition   ***************/

  /**********************  Private Function   *************************/
  /*Initialization Task*/
  bool isInitParameterValid(const TForteUInt16 paNodeID, const TForteUInt16 paTotalNumNode);
  void storeCurrentNodeID(const TForteUInt16 paNodeID);
  void storeTotalNumberOfNode(const TForteUInt16 paTotalNumNode);
  void initializeRound();

  void clearMessage(Messages & paMessage);
  void clearBuffer(TForteUInt32* buffer, size_t bufferSize);
  void clearAllData();
  
  void read_PortID(CIEC_WSTRING &PortIDString, TForteUInt8* PortID);
  void mixerInitialization(TForteUInt16 NodeID, TForteUInt16 TotalNumNode);
  
  /*Reception Logic Task*/
  void updateReceivedNodeHistory(TForteUInt8 NodeID);
  bool existedSenderinHistory(TForteUInt8 ID, SMixerDataMatrix*& position);

  void unpackingRx(Messages & paMessage, TForteUInt32* buffer);
  void updateDataMatrix(Messages & paMessage);
  void setRDOutput(TForteUInt16 paPortID, CIEC_ANY& paData);

  /*Transmittion Logic Task*/
  void packingTx(Messages & paMessage, TForteUInt32* buffer);
  void applicationPiorityLoad(TForteUInt8 &remainedSlot, Messages & paMessage);   
  void requestMessageLoad(TForteUInt8 &remainedSlot, Messages & paMessage);
  void innovationForwardingLoad(TForteUInt8 &remainedSlot, Messages & paMessage);
  void normalMessageLoad(TForteUInt8 &remainedSlot, Messages & paMessage);
  void prepareTxMessage(Messages & paMessage);
  
  /* Common Logic*/
  bool transmitProbability();
  size_t countElements(CSinglyLinkedList<SPortData*>& list);
  void copyDatawPort(CSinglyLinkedList<SPortData*> &destination, const CSinglyLinkedList<SPortData*> &source);
  bool Buffer_NonZero_Check(TForteUInt32* buffer);
  
  void savetoValueBuffer(CIEC_ANY& paData, TForteUInt16* buffer);
  void applicationReceive(TForteUInt16 paPortID, CIEC_ANY& paData);
  
  #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
    void printMessage(Messages & paMessage);
    void createfakedata(TForteUInt16 paPortID, CIEC_ANY& paData);
    void printCentralMatrix();
  #endif
  
public:
   FORTE_Mixer_Main(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CFunctionBlock( pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData) {
   };

  virtual ~FORTE_Mixer_Main() = default;
};

#endif // _MIXER_MAIN_H_


