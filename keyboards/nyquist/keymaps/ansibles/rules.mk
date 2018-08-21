USER_NAME := hokiegeek

BOOTLOADER = qmk-dfu

SWAP_HANDS_ENABLE = yes
# RGBLIGHT_ENABLE = yes
MOUSEKEY_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
