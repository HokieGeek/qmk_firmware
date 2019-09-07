#!/bin/sh

make keebio/levinson/rev2:philotes:production || exit 1

sudo avrdude -c usbtiny -p m32u4 -P usb \
        -U flash:w:keebio_levinson_rev2_philotes_production.hex:a \
        -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m

# make keebio/nyquist/rev2:hickory-n-dickory:production || exit 1
# 
# sudo avrdude -c usbtiny -p m32u4 -P usb \
#         -U flash:w:keebio_nyquist_rev2_hickory-n-dickory_production.hex:a \
#         -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m
