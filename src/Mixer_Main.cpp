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

#include "Mixer_Main.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Mixer_Main_gen.cpp"
#endif

#include <string_utils.h>
#include "../../arch/devlog.h"

DEFINE_FIRMWARE_FB(FORTE_Mixer_Main, g_nStringIdMixer_Main)

const CStringDictionary::TStringId FORTE_Mixer_Main::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdNodeID, g_nStringIdTotalNode, g_nStringIdRD_OUT_ID, g_nStringIdSD_IN_ID, g_nStringIdSD_IN_1, g_nStringIdSD_IN_2, g_nStringIdSD_IN_3, g_nStringIdSD_IN_4, g_nStringIdSD_IN_5, g_nStringIdRD_IN};

const CStringDictionary::TStringId FORTE_Mixer_Main::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdUDINT};

const CStringDictionary::TStringId FORTE_Mixer_Main::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdRD_OUT_1, g_nStringIdRD_OUT_2, g_nStringIdRD_OUT_3, g_nStringIdRD_OUT_4, g_nStringIdRD_OUT_5, g_nStringIdSD_OUT};

const CStringDictionary::TStringId FORTE_Mixer_Main::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdUDINT};

const TDataIOID FORTE_Mixer_Main::scm_anEIWith[] = {0, 1, 2, 3, 4, 255, 10, 255, 5, 255, 6, 255, 7, 255, 8, 255, 9, 255};
const TForteInt16 FORTE_Mixer_Main::scm_anEIWithIndexes[] = {0, -1, -1, -1, 6, 8, 10, 12, 14, 16};
const CStringDictionary::TStringId FORTE_Mixer_Main::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdROUND_START, g_nStringIdTRANSMIT_TRG, g_nStringIdSEND_RD, g_nStringIdREQ_RD, g_nStringIdREQ1, g_nStringIdREQ2, g_nStringIdREQ3, g_nStringIdREQ4, g_nStringIdREQ5};

const TDataIOID FORTE_Mixer_Main::scm_anEOWith[] = {0, 1, 255, 0, 1, 7, 255, 2, 0, 1, 3, 4, 5, 6, 255};
const TForteInt16 FORTE_Mixer_Main::scm_anEOWithIndexes[] = {0, 3, 7};
const CStringDictionary::TStringId FORTE_Mixer_Main::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdESD, g_nStringIdERD};


