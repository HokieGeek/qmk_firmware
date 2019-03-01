#!/bin/sh

# make keebio/nyquist/rev2:ansibles:production
make keebio/levinson/rev2:philotes:production

sudo avrdude -c usbtiny -p m32u4 -P usb \
        -U flash:w:keebio_levinson_rev2_philotes_production.hex:a \
        -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m
