USER_NAME := hokiegeek

BOOTLOADER = qmk-dfu

TAP_DANCE_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