const SFBInterfaceSpec FORTE_Mixer_Main::scm_stFBInterfaceSpec = {
  10, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  3, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  11, scm_anDataInputNames, scm_anDataInputTypeIds,
  8, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

/*****************  Initialization Part  ********************/


bool FORTE_Mixer_Main::isInitParameterValid(const TForteUInt16 paNodeID, const TForteUInt16 paTotalNumNode){
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

void FORTE_Mixer_Main::storeCurrentNodeID(const TForteUInt16 paNodeID) {
  mNodeID = static_cast<TForteUInt8>(paNodeID);
}

void FORTE_Mixer_Main::storeTotalNumberOfNode(const TForteUInt16 paTotalNumNode){
  mTotalNumberNodes = static_cast<TForteUInt8>(paTotalNumNode);
}

void FORTE_Mixer_Main::initializeRound(){
  unsigned int i;
  mRoundNumber = 0;

  // Clear Node History.
  for (i=0;i>NODE_HISTORY_SIZE;i++){
    NodeHistory[i]= 0;
  }

}

void FORTE_Mixer_Main::clearMessage(Messages & paMessage){
  for(unsigned int i =0; i < MIXER_TOTAL_SLOTS; i++){
    paMessage[i].SenderID = 0;
    if(!paMessage[i].DatawPort.isEmpty()){
      paMessage[i].DatawPort.clearAll();
    }
  }
}

void FORTE_Mixer_Main::clearBuffer(TForteUInt32* buffer, size_t bufferSize){
  memset(buffer, 0, bufferSize * sizeof(TForteUInt32));
}

void FORTE_Mixer_Main::clearAllData(){

  /*Clear Main Data Matrix*/ 
  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
  iter != MainCentralDataMatrix.end(); ++iter){
    (*iter)->DatawPort.clearAll();
    delete (*iter);
  }

  /*Clear Tx and Rx Message*/
  clearMessage(Tx_Message);
  clearMessage(Rx_Message);

  /*Clear Tx and Rx Buffer*/
  clearBuffer(m_TransBuffer, BUFFER_SIZE);
  clearBuffer(m_RecvBuffer, BUFFER_SIZE);

}

void FORTE_Mixer_Main::mixerInitialization(TForteUInt16 NodeID, TForteUInt16 TotalNumNode) {

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
void FORTE_Mixer_Main::read_PortID(CIEC_WSTRING &PortIDString, TForteUInt8* PortID){
  char *pacBuffer = PortIDString.getValue();
  CParameterParser parser(pacBuffer, ',');
  size_t amountOfParameters = parser.parseParameters();

  for(unsigned int i = 0; i < amountOfParameters; i++){
    TForteUInt8 extract_Port = static_cast<TForteUInt8>(forte::core::util::strtoul(parser[i], 0, 10));
    PortID[i] = extract_Port;
  }

}

/*************** End of Initialization Task  ****************/

/*****************  Reception Logic Part  ********************/
void FORTE_Mixer_Main::updateReceivedNodeHistory(TForteUInt8 NodeID){
  unsigned int i;

  // TODO: Not yet consider full history, slide window part
  // This feature not yet implement, need to consider whether needed or not.
  // The node history might support for cooperative transmission, improve startup and smart shutdown.
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

bool FORTE_Mixer_Main::existedSenderinHistory(TForteUInt8 ID, SMixerDataMatrix*& position){
  
  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); iter != MainCentralDataMatrix.end(); ++iter){
    if((*iter)->SenderID == ID){
      position = *iter;
      return true;
    }
  }
  return false;
}

void FORTE_Mixer_Main::unpackingRx(Messages & paMessage, TForteUInt32* buffer){
  // TODO: Synchronization round number. Edit: might not need synchorize round number.
  TForteUInt8 Number_Port_PerSender[MIXER_TOTAL_SLOTS];

  // First buffer element:
  /*|1 2         |3 4    |5 6           | 7 8    |*/
  /*|Round Number|Node ID|Message Length|Reserved|*/
#if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)  //suppress warning
  TForteUInt8 rcv_roundNumber = static_cast<TForteUInt8>(buffer[0] >> 24);
  TForteUInt8 rcv_NodeID = static_cast<TForteUInt8>(buffer[0] >> 16);
#endif
  TForteUInt8 rcv_MessageLength = static_cast<TForteUInt8>(buffer[0] >> 8);

  // Second buffer element: Info 2 - Sender ID
  /*|1 2        |3 4        |5 6        | 7 8       |*/
  /*|Sender ID 1|Sender ID 2|Sender ID 3|Sender ID 4|*/
  paMessage[0].SenderID = static_cast<TForteUInt8>(buffer[1] >> 24);
  paMessage[1].SenderID = static_cast<TForteUInt8>(buffer[1] >> 16);
  paMessage[2].SenderID = static_cast<TForteUInt8>(buffer[1] >> 8);
  paMessage[3].SenderID = static_cast<TForteUInt8>(buffer[1]);

  // Third buffer element: Info 3 - Number of port per sender
  /*|1  |2  |3  |4  |5 6 7 8 |*/
  /*|PN1|PN2|PN3|PN4|Reserved|*/
  Number_Port_PerSender[0] =  static_cast<TForteUInt8>((buffer[2] >> 28) & 0xF);
  Number_Port_PerSender[1] =  static_cast<TForteUInt8>((buffer[2] >> 24) & 0xF);
  Number_Port_PerSender[2] =  static_cast<TForteUInt8>((buffer[2] >> 20) & 0xF);
  Number_Port_PerSender[3] =  static_cast<TForteUInt8>((buffer[2] >> 16) & 0xF);
  
 #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
    DEVLOG_INFO("Rcv Round Number: %d, Rcv Node ID: %d\n", rcv_roundNumber, rcv_NodeID);
    DEVLOG_INFO("Rcv Mess Length: %d\n", rcv_MessageLength);

    DEVLOG_INFO("Rcv Sender ID:       %d, %d, %d, %d\n", paMessage[0].SenderID,paMessage[1].SenderID,
                                                  paMessage[2].SenderID,paMessage[3].SenderID);

    DEVLOG_INFO("Rcv Port per sender: %d, %d, %d, %d\n", Number_Port_PerSender[0],Number_Port_PerSender[1],
                                                  Number_Port_PerSender[2],Number_Port_PerSender[3]);
  #endif

  // Other buffer element: Data
  /*|1 2    |3 4      | 5 6 7 8|*/
  /*|Port ID|Data Type| Data   |*/
  /*|            Data          |*/  //If requires more than 16 bits

  TForteUInt8 sender_idx = 0;
  TForteUInt8 port_count = 0;
  for(unsigned int i = 3; i <= rcv_MessageLength; i++){
    if(Number_Port_PerSender[sender_idx] != 0){
      TForteUInt8 rcv_PortID = static_cast<TForteUInt8>(buffer[i] >> 24);
      CIEC_ANY::EDataTypeID rcv_DataType = static_cast<CIEC_ANY::EDataTypeID>((buffer[i] >> 16) & 0xFF);
      SPortData* accepted_PData = new SPortData();
      accepted_PData->PortID = rcv_PortID;
      accepted_PData->DataType = rcv_DataType;
      switch (rcv_DataType)
      {
        // Data Type smaller than or equal 16 bits.
        // Port ID, Data Type and Data fit into 1 buffer slot. 
        case CIEC_ANY::e_BOOL:
          accepted_PData->Value_Buffer[0] = buffer[i]& 0x01;
          paMessage[sender_idx].DatawPort.pushBack(accepted_PData);
          port_count++;
          break;

        case CIEC_ANY::e_SINT:
        case CIEC_ANY::e_USINT:
        case CIEC_ANY::e_BYTE:
          accepted_PData->Value_Buffer[0] = buffer[i]& 0xFF;
          paMessage[sender_idx].DatawPort.pushBack(accepted_PData);
          port_count++;
          break;

        case CIEC_ANY::e_INT:
        case CIEC_ANY::e_UINT:
        case CIEC_ANY::e_WORD:
          accepted_PData->Value_Buffer[0] = buffer[i]& 0xFFFF;
          paMessage[sender_idx].DatawPort.pushBack(accepted_PData);
          port_count++;
          break;

        //32 bits - Takes the whole next buffer slot.  
        case CIEC_ANY::e_DINT: 
        case CIEC_ANY::e_UDINT:
        case CIEC_ANY::e_DWORD:         
        case CIEC_ANY::e_REAL: 
          memcpy(accepted_PData->Value_Buffer, &buffer[i+1], sizeof(TForteFloat));
          paMessage[sender_idx].DatawPort.pushBack(accepted_PData);
          i++;
          port_count++;
          break;

        //64 bits - Takes the whole 2 next buffer slot.
        case CIEC_ANY::e_LINT: 
        case CIEC_ANY::e_ULINT:
        case CIEC_ANY::e_LWORD: 
        case CIEC_ANY::e_LREAL: 
          memcpy(accepted_PData->Value_Buffer, &buffer[i+1], sizeof(TForteDFloat));
          paMessage[sender_idx].DatawPort.pushBack(accepted_PData);
          i = i + 2;
          port_count++;
          break;

        default:
          // None support datatype: e_STRING, e_WSTRING, e_DATE, e_TIME_OF_DAY, e_DATE_AND_TIME, e_TIME
          break;
      }

      if(port_count == Number_Port_PerSender[sender_idx]){
        #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
          DEVLOG_INFO("   Unpacking Tx checkpoint: Port Count Full. Switch to next data line\n");
        #endif
        port_count = 0;
        sender_idx++;

        if (sender_idx == MIXER_TOTAL_SLOTS){
          if(i < rcv_MessageLength){
            DEVLOG_ERROR("Received Message exceed expected message length. Data Corrupt or Receive more than 1 message in 1 round.\n");
          }
        }
      }

    }
  }

  // TODO: Update Coding Vector, Full Rank Flag, Request Matrix.
  // This feature not yet implement, need to consider whether needed or not.
  // updateReceivedNodeHistory(paPacket->NodeID);
}

void FORTE_Mixer_Main::updateDataMatrix(Messages & paMessage){
  SMixerDataMatrix* position;

  // Note: Need to review if Received Message have message from own node.
  for(unsigned int i = 0; i < MIXER_TOTAL_SLOTS; i++){
    if (countElements(paMessage[i].DatawPort) == 0){
      continue;
    }
    if ((paMessage[i].SenderID == mNodeID) || (paMessage[i].SenderID == 0)){
      continue;
    }

    if(existedSenderinHistory(paMessage[i].SenderID, position)){
      bool noNewData = true;

      for(CSinglyLinkedList<SPortData* > :: Iterator iter1 = paMessage[i].DatawPort.begin();
        iter1 !=paMessage[i].DatawPort.end(); ++iter1){
        bool found_port = false;

        for(CSinglyLinkedList<SPortData* > :: Iterator iter2 =  (position)->DatawPort.begin();
          iter2 !=(position)->DatawPort.end(); ++iter2){
          if((iter1)->PortID == (iter2)-> PortID){
            found_port = true;
            std::copy((iter1)->Value_Buffer, (iter1)->Value_Buffer + VALUE_BUFFER_SIZE, (iter2)->Value_Buffer);
            break;
          }
        }

        if(found_port == false){
          SPortData* accepted_PData = new SPortData();
          accepted_PData->PortID = static_cast<TForteUInt8>((iter1)->PortID);
          std::copy((iter1)->Value_Buffer, (iter1)->Value_Buffer + VALUE_BUFFER_SIZE, (accepted_PData)->Value_Buffer);
          accepted_PData->DataType = (iter1)->DataType;

          (position)->DatawPort.pushBack(accepted_PData);
          noNewData = false;
          (position)->Flag_InnoForwLoad = 3;
        }

      }

      if(noNewData == true){
        (position)->Flag_InnoForwLoad--;
      }

    }else{
      // Completely new data. Load all data from this slot.
      SMixerDataMatrix* accepted = new SMixerDataMatrix();
      accepted->SenderID = paMessage[i].SenderID;
      copyDatawPort(accepted->DatawPort, paMessage[i].DatawPort);

      // Update Information Flag
      accepted->Flag_InnoForwLoad   = 3;
      accepted->Flag_DataAvailable  = true;
      accepted->Flag_NewData        = true;
      MainCentralDataMatrix.pushBack(accepted);
      
    }
  }
}

void FORTE_Mixer_Main::setRDOutput(TForteUInt16 paPortID, CIEC_ANY &paPort){
  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
  iter != MainCentralDataMatrix.end(); ++iter){
    for(CSinglyLinkedList<SPortData* > :: Iterator iter2 =  (*iter)->DatawPort.begin();
      iter2 !=(*iter)->DatawPort.end(); ++iter2){
      if(paPortID == (iter2)->PortID){
        TForteUInt16 *buffer= (*iter2)->Value_Buffer;

        switch ((*iter2)->DataType)
        {
          case CIEC_ANY::e_BOOL:
            // DEVLOG_INFO("Send RD Out: BOOL data type. Value: %d\n", *buffer);
            paPort.saveAssign(static_cast<CIEC_BOOL>(*buffer));
            break;

          case CIEC_ANY::e_SINT:
            paPort.saveAssign(static_cast<CIEC_SINT>(static_cast<TForteUInt8>(*buffer)));
            break;

          case CIEC_ANY::e_USINT:
            paPort.saveAssign(static_cast<CIEC_SINT>(static_cast<TForteInt8>(*buffer)));
            break;

          case CIEC_ANY::e_INT:
            paPort.saveAssign(static_cast<CIEC_INT>(*buffer));
            break;

          case CIEC_ANY::e_UINT:
            paPort.saveAssign(static_cast<CIEC_UINT>(*buffer));
            break;

          case CIEC_ANY::e_DINT:
            paPort.saveAssign(static_cast<CIEC_DINT>(*reinterpret_cast<TForteInt32*>(buffer)));
            break;

          case CIEC_ANY::e_UDINT:
            paPort.saveAssign(static_cast<CIEC_UDINT>(*reinterpret_cast<TForteUInt32*>(buffer)));
            break;

          case CIEC_ANY::e_LINT:
            paPort.saveAssign(static_cast<CIEC_LINT>(*reinterpret_cast<TForteInt64*>(buffer)));
            break;

          case CIEC_ANY::e_ULINT:
            paPort.saveAssign(static_cast<CIEC_ULINT>(*reinterpret_cast<TForteUInt64*>(buffer)));
            break;            

          case CIEC_ANY::e_REAL:
            // DEVLOG_INFO("Send RD Out: REAL data type. Value: %f\n", *reinterpret_cast<TForteFloat*>(buffer));
            paPort.saveAssign(static_cast<CIEC_REAL>(*reinterpret_cast<TForteFloat*>(buffer)));
            break;

          case CIEC_ANY::e_LREAL:
            paPort.saveAssign(static_cast<CIEC_LREAL>(*reinterpret_cast<TForteDFloat*>(buffer)));
            break;

          case CIEC_ANY::e_BYTE:
            paPort.saveAssign(static_cast<CIEC_BYTE>(*reinterpret_cast<TForteByte*>(buffer)));
            break;

          case CIEC_ANY::e_WORD:
            paPort.saveAssign(static_cast<CIEC_WORD>(*reinterpret_cast<TForteWord*>(buffer)));
            break;

          case CIEC_ANY::e_DWORD:
          paPort.saveAssign(static_cast<CIEC_DWORD>(*reinterpret_cast<TForteDWord*>(buffer)));
          break; 

          case CIEC_ANY::e_LWORD:
          paPort.saveAssign(static_cast<CIEC_LWORD>(*reinterpret_cast<TForteLWord*>(buffer)));
          break;             

          default:
            //None support datatype: e_STRING, e_WSTRING, e_DATE, e_TIME_OF_DAY, e_DATE_AND_TIME, e_TIME
            break;
        }
        
        break;
      }
    }
  }
}

