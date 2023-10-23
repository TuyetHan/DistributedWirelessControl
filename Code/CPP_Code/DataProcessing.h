/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: DataProcessing
 *** Description: Service Interface Function Block Type
 *** Version:
***     1.0: 2023-08-25/ADMIN -  - 
 *************************************************************************/

#ifndef _DATAPROCESSING_H_
#define _DATAPROCESSING_H_

#include "funcbloc.h"
#include "forte_any.h"
// #error type contains variables of type ANY. Please check the usage of these variables as we can not gurantee correct usage on export!
#include "forte_bool.h"
#include "forte_uint.h"
#include "forte_wstring.h"
#include "forte_array_at.h"

#include "../../core/utils/parameterParser.h"

/*****************************************************************************/
//Data Related Constant
#define MIXER_TOTAL_SLOTS           4   
// #define MIXER_PAYLOAD_PERSLOT       16  //BYTES
// #define MIXER_SENDERID_SIZE         1   //BYTES
// #define MIXER_TOTAL_PAYLOAD         (MIXER_TOTAL_SLOTS*(MIXER_PAYLOAD_PERSLOT+MIXER_SENDERID_SIZE))

//General Mixer Parameters
#define MAXIMUM_NUMBER_NODES                255 //2^8 TODO: Need Review, lots more than needed 
// #define MAXIMUM_TRANSMIT_PORT_PERNODE       32  // 2^5 TODO: Need Review, lots more than needed
#define MAXIMUM_RECEIVE_PORT_PERNODE        32  // 2^5 TODO: Need Review, lots more than needed
#define MAXIMUM_NUMBER_PORTS                256 //2^8 - 1 bytes, 8 bits

#define NODE_HISTORY_SIZE               20 // Around double number of neighbors
#define MAXIMUM_INNOFORWARDING_SLOT     2

// Application Constant
#define NUM_INITIALIZE_PARAMETER    2
#define NODEID_POSITION             0
#define TOTAL_NODE_POSITION         1
#define DENOMINATOR_N_TRANSMIT      5

#define MIXER_DEBUG_ON      1
#define MIXER_DEBUG_OFF     0
#define MIXER_DEBUG_MODE    MIXER_DEBUG_ON

/*****************************************************************************/


class FORTE_DataProcessing: public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_DataProcessing)

