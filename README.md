# RV-Debugger-ESP32-JTAG

This repository provides resources and instructions for using the **RV-Sipeed-Debugger-Plus** to debug the **ESP32** via JTAG. It covers setup, configuration, and troubleshooting.  
Tested and confirmed working on **Windows 11**. 

---

## Hardware Requirements
- **RV-Sipeed-Debugger-Plus** [Link product](https://github.com/sipeed/RV-Debugger-BL702)
- **ESP32 WROVER IB** 16MB flash, 536KB SRAM

### JTAG Connection Details
| Signal | Wrover-IB GPIO Pin | RV-Sipeed-Debugger-Plus Pin | Description            |
|--------|----------------|----------------------------|------------------------|
| TDI    | GPIO12         | TDI                       | Test Data In           |
| TDO    | GPIO13         | TCK                       | Test Clock             |
| TCK    | GPIO14         | TMS                       | Test Mode Select       |
| TMS    | GPIO15         | TD0                       | Test Data Out          |
| GND    | GND            | GND                       | Ground connection      |

---

## Software Requirements
- **Open On-Chip Debugger**: v0.11.0-esp32-20220706  
- **PlatformIO Core**: version 6.1.16
- **Visual Studio Code** : 1.96.2 fabdb6a30b49f79a7aba0f2ad9df9b399473380f x64

---

## Setup Instructions

### Step 1: Clone the Source Code
Clone this repository:  
```bash
git clone https://github.com/nub-atur/rv-debugger-esp32-jtag.git
```
### Step 2: Open **Git Bash** and nagavite to the clone and run
```bash
chmod +x ./setup.sh
./setup.sh
```
### If you prefer manual configuration, perform the following steps:
Copy **sipeed.cfg** to:
$HOME\.platformio\packages\tool-openocd-esp32\share\openocd\scripts\interface\ftdi
Copy **esp-wrover-kit-IB.json** to:
$HOME\.platformio\platforms\espressif32\boards

---

## Usage
### Step 1: Open the Repository in Visual Studio Code
- Open the project repository in **PlatformIO** on **Visual Studio Code**.

### Step 2: Run OpenOCD Command
- Open a terminal (e.g., Windows PowerShell or Git Bash)
- Navigate to the OpenOCD directory:
```bash
cd $HOME\.platformio\packages\tool-openocd-esp32
``` 
- Run the following command:
```bash
./bin/openocd -s share/openocd/scripts -f interface/ftdi/sipeed.cfg -c "set ESP32_FLASH_VOLTAGE 3.3" -f target/esp32.cfg
```
### Step 3: Switch back to Visual Studio Code.
- Start debugging your ESP32 project by clicking the Start Debugging button (or press F5).

---


## Notes
- The **.platformio** folder is typically installed in `C:\Users\anhky.dang` (in my case). Ensure this path is correct for your system.
- Verify that the paths in your configuration files match your PlatformIO installation directory.
- After making changes, restart your IDE to apply the updates.
- Double-check that your configuration files are properly formatted and compatible with OpenOCD and your ESP32 setup.
- Ensure all hardware connections are secure to avoid any debugging issues.
- The **GND** connection is essential for proper signal integrity and should always be connected.