/*************** End of Receiption Logic Part  ****************/

/*****************  Transmittion Logic Part  ********************/
void FORTE_Mixer_Main::packingTx(Messages & paMessage, TForteUInt32* buffer){

  // TODO: Update full rank flag, coding vector, request flags, CRC.
  // This feature not yet implement, need to consider whether needed or not.
  // Second buffer element: Info 2 - Sender ID
  /*|1 2        |3 4        |5 6        | 7 8       |*/
  /*|Sender ID 1|Sender ID 2|Sender ID 3|Sender ID 4|*/
  buffer[1] = (paMessage[0].SenderID  << 24)|(paMessage[1].SenderID  << 16)|
              (paMessage[2].SenderID  << 8) |(paMessage[3].SenderID);

  // Third buffer element: Info 3 - Number of port per sender
  /*|1  |2  |3  |4  |5 6 7 8 |*/
  /*|PN1|PN2|PN3|PN4|Reserved|*/
  buffer[2] = (countElements(paMessage[0].DatawPort) << 28)|(countElements(paMessage[1].DatawPort) << 24)|
              (countElements(paMessage[2].DatawPort) << 20)|(countElements(paMessage[3].DatawPort) << 16);

  
  // Other buffer element: Data
  /*|1 2    |3 4      | 5 6 7 8|*/
  /*|Port ID|Data Type| Data   |*/
  /*|            Data          |*/  //If requires more than 16 bits
  TForteUInt8 current_pos = 3;
  for(int i = 0; i < MIXER_TOTAL_SLOTS; i++){
    for(CSinglyLinkedList<SPortData* > :: Iterator iter2 =  paMessage[i].DatawPort.begin(); 
      iter2 !=paMessage[i].DatawPort.end(); ++iter2){
        switch ((*iter2)->DataType){
          // Data Type smaller than or equal 16 bits.
          // Port ID, Data Type and Data fit into 1 buffer slot. 
          case CIEC_ANY::e_BOOL:
          case CIEC_ANY::e_SINT:
          case CIEC_ANY::e_INT:
          case CIEC_ANY::e_USINT:
          case CIEC_ANY::e_UINT:
          case CIEC_ANY::e_BYTE:
          case CIEC_ANY::e_WORD:
            TForteUInt16 data_buffer;
            data_buffer = (*iter2)->Value_Buffer[0];
            buffer[current_pos] = ((*iter2)->PortID << 24)|((*iter2)->DataType << 16)|(data_buffer);
            current_pos++;
            break;
          
          // Data Type need 32 bits
          case CIEC_ANY::e_DINT:
          case CIEC_ANY::e_UDINT:
          case CIEC_ANY::e_DWORD:
          case CIEC_ANY::e_REAL:
            buffer[current_pos]   = ((*iter2)->PortID << 24)|((*iter2)->DataType << 16);
            memcpy(&buffer[current_pos+1], (*iter2)->Value_Buffer, sizeof(TForteFloat));
            current_pos = static_cast<TForteUInt8>(current_pos + 2);
            break;

          // Data Type need 64 bits
          case CIEC_ANY::e_LINT:
          case CIEC_ANY::e_ULINT:
          case CIEC_ANY::e_LWORD:
          // case CIEC_ANY::e_DATE:
          // case CIEC_ANY::e_TIME_OF_DAY:
          // case CIEC_ANY::e_DATE_AND_TIME:
          // case CIEC_ANY::e_TIME:  
          case CIEC_ANY::e_LREAL:
            buffer[current_pos] = ((*iter2)->PortID << 24)|((*iter2)->DataType << 16);
            memcpy(&buffer[current_pos+1], (*iter2)->Value_Buffer, sizeof(TForteDFloat));
            current_pos = static_cast<TForteUInt8>(current_pos + 3);
            break;

          default:
            //None support datatype: e_STRING, e_WSTRING, e_DATE, e_TIME_OF_DAY, e_DATE_AND_TIME, e_TIME
            break;
        }
      } 
  }

  // First buffer element: Info 1
  /*|1 2         |3 4    |5 6           | 7 8    |*/
  /*|Round Number|Node ID|Message Length|Reserved|*/
  m_Trans_MessLength = current_pos;
  buffer[0] = (mRoundNumber << 24)|(mNodeID << 16)|(m_Trans_MessLength << 8);

}

