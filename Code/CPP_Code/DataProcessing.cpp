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

#include "DataProcessing.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DataProcessing_gen.cpp"
#endif

#include <string_utils.h>
#include "../../arch/devlog.h"



DEFINE_FIRMWARE_FB(FORTE_DataProcessing, g_nStringIdDataProcessing)

const CStringDictionary::TStringId FORTE_DataProcessing::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdNodeID, g_nStringIdTotalNode, g_nStringIdSD_IN, g_nStringIdRD_IN};

const CStringDictionary::TStringId FORTE_DataProcessing::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdANY, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_DataProcessing::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdSD_OUT, g_nStringIdRD_OUT};

const CStringDictionary::TStringId FORTE_DataProcessing::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdANY, g_nStringIdANY};

const TDataIOID FORTE_DataProcessing::scm_anEIWith[] = {0, 1, 2, 255, 0, 3, 4, 255};
const TForteInt16 FORTE_DataProcessing::scm_anEIWithIndexes[] = {0, 4, -1, -1};
const CStringDictionary::TStringId FORTE_DataProcessing::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdROUND_START, g_nStringIdTRANSMIT_TRG};

const TDataIOID FORTE_DataProcessing::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255, 3, 0, 1, 255};
const TForteInt16 FORTE_DataProcessing::scm_anEOWithIndexes[] = {0, 3, 7};
const CStringDictionary::TStringId FORTE_DataProcessing::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdESD, g_nStringIdERD};


const SFBInterfaceSpec FORTE_DataProcessing::scm_stFBInterfaceSpec = {
  4, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  3, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  5, scm_anDataInputNames, scm_anDataInputTypeIds,
  4, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

/*****************  Initialization Part  ********************/


bool FORTE_DataProcessing::isInitParameterValid(const TForteUInt16 paNodeID, const TForteUInt16 paTotalNumNode){
  bool l_everythingOK = true;

  if(paNodeID> MAXIMUM_NUMBER_NODES){
    DEVLOG_ERROR("[Mixer Middle Layer] Node ID larger than Maximum Total Number of Node: %d\n", MAXIMUM_NUMBER_NODES);
    l_everythingOK = false;

  }else if(paTotalNumNode > MAXIMUM_NUMBER_NODES){
    DEVLOG_ERROR("[Mixer Middle Layer] Total Number of node larger than Maximum Total Number of Node: %d\n", MAXIMUM_NUMBER_NODES);
    l_everythingOK = false;

  }else if (paNodeID == 0){ 
    DEVLOG_ERROR("[Mixer Middle Layer] Node ID must different from 0 \n");
    l_everythingOK = false;

  }else if(paNodeID>paTotalNumNode){
    DEVLOG_ERROR("[Mixer Middle Layer] NodeID must smaller or equal Total Number of Node\n");
    l_everythingOK = false;

  }else{
    l_everythingOK = true;

  }

  return l_everythingOK;
}

void FORTE_DataProcessing::storeCurrentNodeID(const TForteUInt16 paNodeID) {
  mNodeID = static_cast<TForteUInt8>(paNodeID);
}

void FORTE_DataProcessing::storeTotalNumberOfNode(const TForteUInt16 paTotalNumNode){
  mTotalNumberNodes = static_cast<TForteUInt8>(paTotalNumNode);
}

void FORTE_DataProcessing::initializeRound(){
  unsigned int i;
  mRoundNumber = 0;

  // Clear Node History.
  for (i=0;i>NODE_HISTORY_SIZE;i++){
    NodeHistory[i]= 0;
  }

}

void FORTE_DataProcessing::clearPacket(SMixerPacket *paPacket){
  unsigned int i;

  paPacket->SlotNo = 0;
  paPacket->NodeID = 0;
  paPacket->Flags = 0;
  paPacket->CodingVector_Sv = 0;

  // TODO: Review how to clear data message here.
  for(i=0; i > MIXER_TOTAL_SLOTS; i++){
    // paPacket->Data_Slot_Sp[i] = paMessage[i]; 

  }

  paPacket->InfoVector_Sv = 0;
  paPacket->CRC = 0;
}

void FORTE_DataProcessing::clearMessage(Messages & paMessage){
  unsigned int i;

  for(i=0; i > MIXER_TOTAL_SLOTS; i++){
    paMessage[i].SenderID = 0;
    paMessage[i].DatawPort.clearAll();
  }
}

void FORTE_DataProcessing::clearAllData(){

  /*Clear Main Data Matrix*/ 
  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
  iter != MainCentralDataMatrix.end(); ++iter){
    (*iter)->DatawPort.clearAll();
    delete (*iter);
  }

  /*Clear Tx and Rx Message*/
  clearMessage(Tx_Message);
  clearMessage(Rx_Message);

  /*Clear Tx and Rx Packet*/
  clearPacket(&TxPacket);
  clearPacket(&RxPacket);

}

