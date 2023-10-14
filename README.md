
# MIXER in 4DIAC

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


## Running Tests

This project will be tested on Beagle Bone Black Industrial. The following steps shall be taken to prepare BBB.

- Download the Software Image and flash it on the SD card. https://spotpear.com/index/study/detail/id/734.html
- Connect BBB to PC and control it:
    
    For Windows: Download PUTTY and WinSCP to control and transfer source code. Read this documentation for details: https://eclipse.dev/4diac/en_help.php?helppage=html/examples/bbbTraficControl.html

    For Linux: Can be controlled and transfer source code directly via terminal.
```bash
  #Connect to Beagle Bone
  ssh debian@192.168.7.2

  #Copy Source File to Beagle Bone
  scp -r /source_code/directory debian@192.168.7.2:/target/directory

```
Note: 192.168.7.2 is BBB's default address.
Debian is BBB Image which can be different for each BBB.
The password of BBB: temppwd.


- Set up wifi for BBB: https://www.fis.gatech.edu/how-to-configure-bbw-wifi/


- Run FORTE on BBB:

```bash
  cd /Source_File/directory
  chmode +x forte
  ./forte
```

## Appendix

MIXER : Efficient Many-to-All Broadcast in Dynamic Wireless
Mesh Networks - https://dl.acm.org/doi/pdf/10.1145/3274783.3274849

4DIAC - https://eclipse.dev/4diac/index.php