void FORTE_Mixer_Main::applicationPiorityLoad(TForteUInt8 &remainedSlot, Messages & paMessage){
  TForteUInt8   l_SlotNumber;

  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
    iter != MainCentralDataMatrix.end(); ++iter){
      // Seek for line with Application Data
      if((*iter)->Flag_AppPiorityLoad == true){
        l_SlotNumber = (TForteUInt8)(MIXER_TOTAL_SLOTS - remainedSlot);

      // Load Data
      paMessage[l_SlotNumber].SenderID = (*iter)->SenderID;
      copyDatawPort(paMessage[l_SlotNumber].DatawPort, (*iter)->DatawPort);

      (*iter)->Flag_NewData = false;
      (*iter)->Flag_AppPiorityLoad = false;
      remainedSlot--;
      #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
        DEVLOG_INFO("   AppPiority Check Point- ID: %d\n", (*iter)->SenderID);
      #endif
      }
  }

}

void FORTE_Mixer_Main::requestMessageLoad(TForteUInt8 &remainedSlot, Messages & paMessage){
// TODO: Request Tx load logic
// Below is dump logic
  TForteUInt8 temp1 = remainedSlot;
  Messages temp2 = paMessage;
  temp1++;
}

void FORTE_Mixer_Main::innovationForwardingLoad(TForteUInt8 &remainedSlot, Messages & paMessage){
  TForteUInt8   l_piorityLevel, l_SlotNumber;
  TForteUInt8   l_SlotUsed = 0;

  for(l_piorityLevel=3; l_piorityLevel>0; l_piorityLevel--){
    for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
    iter != MainCentralDataMatrix.end(); ++iter){

      if((*iter)->Flag_InnoForwLoad == l_piorityLevel){
        l_SlotNumber = (TForteUInt8)(MIXER_TOTAL_SLOTS - remainedSlot);
        
        // Load Data
        paMessage[l_SlotNumber].SenderID = (*iter)->SenderID;
        copyDatawPort(paMessage[l_SlotNumber].DatawPort, (*iter)->DatawPort);     

        (*iter)->Flag_NewData = false;
        (*iter)->Flag_InnoForwLoad = 0;

        remainedSlot--;
        l_SlotUsed ++;
        #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
          DEVLOG_INFO("   Innovation FW Check Point - ID: %d\n", (*iter)->SenderID);
        #endif

        // Exit Condition
        if (l_SlotUsed == MAXIMUM_INNOFORWARDING_SLOT){
          return;
        }
      }
    }
  }
}