void FORTE_DataProcessing::mixerInitialization(TForteUInt16 NodeID, TForteUInt16 TotalNumNode) {

  if (isInitParameterValid(NodeID, TotalNumNode))
  {
    storeCurrentNodeID(NodeID); 
    storeTotalNumberOfNode(TotalNumNode);
    initializeRound();
    clearAllData();
    DEVLOG_INFO("[Mixer Middle Layer] Succesfully Initialize \n");

  }else{
    DEVLOG_INFO("[Mixer Middle Layer] Wrong parameter, the FB is not initialized\n");
  }
  
}

/*************** End of Initialization Task  ****************/

bool FORTE_DataProcessing::transmitProbability(){
  bool l_transmition = false;

  // TODO: this function need to be written again.
  if((mRoundNumber % DENOMINATOR_N_TRANSMIT) == mNodeID){
    l_transmition = true;
  }
  
  return l_transmition;
}

/*****************  Receiption Logic Part  ********************/

void FORTE_DataProcessing::updateReceivedNodeHistory(TForteUInt8 NodeID){
  unsigned int i;

  // TODO: Not yet consider full history, slide window part
  for (i=0;i>NODE_HISTORY_SIZE;i++){
    if(NodeHistory[i]== 0){
      // Blank Slot, save Node ID
      NodeHistory[i] = NodeID;
      break;

    } else{
      if (NodeHistory[i]== NodeID){
        // Exit loop, already received from this node before
        break;
      }else{
        // Do nothing, continue.
      }

    }
  }

}


void FORTE_DataProcessing::unpackingRx(SMixerPacket *paPacket, Messages & paMessage){
  unsigned int i;
  // TODO: Synchronization round number

  updateReceivedNodeHistory(paPacket->NodeID);

  // TODO: Update Coding Vector
  // TODO: Full Rank Flag Receive

  for(i=0; i > MIXER_TOTAL_SLOTS; i++){
    paMessage[i] = paPacket->Data_Slot_Sp[i]; 
  }

  // TODO: Request Matrix update <- Info Vector

}

bool FORTE_DataProcessing::existedSenderinHistory(TForteUInt8 ID, CSinglyLinkedList<SMixerDataMatrix *>::Iterator position){

  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
  iter != MainCentralDataMatrix.end(); ++iter){
    if((*iter)->SenderID == ID){
      position = iter;
      return true;
    }
  }
  return false;
}

int FORTE_DataProcessing::sizeofPortData(CSinglyLinkedList<SPortData> paPortData){
  int count = 0;

  for(CSinglyLinkedList<SPortData>::Iterator iter = paPortData.begin(); 
  iter != paPortData.end(); ++iter){
    count ++;
  }

  return count;
}

void FORTE_DataProcessing::updateDataMatrix(Messages & paMessage){
  unsigned int i;
  CSinglyLinkedList<SMixerDataMatrix *>::Iterator position = nullptr;

  for(i=0; i > MIXER_TOTAL_SLOTS; i++){
    if(existedSenderinHistory(paMessage[i].SenderID, position)){
      // Check size of Single List
      if(sizeofPortData(paMessage[i].DatawPort)== 
      sizeofPortData(position->DatawPort)){
        // Old data, reduce piority
        (*position)->Flag_InnoForwLoad --;

      }else{
        // New data, coming
        // TODO: Check inside - outside cluster.
        (*position)->Flag_InnoForwLoad = 3;
        (*position)->Flag_NewData  = true;
        (*position)->DatawPort = paMessage[i].DatawPort;
      }

    }else{
      // Completely new data. Load all data from this slot.
      SMixerDataMatrix* accepted = new SMixerDataMatrix();
      accepted->SenderID = paMessage[i].SenderID;
      accepted->DatawPort = paMessage[i].DatawPort;

      accepted->Flag_InnoForwLoad   = 3;
      accepted->Flag_DataAvailable  = true;
      accepted->Flag_NewData        = true;
      MainCentralDataMatrix.pushBack(accepted);
    }
  }
}

