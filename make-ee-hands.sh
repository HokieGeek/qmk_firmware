#!/bin/bash

flash_eep() {
    eepfile=$1

    local USB=""

    printf "Detecting  port, reset your controller now."
    ls /dev/tty* > /tmp/a1
    while [ -z $USB ]; do
        sleep 0.5
        printf "."
        ls /dev/tty* > /tmp/a2
        USB=`comm -13 /tmp/a1 /tmp/a2 | grep  -o '/dev/tty.*'`
        mv /tmp/a2 /tmp/a1
    done
    echo ""
    echo "Detected controller on  port at $USB. Flashing ${eepfile}"
    sleep 1
    set -x
    sudo avrdude -p atmega32u4 -P $USB -c avr109 -U eeprom:w:${eepfile} || exit 1
    set +x
}

read -p "Ensure the left side is plugged in..."
flash_eep ./keyboards/nyquist/eeprom-lefthand.eep || exit 1
read -p "Switch to the right side..."
flash_eep ./keyboards/nyquist/eeprom-righthand.eep || exit 1