void FORTE_Mixer_Main::normalMessageLoad(TForteUInt8 &remainedSlot, Messages & paMessage){
  TForteUInt8 randrow, l_SlotNumber, count, totalRow;
  totalRow = 0;

  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
  iter != MainCentralDataMatrix.end(); ++iter){
    totalRow ++;
  }

  if(totalRow == (MIXER_TOTAL_SLOTS - remainedSlot)){
    // all data already loaded
    return;
  }

  // Only try to load each of the remained Slot 2 times.
  for(int i=0; i < remainedSlot*2; i++)
  { 
    // Pick a random row
    randrow = (TForteUInt8)(rand() % totalRow);

    for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
      iter != MainCentralDataMatrix.end(); ++iter){

        if(count == randrow){  
          if((*iter)->Flag_NewData == 1){
            l_SlotNumber = (TForteUInt8)(MIXER_TOTAL_SLOTS - remainedSlot);

            paMessage[l_SlotNumber].SenderID = (*iter)->SenderID;
            copyDatawPort(paMessage[l_SlotNumber].DatawPort, (*iter)->DatawPort);     
            
            (*iter)->Flag_NewData = false;
            remainedSlot--;

            count = 0;
            #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
              DEVLOG_INFO("   Normal Load Check Point- ID: %d\n", (*iter)->SenderID);
            #endif
            break;

          }
        }
        count++;  
    }
  }
}

void FORTE_Mixer_Main::prepareTxMessage(Messages & paMessage){
  TForteUInt8 remainingSlot = MIXER_TOTAL_SLOTS;

  // The sooner function call, the higher piority.
  // Highest piority
  applicationPiorityLoad(remainingSlot, paMessage);

  // requestMessageLoad(remainingSlot, paMessage);

  innovationForwardingLoad(remainingSlot, paMessage);

  normalMessageLoad(remainingSlot, paMessage);
  // Lowest piority
}

/************** End of Transmittion Logic Part  ***************/

/*************** Start of Common Logic Part  ****************/
bool FORTE_Mixer_Main::transmitProbability(){
  bool l_transmition = false;

  // TODO: this function need to be checked again. 
  // Semi-coordinated Transmissions should be implement here.
  if((mRoundNumber % mTotalNumberNodes) + 1 == mNodeID){
    l_transmition = true;
  }

  #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
    DEVLOG_INFO("Round Number: %d - %s round\n" , mRoundNumber, l_transmition? "Transmit":"Receive");
  #endif
  
  return l_transmition;
}

// TODO: replace size of port data by countElements
size_t FORTE_Mixer_Main::countElements(CSinglyLinkedList<SPortData*> & list) {
    size_t count = 0;
    auto iter = list.begin();
    auto end = list.end();

    while (iter != end) {
        ++count;
        ++iter;
    }

    return count;
}

void FORTE_Mixer_Main::copyDatawPort(CSinglyLinkedList<SPortData*> &destination, const CSinglyLinkedList<SPortData*> &source) {
    // Clear the destination list
    destination.clearAll();

    // Iterate over the source list and copy each SPortData*
    for(CSinglyLinkedList<SPortData*>::Iterator iter = source.begin(); iter != source.end(); ++iter){
        SPortData* newData = new SPortData();
        newData->PortID =  (*iter)->PortID;
        std::copy((*iter)->Value_Buffer, (*iter)->Value_Buffer + VALUE_BUFFER_SIZE, (newData)->Value_Buffer);
        newData->DataType = (*iter)->DataType;
        destination.pushBack(newData);
    }
}

bool FORTE_Mixer_Main::Buffer_NonZero_Check(TForteUInt32* buffer){
  bool NonZeroValue = true;

  for (size_t i = 0; i < BUFFER_SIZE; ++i) {
    if (buffer[i] != 0) {
        NonZeroValue = false;
        break;
    }
  }
  return NonZeroValue;
}