/*************** End of Receiption Logic Part  ****************/

/*****************  Transmittion Logic Part  ********************/

void FORTE_DataProcessing::packingTx(Messages & paMessage, SMixerPacket *paPacket){
  unsigned int i;

  paPacket->SlotNo = mRoundNumber;
  paPacket->NodeID = mNodeID;

  // TODO: Update full rank flag

  // TODO: Update coding vector field
  for(i=0; i > MIXER_TOTAL_SLOTS; i++){
    paPacket->Data_Slot_Sp[i] = paMessage[i]; 

  }
  
  // TODO: Request -> info vector field

  // TODO: Update CRC field

}


void FORTE_DataProcessing::applicationPiorityLoad(TForteUInt8 *remainedSlot, Messages & paMessage){
  
  TForteUInt8   l_SlotNumber;

  /*Old Logic, keep for backup*/
  // TForteUInt8   i;
  // for(i=0; i > mTotalNumberNodes; i++){
  //   if(MainDataMatrix[i].Flag_AppPiorityLoad==1){
  //     l_SlotNumber = (TForteUInt8)(MIXER_TOTAL_SLOTS - *remainedSlot);

  //     // Load Data
  //     paMessage[l_SlotNumber].SenderID = MainDataMatrix[i].SenderID;
  //     paMessage[l_SlotNumber].DatawPort = MainDataMatrix[i].DatawPort;

  //     remainedSlot--;
  //   }
  // }
  /*End Old Logic*/

  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
    iter != MainCentralDataMatrix.end(); ++iter){
      // Seek for line with Application Data
      if((*iter)->Flag_AppPiorityLoad == true){
        l_SlotNumber = (TForteUInt8)(MIXER_TOTAL_SLOTS - *remainedSlot);

      // Load Data
      paMessage[l_SlotNumber].SenderID = (*iter)->SenderID;
      paMessage[l_SlotNumber].DatawPort = (*iter)->DatawPort;

      (*iter)->Flag_NewData = false;
      (*iter)->Flag_AppPiorityLoad = false;
      remainedSlot--;
      }
  }

}

void FORTE_DataProcessing::requestMessageLoad(TForteUInt8 *remainedSlot, Messages & paMessage){
// TODO: Request Tx load logic
// Below is dump logic
TForteUInt8* temp1 = remainedSlot;
Messages temp2 = paMessage;
temp1++;
}

void FORTE_DataProcessing::innovationForwardingLoad(TForteUInt8 *remainedSlot, Messages & paMessage){
  TForteUInt8   l_piorityLevel, l_SlotNumber;
  TForteUInt8   l_SlotUsed = 0;

  for(l_piorityLevel=3; l_piorityLevel>0; l_piorityLevel--){
    for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
    iter != MainCentralDataMatrix.end(); ++iter){

      if((*iter)->Flag_InnoForwLoad == l_piorityLevel){
        l_SlotNumber = (TForteUInt8)(MIXER_TOTAL_SLOTS - *remainedSlot);
        
        // Load Data
        paMessage[l_SlotNumber].SenderID = (*iter)->SenderID;
        paMessage[l_SlotNumber].DatawPort = (*iter)->DatawPort;        

        (*iter)->Flag_NewData = false;
        (*iter)->Flag_InnoForwLoad = 0;

        remainedSlot--;
        l_SlotUsed ++;

        // Exit Condition
        if (l_SlotUsed == MAXIMUM_INNOFORWARDING_SLOT){
          return;
        }
      }

    }
  }

}

