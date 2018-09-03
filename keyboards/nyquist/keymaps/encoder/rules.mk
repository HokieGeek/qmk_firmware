#USER_NAME := hokiegeek

BOOTLOADER = qmk-dfu

# MOUSEKEY_ENABLE = yes

CONSOLE_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
