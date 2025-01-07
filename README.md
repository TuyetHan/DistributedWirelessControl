
# [MIXER](https://dl.acm.org/doi/pdf/10.1145/3274783.3274849) in [4DIAC](https://eclipse.dev/4diac/index.php)

The Project Objective is to implement the basic features of MIXER - a new communication protocol - into 4DIAC - an open-source infrastructure based on the IEC 61499 standard.

According to the original paper of MIXER, the most important problems that need to be tackled for many-to-all communication are:

- When the node should be listened/transmitted?
- What the node should transmit?
- Ensure synchronous transmission without a global clock.
- Efficient runtime operation.

This project will aim to solve all the problems above as well as some additional features which will increase the performance of MIXER.

## Features
Basic:

- Semi-coordinated Transmissions
- Explicit Innovation Forwarding


Advance: 
- Improving Startup: Adapted Coordination.
- Improving Completion: Active Requests
- Improving Finalization: Smart Shutdown.

## General Architecture
Below is the architecture for config communication. The FB square block represents all application Function Blocks which need to send or receive data via networks. The sending data can connect to SD_IN_x Port on Mixer_Main and receiving data can be obtained via RD_OUT_x Port on Mixer_Main. (Note: x from 1 to 5) 

![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/4a6546ae-190d-4781-8e36-370d99f4de6b)

## Mixer User Guideline
![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/a60e55ba-31e5-4113-b1e4-5ec3e8a4db06)

Application Data Connection: Use to receive and transmit data from and to the application function block. Application FBs are FBs not responsible for Mixer communication but rather FBs used for running user-defined applications.
- SD_IN_1 to SD_IN_5: Send Data Input.
- REQ1 to REQ5: Event for SD_IN_1 to SD_IN_5.
- RD_OUT_1 to RD_OUT_5: Receive Data Output.
- ERD: Event for RD_OUT_1 to RD_OUT_5.

Time-control input (event): ROUND_START, TRANSMIT_TRG, SEND_RD. Those event inputs will control the timing of MIXER.
- ROUND_START: used to start a new "round" or "time slot" of MIXER. This input shall be controlled by cyclic FBs (inside Mixer_Timer) and can be config via ROUND_CYC of Mixer_Timer.
- SEND_RD: used to trigger ERD and send data inside to RD_OUT_x. This input also could be controlled by cyclic FBs (inside Mixer_TImer and can be config via RD_TRG_CYCof Mixer_Timer.
- TRANSMIT_TRG: used to send data to PUBLISH and send to the network. Note: ESD output event of Mixer_Main must connect to ESD input event of Mixer_Timer. This parameter are advised to configure around 40% to 80% of ROUND_CYC.
    
Transmission and Reception config:
- Connection to PUBLISH_1: SD_OUT -> SD_1, ESD -> REQ, INITO -> INIT (optional).
- Connection to SUBCRIBE_1: RD_1 -> RD_IN, IND ->REG_RD, INITO -> INIT (optional.
    
Other configuration:
- ID of SUBCRIBE_1 and PUBLISH_1 shall be the same for all "devices" within a system. For example: "225.0.0.1:61499"
- QI of SUBCRIBE_1 and PUBLISH_1 shall be set to 1.
- ROUND_CYC and TX_DELAY_TRG also shall be the same for all "devices" within a system. RX_TRG_CYC; however, can be varied as it does not affect MIXER timing and operation.
- NodeID of Mixer_Main: each device shall have a unique ID within the system.
- Total Node: shall be the same for all "devices". This parameter gives information on deciding whether this round is transmitted or received.
- RD_OUT_ID, SD_IN_ID: Port ID of RD_OUT_x and SD_IN_x. Shall be unique within the whole system. Each port ID shall be separated by ",". There is no limit on how many ports shall be config; however, only 5 first numbers will be considered inside Mixer cooperation and non-configuration ports will have ID = 0.

The graph below describes how the system over time.
![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/f277dbc5-16c4-4cfc-b765-726aca59e442)

## Data Structure
- Buffer Structure:
![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/66c2e2fb-dd85-4086-8c3e-c29d768fc135)

- Main Central Data Matrix:
![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/2d1d4491-c9c2-4edc-ab6f-a1f0fafa3247)

- Tx and Rx Message: Same with Main Central Data Matrix but only have 4 row, and without FLAGs.
  
## Running Tests

This project will be tested on Beagle Bone Black Industrial. The following steps shall be taken to prepare BBB.

- Download the Software Image and flash it on the SD card. https://spotpear.com/index/study/detail/id/734.html
- Connect BBB to PC and control it:
    
    For Windows: Download PUTTY and WinSCP to control and transfer source code. Read this documentation for details: https://eclipse.dev/4diac/en_help.php?helppage=html/examples/bbbTraficControl.html

    For Linux: Can be controlled and transfer source code directly via terminal.

  Note: 192.168.7.2 is BBB's default address.
    Debian is BBB Image which can be different for each BBB.
    The password of BBB: temppwd.
```bash
  #Connect to Beagle Bone
  ssh debian@192.168.7.2

  #Copy Source File to Beagle Bone
  scp -r /source_code/directory debian@192.168.7.2:/target/directory

```



- Set up wifi for BBB: https://www.fis.gatech.edu/how-to-configure-bbw-wifi/

- Build FORTE for BBB:

     Follow this guideline: https://eclipse.dev/4diac/en_help.php?helppage=html/installation/raspi.html
    
     Note: The Linaro toolchain for Linux should be downloaded at https://releases.linaro.org/components/toolchain/binaries/latest-7/arm-linux-gnueabihf/
          version "gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf" . For Windows, version raspberry-gcc8.3.0.exe will work.

- Run FORTE on BBB:

```bash
  cd /Source_File/directory
  chmode +x forte
  ./forte
```
- Find the address that the router assigned to BBB: ifconfig. This address shall be configured in System Configuration before testing. This address will be changed every time BBB restart or power ON; therefore, need to be rechecked every time start testing.
  ![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/7d7ba43e-c758-47a7-bfed-e8f567be06bc)
  ![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/142552ae-e788-45b4-96c6-764987ba773f)

## Acknowledgements

 - Change Beagle Bone Default Address:
 ```bash
  cd /etc/default/
  sudo nano bb-boot

  - Change USB0 Address according to your need
```

 - Error when connect 2 BBBs having same address:
 ```bash
  ssh-keygen -f "/home/.ssh/known_host" -R "192.168.7.2"

  - Note: Need to find ssh location in your computer and replace accordingly, also "192.168.7.2" also shall be replaced by BBB default address (if you already changed it)
```

Thanks to Professor [Dominik Baumann](https://baumanndominik.github.io/) for supporting me in this project