private:
  
  /************ Mixer Structure Definition ***********/
  struct SPortData{
    // bool Flag_NewData  ;   //Flag indicate that this data not yet transmit
    
    TForteUInt8 PortID;
    CIEC_ANY Raw_Data;
  };

  struct SMixerSlot{
    TForteUInt8     SenderID;  
    CSinglyLinkedList<SPortData> DatawPort;
  };
  typedef forte::core::util::CFixedCapazityVector<SMixerSlot, MIXER_TOTAL_SLOTS> Messages;

  struct SMixerPacket{
    TForteUInt16  SlotNo;
    TForteUInt8   NodeID;                       //ID of current Node
    TForteUInt8   Flags;               //TODO: This is full rank notice flag
    TForteUInt16  CodingVector_Sv;     //TODO: Size should be consider again
    
    SMixerSlot    Data_Slot_Sp[MIXER_TOTAL_SLOTS];  //Contains whole Tx_Message or Rx_Message
    // Messages      MessageData;

    TForteUInt16  InfoVector_Sv;      //TODO: Size should be consider again
    TForteUInt16  CRC;
  };

  struct SMixerDataMatrix{
    TForteUInt8     SenderID;  

    TForteUInt8 Flag_DataAvailable     :1;
    TForteUInt8 Flag_AppPiorityLoad    :1;
    TForteUInt8 Flag_NewData           :1;
    TForteUInt8 Flag_InnoForwLoad      :2;  //3 levels
    TForteUInt8 Flag_Unused            :3;
    
    // SPortData      Data[MAXIMUM_TRANSMIT_PORT_PERNODE];
    CSinglyLinkedList<SPortData> DatawPort;
  };

  /************ End Structure Definition ***********/


  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventROUND_STARTID = 2;
  static const TEventID scm_nEventTRANSMIT_TRGID = 3;
  
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
  
  CIEC_ANY &st_SD_IN() {
    return *static_cast<CIEC_ANY*>(getDI(3));
  }
  
  CIEC_ANY &st_RD_IN() {
    return *static_cast<CIEC_ANY*>(getDI(4));
  }
  
  CIEC_BOOL &st_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_WSTRING &st_STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(1));
  }
  
  CIEC_ANY &st_SD_OUT() {
    return *static_cast<CIEC_ANY*>(getDO(2));
  }
  
  CIEC_ANY &st_RD_OUT() {
    return *static_cast<CIEC_ANY*>(getDO(3));
  }
  

  FORTE_FB_DATA_ARRAY(3, 5, 4, 0);

  void executeEvent(int pa_nEIID);

  /*****************   Data Variable Definition   *********************/
  /* Buffer - might be no need - can direct transfer struct*/
  uint8_t m_RecvBuffer[cg_unIPLayerRecvBufferSize];
  uint8_t m_TransBuffer[sizeof(SMixerPacket)];

  /* Whole transmit packet*/
  // CSinglyLinkedList<SMixerPacket*> TxPacket;
  // CSinglyLinkedList<SMixerPacket*> RxPacket;

  /*The whole transmit packet*/
  SMixerPacket TxPacket;
  SMixerPacket RxPacket;

  /*This is Rx queue and Tx packet in the paper,
  Middle Structure to receive data from packet*/
  

  Messages Tx_Message;
  Messages Rx_Message;
  // SMixerSlot TxMessage[MIXER_TOTAL_SLOTS];
  // SMixerSlot RxMessage[MIXER_TOTAL_SLOTS];

  /* Contains all data from Rx and application*/
  // TODO: Remove maindatamatrix
  SMixerDataMatrix MainDataMatrix[MAXIMUM_NUMBER_NODES];
  CSinglyLinkedList<SMixerDataMatrix*> MainCentralDataMatrix;

  /****************  End of Data Variable Definition   ****************/

  /****************   Control Variable Definition   *******************/
  TForteUInt8 NodeHistory[NODE_HISTORY_SIZE];
  TForteUInt8 ListReceivedPort[MAXIMUM_RECEIVE_PORT_PERNODE];

  //TODO: Define Request, Flags for Rx/Tx, round, rank, neighbour
  TForteUInt8 mNodeID;
  TForteUInt8 mTotalNumberNodes;
  TForteUInt8 mRoundNumber;   // This is Slot_No in original paper and in transmit mess.


  /**************  End of Control Variable Definition   ***************/

  /**********************  Private Function   *************************/
  bool isInitParameterValid(const TForteUInt16 paNodeID, const TForteUInt16 paTotalNumNode);
  void storeCurrentNodeID(const TForteUInt16 paNodeID);
  void storeTotalNumberOfNode(const TForteUInt16 paTotalNumNode);

  void initializeRound();
  void clearPacket(SMixerPacket *paPacket);
  void clearMessage(Messages & paMessage);
  void clearAllData();

  void mixerInitialization(TForteUInt16 NodeID, TForteUInt16 TotalNumNode);

  bool transmitProbability();
  
  void updateReceivedNodeHistory(TForteUInt8 NodeID);
  bool existedSenderinHistory(TForteUInt8 ID, CSinglyLinkedList<SMixerDataMatrix *>::Iterator position);

  int sizeofPortData(CSinglyLinkedList<SPortData> paPortData);
  void updateDataMatrix(Messages & paMessage);
  void unpackingRx(SMixerPacket *paPacket, Messages & paMessage);

  void packingTx(Messages & paMessage, SMixerPacket *paPacket);
  void applicationPiorityLoad(TForteUInt8 *remainedSlot, Messages & paMessage);   
  void requestMessageLoad(TForteUInt8 *remainedSlot, Messages & paMessage);
  void innovationForwardingLoad(TForteUInt8 *remainedSlot, Messages & paMessage);
  void normalMessageLoad(TForteUInt8 *remainedSlot, Messages & paMessage);
  void prepareTxMessage(Messages & paMessage);

  #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
    void printCentralMatrix();
  #endif
  
public:
   FORTE_DataProcessing(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CFunctionBlock( pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData) {
   };
    
  virtual ~FORTE_DataProcessing() = default;
};

#endif // _DATAPROCESSING_H_


