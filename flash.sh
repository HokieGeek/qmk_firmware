#!/bin/bash

[[ $1 =~ "hick" ]] && kbd="hickory-n-dickory" || kbd="ansibles"

make nyquist/rev2:${kbd:-"ansibles"}:avrdude
