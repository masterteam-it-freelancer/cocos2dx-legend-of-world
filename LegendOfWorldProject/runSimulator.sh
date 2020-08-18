#!/bin/bash -e
echo Runing Devices Script
#echo "$(PWD)"
HOME_CURRENT=$(PWD)
HOME_EMULATOR=/Users/imac_vtca/Library/Android/sdk/emulator
cd $HOME_EMULATOR
echo "List devices: "
./emulator -list-avds
if [ "$#" -ne 0 ]
    then
        echo "Please choose your device " 
    fi
echo "Input name of device: "
read -r name
./emulator -avd $name &
cd $HOME_CURRENT
