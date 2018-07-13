#!/bin/sh
brew tap osx-cross/avr
brew tap PX4/homebrew-px4
brew update
brew install avr-gcc@7
brew install dfu-programmer
brew install gcc-arm-none-eabi
brew install avrdude
