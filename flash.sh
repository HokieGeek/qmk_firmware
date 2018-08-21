#!/bin/bash

[[ $1 =~ "hick" ]] && {
    make nyquist/rev2:hickory-n-dickory:avrdude
} || {
    make nyquist/rev2:ansibles:dfu
}
