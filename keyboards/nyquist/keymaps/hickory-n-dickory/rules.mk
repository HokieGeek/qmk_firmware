BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
COMMAND_ENABLE = no

NKRO_ENABLE = yes

SWAP_HANDS_ENABLE = yes
# TAP_DANCE_ENABLE = yes

# SRC += tapdance_accents.c

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
