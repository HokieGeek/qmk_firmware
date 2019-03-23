USER_NAME := hokiegeek

BOOTLOADER = qmk-dfu

MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
ENCODER_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