void FORTE_Mixer_Main::savetoValueBuffer(CIEC_ANY& paData, TForteUInt16* buffer){
  switch (paData.getDataTypeID())
  { 
    // 16 Bits
    case CIEC_ANY::e_BOOL:
    case CIEC_ANY::e_SINT:
    case CIEC_ANY::e_INT:
    case CIEC_ANY::e_USINT:
    case CIEC_ANY::e_UINT:
    case CIEC_ANY::e_BYTE:
    case CIEC_ANY::e_WORD:
      memcpy(buffer, paData.getDataPtr(), sizeof(TForteUInt16));
      break;

    // 32 Bits
    case CIEC_ANY::e_DINT:
    case CIEC_ANY::e_UDINT:
    case CIEC_ANY::e_DWORD:
    case CIEC_ANY::e_REAL:
      memcpy(buffer, paData.getDataPtr(), sizeof(TForteFloat));
      break;

    // 64 Bits
    case CIEC_ANY::e_LINT:
    case CIEC_ANY::e_ULINT:
    case CIEC_ANY::e_LWORD:
    case CIEC_ANY::e_LREAL:
      memcpy(buffer, paData.getDataPtr(), sizeof(TForteDFloat));
      break;

    default:
      //None support datatype: e_STRING, e_WSTRING, e_DATE, e_TIME_OF_DAY, e_DATE_AND_TIME, e_TIME
      DEVLOG_INFO("Warning: Mixer not yet support this datatype.\n");
      break;
  }
}

void FORTE_Mixer_Main::applicationReceive(TForteUInt16 paPortID, CIEC_ANY& paData){
  bool loadDataFinished = false;
  
  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
    iter != MainCentralDataMatrix.end(); ++iter){
      
      // Seek for row contains Application Data
      if((*iter)->SenderID == mNodeID){
        // Find appropriate port
        for(CSinglyLinkedList<SPortData* > :: Iterator iter2 =  (*iter)->DatawPort.begin();
          iter2 !=(*iter)->DatawPort.end(); ++iter2){
          if(paPortID == (iter2)->PortID){
            // Data already received before, replace old data with new data.
            savetoValueBuffer(paData, (iter2)->Value_Buffer);

            loadDataFinished = true;
            break;
          }
        }
        
        // Can't find appropriate port
        if (loadDataFinished == false){
          loadDataFinished = true;
          // Create new port slot  
          SPortData* accepted_PData = new SPortData();
          accepted_PData->PortID = static_cast<TForteUInt8>(paPortID);
          savetoValueBuffer(paData, accepted_PData->Value_Buffer);
          accepted_PData->DataType = paData.getDataTypeID();

          (*iter)->DatawPort.pushBack(accepted_PData);
        }

        (*iter)->Flag_NewData = true;
        (*iter)->Flag_AppPiorityLoad = true;

      }
  }

  if (loadDataFinished == false){
    // First time receive application data, create new row
    SMixerDataMatrix* accepted = new SMixerDataMatrix();
    SPortData* accepted_PData = new SPortData();

    accepted_PData->PortID = static_cast<TForteUInt8>(paPortID);
    savetoValueBuffer(paData, accepted_PData->Value_Buffer);
    accepted_PData->DataType = paData.getDataTypeID();
    
    accepted->SenderID = mNodeID;
    accepted->DatawPort.pushBack(accepted_PData);

    // Update Information Flag
    accepted->Flag_AppPiorityLoad   = true;
    accepted->Flag_DataAvailable    = true;
    accepted->Flag_NewData          = true;
    accepted->Flag_InnoForwLoad     = 0;
    MainCentralDataMatrix.pushBack(accepted);
  }

  #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
    TForteByte *acDataPtr = paData.getDataPtr();
    DEVLOG_INFO("App Data Receive...Port ID: %d Data: %d Type: %d\n", paPortID, *acDataPtr, paData.getDataTypeID());
    // if (paData.getDataTypeID() == CIEC_ANY::e_REAL){
    //   DEVLOG_INFO("Data: %f Type: %d\n", *reinterpret_cast<TForteFloat*>(acDataPtr), paData.getDataTypeID());
    // }
    // createfakedata(paPortID, paData);
    // printCentralMatrix();
  #endif
}
/*************** End of General Logic Part  ****************/

/*************** Start of Debug Logic Part  ****************/

#if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)

void FORTE_Mixer_Main::createfakedata(TForteUInt16 paPortID, CIEC_ANY& paData){
  TForteUInt8 fakeNodeID = (TForteUInt8)(rand() % 10);
  bool loadDataFinished = false;
  
  // Avoid genrate same ID with current node
  if (fakeNodeID == mNodeID){fakeNodeID = (TForteUInt8)(rand() % mNodeID);}

  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
    iter != MainCentralDataMatrix.end(); ++iter){
      
      // Seek for row contains Application Data
      if((*iter)->SenderID == fakeNodeID){
        // Find appropriate port
        for(CSinglyLinkedList<SPortData* > :: Iterator iter2 =  (*iter)->DatawPort.begin();
          iter2 !=(*iter)->DatawPort.end(); ++iter2){
          if(paPortID == (iter2)->PortID){
            // Data already received before, replace old data with new data.
            loadDataFinished = true;
            break;
          }
        }
        
        // Can't find appropriate port
        if (loadDataFinished == false){
          loadDataFinished = true;
          // Create new port slot  
          SPortData* accepted_PData = new SPortData();
          accepted_PData->PortID = static_cast<TForteUInt8>(paPortID);
          accepted_PData->DataType = paData.getDataTypeID();

          (*iter)->DatawPort.pushBack(accepted_PData);
        }

        (*iter)->Flag_DataAvailable = true;
        (*iter)->Flag_AppPiorityLoad = false;

      }
  }

  if (loadDataFinished == false){
    // First time receive application data, create new row
    SMixerDataMatrix* accepted = new SMixerDataMatrix();
    SPortData* accepted_PData = new SPortData();

    accepted_PData->PortID = static_cast<TForteUInt8>(paPortID);
    accepted_PData->DataType = paData.getDataTypeID();

    accepted->SenderID = fakeNodeID;
    accepted->DatawPort.pushBack(accepted_PData);

    // Update Information Flag
    accepted->Flag_AppPiorityLoad   = false;
    accepted->Flag_DataAvailable  = true;
    accepted->Flag_NewData        = true;
    accepted->Flag_InnoForwLoad = static_cast<TForteUInt8>((rand() % 4));
    MainCentralDataMatrix.pushBack(accepted);
  }
}