void FORTE_DataProcessing::normalMessageLoad(TForteUInt8 *remainedSlot, Messages & paMessage){
  TForteUInt8 i, l_SlotNumber;

  while (*remainedSlot > 0)
  { 
    // TODO: This logic is invalid, need change MainDataMatrix to MainCentralDataMatrix
    // Randomly generate i between 0 - Maximum of Node.
    i = (TForteUInt8)(rand() % mTotalNumberNodes);

    if(MainDataMatrix[i].Flag_DataAvailable == 1){
      l_SlotNumber = (TForteUInt8)(MIXER_TOTAL_SLOTS - *remainedSlot);

      paMessage[l_SlotNumber].SenderID = MainDataMatrix[i].SenderID;
      paMessage[l_SlotNumber].DatawPort = MainDataMatrix[i].DatawPort;    
      
      MainDataMatrix[i].Flag_NewData = false;
      remainedSlot--;
    }
  }
}

void FORTE_DataProcessing::prepareTxMessage(Messages & paMessage){
  TForteUInt8 remainingSlot = MIXER_TOTAL_SLOTS;

  // The sooner function call, the higher piority.
  // Highest piority
  applicationPiorityLoad(&remainingSlot, paMessage);

  requestMessageLoad(&remainingSlot, paMessage);

  innovationForwardingLoad(&remainingSlot, paMessage);

  normalMessageLoad(&remainingSlot, paMessage);
  // Lowest piority

}

#if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
void FORTE_DataProcessing::printCentralMatrix(){

  // Find size of Central Data Matrix
  int count = 0;
  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
  iter != MainCentralDataMatrix.end(); ++iter){
    count ++;
    DEVLOG_INFO("Data Row: %d\n", count);

    DEVLOG_INFO("Sender ID: %d\n", (*iter)->SenderID);
    DEVLOG_INFO("Flag Data Available: %b  ", (*iter)->Flag_DataAvailable);
    DEVLOG_INFO("Flag App Piority: %b\n", (*iter)->Flag_AppPiorityLoad);
    DEVLOG_INFO("Flag New Data: %b  ", (*iter)->Flag_NewData);
    DEVLOG_INFO("Flag Innovation Forwarding Level: %b\n", (*iter)->Flag_InnoForwLoad);

    // TODO: Print data inside
  }

  // Print size of Central Data Matrix
  if(count == 0){
    DEVLOG_INFO("Central Data Matrix have no element.\n");
  }else{
    DEVLOG_INFO("Size of Matrix: %d\n", count);
  }
}


#endif

/*************** End of Transmittion Logic Part  ****************/


void FORTE_DataProcessing::executeEvent(int pa_nEIID) {

  switch(pa_nEIID) {
    case scm_nEventINITID:
      mixerInitialization(st_NodeID(), st_TotalNode());
      sendOutputEvent(scm_nEventINITOID);

      #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
        DEVLOG_INFO("NodeID: %d\n", mNodeID);
        DEVLOG_INFO("TotalNode: %d\n" , mTotalNumberNodes);
        DEVLOG_INFO("Round Number: %d\n" , mRoundNumber);

        printCentralMatrix();
      #endif

      break;
      
    case scm_nEventREQID:
      // Logic for receive application data - Data from SD_IN

      // Logic for receive network data - Data from RD_IN


      break;
    case scm_nEventROUND_STARTID:
      mRoundNumber++;

      if(transmitProbability()){
        // Perform Transmittion Task
        prepareTxMessage(Tx_Message);
        packingTx(Tx_Message, &TxPacket);
        // sendOutputEvent(scm_nEventESDID);

      }else{
        // Perform Receive Task
        unpackingRx(&RxPacket, Rx_Message);
        updateDataMatrix(Rx_Message);
        // sendOutputEvent(scm_nEventERDID);

      }

      break;
    case scm_nEventTRANSMIT_TRGID:
      st_SD_OUT().setValue(static_cast<CIEC_BOOL>(true));
      st_QO() = true;
      sendOutputEvent(scm_nEventESDID);
      sendOutputEvent(scm_nEventERDID);
      break;
  }
}


