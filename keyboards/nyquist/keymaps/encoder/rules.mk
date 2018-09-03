USER_NAME := hokiegeek

BOOTLOADER = qmk-dfu

TAP_DANCE_ENABLE = yes

MOUSEKEY_ENABLE = yes

CONSOLE_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