void FORTE_Mixer_Main::printCentralMatrix(){

  DEVLOG_INFO("Central Matrix Print\n");
  int count = 0;
  for(CSinglyLinkedList<SMixerDataMatrix *>::Iterator iter = MainCentralDataMatrix.begin(); 
  iter != MainCentralDataMatrix.end(); ++iter){
    count ++;
    DEVLOG_INFO("   Sender ID: %d\n", (*iter)->SenderID);
    DEVLOG_INFO("      DA: %s, App Pi: %s, New: %s, Inn Fw L: %d\n",(*iter)->Flag_DataAvailable ? "true":"false",
            (*iter)->Flag_AppPiorityLoad? "true":"false",  (*iter)->Flag_NewData? "true":"false", (*iter)->Flag_InnoForwLoad);

    for(CSinglyLinkedList<SPortData* > :: Iterator iter2 =  (*iter)->DatawPort.begin();
      iter2 !=(*iter)->DatawPort.end(); ++iter2){
        TForteUInt16 *dataPtr= (*iter2)->Value_Buffer;

        switch ((*iter2)->DataType){
          case CIEC_ANY::e_BOOL:
            DEVLOG_INFO("      Port ID: %d, BOOL Data Type, Value: %s\n",(*iter2)->PortID, *dataPtr? "TRUE":"FALSE");
            break;

          case CIEC_ANY::e_SINT:
            DEVLOG_INFO("      Port ID: %d, SINT Data Type, Value: %d\n",(*iter2)->PortID, static_cast<TForteInt8>(*dataPtr));
            break;  

          case CIEC_ANY::e_INT:
            DEVLOG_INFO("      Port ID: %d, INT Data Type, Value: %d\n",(*iter2)->PortID, static_cast<TForteInt16>(*dataPtr));
            break;

          case CIEC_ANY::e_USINT:
            DEVLOG_INFO("      Port ID: %d, USINT Data Type, Value: %d\n",(*iter2)->PortID, static_cast<TForteUInt8>(*dataPtr));
            break;

          case CIEC_ANY::e_UINT:
            DEVLOG_INFO("      Port ID: %d, UINT Data Type, Value: %d\n",(*iter2)->PortID, static_cast<TForteUInt16>(*dataPtr));
            break;

          case CIEC_ANY::e_DINT:
            DEVLOG_INFO("      Port ID: %d, DINT Data Type, Value: %d\n",(*iter2)->PortID, *reinterpret_cast<TForteInt32*>(dataPtr));
            break;

          case CIEC_ANY::e_UDINT:
            DEVLOG_INFO("      Port ID: %d, UDINT Data Type, Value: %d\n",(*iter2)->PortID, *reinterpret_cast<TForteUInt32*>(dataPtr));
            break;

          case CIEC_ANY::e_LINT:
            DEVLOG_INFO("      Port ID: %d, LINT Data Type, Value: %d\n",(*iter2)->PortID, *reinterpret_cast<TForteInt64*>(dataPtr));
            break;

          case CIEC_ANY::e_ULINT:
            DEVLOG_INFO("      Port ID: %d, ULINT Data Type, Value: %d\n",(*iter2)->PortID, *reinterpret_cast<TForteUInt64*>(dataPtr));
            break;          

          case CIEC_ANY::e_REAL:
            DEVLOG_INFO("      Port ID: %d, REAL data type. Value: %f\n", (*iter2)->PortID, *reinterpret_cast<TForteFloat*>(dataPtr));
            break;  

          case CIEC_ANY::e_LREAL:
            DEVLOG_INFO("      Port ID: %d, LREAL data type. Value: %Lf\n", (*iter2)->PortID, *reinterpret_cast<TForteDFloat*>(dataPtr));
            break;

          case CIEC_ANY::e_BYTE:
            DEVLOG_INFO("      Port ID: %d, BYTE data type. Value: %d\n", (*iter2)->PortID, *reinterpret_cast<TForteByte*>(dataPtr));
            break;

          case CIEC_ANY::e_WORD:
            DEVLOG_INFO("      Port ID: %d, WORD data type. Value: %d\n", (*iter2)->PortID, *reinterpret_cast<TForteWord*>(dataPtr));
            break;   

          case CIEC_ANY::e_DWORD:
            DEVLOG_INFO("      Port ID: %d, DWORD data type. Value: %d\n", (*iter2)->PortID, *reinterpret_cast<TForteDWord*>(dataPtr));
            break;

          case CIEC_ANY::e_LWORD:
            DEVLOG_INFO("      Port ID: %d, LWORD data type. Value: %d\n", (*iter2)->PortID, *reinterpret_cast<TForteLWord*>(dataPtr));
            break;                         


          default:
            // None support datatype: e_STRING, e_WSTRING, e_DATE, e_TIME_OF_DAY, e_DATE_AND_TIME, e_TIME
            DEVLOG_INFO("      Not yet support this data type.\n");
            break;    
        }

      }

  }

  // Print size of Central Data Matrix
  if(count == 0){
    DEVLOG_INFO("Central Data Matrix have no element.\n");
  }else{
    // DEVLOG_INFO("Size of Matrix: %d\n", count);
  }
}

