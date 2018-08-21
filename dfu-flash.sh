#!/bin/sh

make nyquist/rev2:ansibles:production

sudo avrdude -c usbtiny -p m32u4 -P usb \
        -U flash:w:nyquist_rev2_ansibles_production.hex:a \
        -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m
