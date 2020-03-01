#!/bin/sh

keeb=$1

make ${keeb}:production || exit 1

sudo avrdude -c usbtiny -p m32u4 -P usb \
        -U flash:w:$(echo ${keeb} | tr '/:' '_')_production.hex:a \
        -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m
        # -U eeprom:w:"quantum/split_common/eeprom-righthand.eep":a