void FORTE_Mixer_Main::printMessage(Messages & paMessage){
  
  for(int i = 0; i < MIXER_TOTAL_SLOTS; i++){
    DEVLOG_INFO("Sender ID: %d\n", paMessage[i].SenderID);
    for(CSinglyLinkedList<SPortData* > :: Iterator iter2 =  paMessage[i].DatawPort.begin(); 
      iter2 !=paMessage[i].DatawPort.end(); ++iter2){
        TForteUInt16 *dataPtr= (*iter2)->Value_Buffer;
        switch ((*iter2)->DataType){
          case CIEC_ANY::e_LREAL:
            DEVLOG_INFO("      Port ID: %d, LREAL. Data: %Lf\n", (*iter2)->PortID, *reinterpret_cast<TForteDFloat*>(dataPtr));
            break;

          default:
            DEVLOG_INFO("      Port ID: %d Data: %d\n", (*iter2)->PortID, *dataPtr);
            break;
        }
      } 
  }
  
}

#endif

/*************** End of Debug Logic Part  ****************/
void FORTE_Mixer_Main::executeEvent(int pa_nEIID) {

  switch(pa_nEIID) {
    case scm_nEventINITID:
      mixerInitialization(st_NodeID(), st_TotalNode());
      read_PortID(st_RD_OUT_ID(), ListReceivedPort);
      read_PortID(st_SD_IN_ID(), ListTransmitPort);
      sendOutputEvent(scm_nEventINITOID);

      #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
        DEVLOG_INFO("NodeID: %d\n", mNodeID);
        DEVLOG_INFO("TotalNode: %d\n" , mTotalNumberNodes);
        DEVLOG_INFO("Round Number: %d\n" , mRoundNumber);

        printCentralMatrix();
      #endif

      break;
    case scm_nEventROUND_STARTID:
      mRoundNumber++;
      m_RecvIdx = 0;
      m_TranIdx = 0;
      Receive_Transmit_Flag = transmitProbability();

      if(Receive_Transmit_Flag== true){
        // Perform Transmittion Task
        clearBuffer(m_TransBuffer, BUFFER_SIZE);
        clearMessage(Tx_Message);

        prepareTxMessage(Tx_Message);
        packingTx(Tx_Message, m_TransBuffer);

        #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
          printCentralMatrix();
          DEVLOG_INFO("------------------ Tx Message Print -----------------\n");
          printMessage(Tx_Message);
          DEVLOG_INFO("-----------------------------------------------------\n");
        #endif

      }else{
        // Perform Receive Task
        if(Buffer_NonZero_Check(m_RecvBuffer) == false){
          #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
            printCentralMatrix();
          #endif

          unpackingRx(Rx_Message, m_RecvBuffer);
          updateDataMatrix(Rx_Message);

          #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
            DEVLOG_INFO("------------------ Rx Message Print -----------------\n");
            printMessage(Rx_Message);
            DEVLOG_INFO("-----------------------------------------------------\n");
            printCentralMatrix(); 
          #endif

          clearBuffer(m_RecvBuffer, BUFFER_SIZE);
          clearMessage(Rx_Message);
        }

      }
      break;

    case scm_nEventTRANSMIT_TRGID:
      if (m_Trans_MessLength > BUFFER_SIZE){
        DEVLOG_ERROR("The length of Tx message larger than buffer limit: %d > %d. Please change BUFFER_SIZE parameter.\n", m_Trans_MessLength, BUFFER_SIZE);
      }

      if(Receive_Transmit_Flag== true){
        // Only transmit in Transmit round.
        if(m_TranIdx < m_Trans_MessLength){
          #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
            DEVLOG_INFO("Transmit Buffer: %d, Trs Idx: %d\n", m_TransBuffer[m_TranIdx], m_TranIdx);
          #endif

          st_SD_OUT().saveAssign(static_cast<CIEC_UDINT>(m_TransBuffer[m_TranIdx]));
          sendOutputEvent(scm_nEventESDID);
          m_TranIdx++;

        }else{
          m_TranIdx = 0;
        }
      }

      break;

    case scm_nEventSEND_RDID:
      setRDOutput(ListReceivedPort[0], st_RD_OUT_1());
      setRDOutput(ListReceivedPort[1], st_RD_OUT_2());
      setRDOutput(ListReceivedPort[2], st_RD_OUT_3());
      setRDOutput(ListReceivedPort[3], st_RD_OUT_4());
      setRDOutput(ListReceivedPort[4], st_RD_OUT_5());
      sendOutputEvent(scm_nEventERDID);
      break;

    case scm_nEventREQ_RDID:
      if(Receive_Transmit_Flag== false){
        // Only receive in receive round.
        m_RecvBuffer[m_RecvIdx] = static_cast<TForteUInt32>(st_RD_IN());
        m_RecvIdx++;

        #if(MIXER_DEBUG_MODE == MIXER_DEBUG_ON)
          DEVLOG_INFO("Received Buffer: %d, Rcv Idx: %d\n", m_RecvBuffer[m_RecvIdx-1], m_RecvIdx-1);
        #endif
      }
      break;

    case scm_nEventREQ1ID:
      applicationReceive(ListTransmitPort[0], st_SD_IN_1());
      break;

    case scm_nEventREQ2ID:
      applicationReceive(ListTransmitPort[1], st_SD_IN_2());
      break;

    case scm_nEventREQ3ID:
      applicationReceive(ListTransmitPort[2], st_SD_IN_3());
      break;

    case scm_nEventREQ4ID:
      applicationReceive(ListTransmitPort[3], st_SD_IN_4());
      break;

    case scm_nEventREQ5ID:
      applicationReceive(ListTransmitPort[4], st_SD_IN_5());
      break;

  }
}
