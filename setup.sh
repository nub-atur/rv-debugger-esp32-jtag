#!/bin/bash

# Paths to the source files
SOURCE_FILE_SIPEED="sipeed.cfg"
SOURCE_FILE_BOARD="esp-wrover-kit-IB.json"

# Paths to the target directories
TARGET_DIR_SIPEED="$HOME/.platformio/packages/tool-openocd-esp32/share/openocd/scripts/interface/ftdi"
TARGET_DIR_BOARD="$HOME/.platformio/platforms/espressif32/boards"

# Function to copy a file to a directory
copy_file() {
    local source_file=$1
    local target_dir=$2

    # Check if the source file exists
    if [ ! -f "$source_file" ]; then
        echo "Error: Source file $source_file does not exist."
        return 1
    fi

    # Check if the target directory exists
    if [ -d "$target_dir" ]; then
        echo "Target directory $target_dir exists. Proceeding with file copy..."
    else
        echo "Target directory $target_dir does not exist. Creating directory..."
        mkdir -p "$target_dir"
    fi

    # Copy the file
    cp "$source_file" "$target_dir"
    echo "File $source_file has been copied to $target_dir."
}

# Copy the files to their respective directories
copy_file "$SOURCE_FILE_SIPEED" "$TARGET_DIR_SIPEED"
copy_file "$SOURCE_FILE_BOARD" "$TARGET_DIR_BOARD"




# ### Step 1: Add Sipeed Configuration File
# cp  .platformio\packages\tool-openocd-esp32\share\openocd\scripts\interface\ftdi

# ### Step 2: Add ESP-WROVER-KIT-IB Board File
# .platformio\platforms\espressif32\boards

# ### Step 3: Clone the Source Code
# git clone https://github.com/nub-atur/rv-debugger-esp32-jtag.git



#  chmod +x ./setup.sh