
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
Below is the architecture for config communication. The FB square block represents all application Function Blocks which need to send or receive data via networks. The sending data needs to be sent to MERGE FB before being sent to MIXER. In the opposite direction, the received data needs to be sent to UNMERGE FB before being sent to application Function Blocks.

![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/811f43d0-402c-4a60-8f77-1d9dd5e092a1)

The graph below describes how the system over time.
![image](https://github.com/TuyetHan/DistributedWirelessControl/assets/44611883/f277dbc5-16c4-4cfc-b765-726aca59e442)

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





