EXTRAFLAGS += -flto

SRC += hokiegeek.c os.c taps.c latin.c vscode.c

## Enable options common to all of my boards
BOOTLOADER = qmk-dfu
SPLIT_KEYBOARD = yes

ifndef MOUSEKEY_ENABLE
	MOUSEKEY_ENABLE = yes
endif

ifndef TAP_DANCE_ENABLE
	TAP_DANCE_ENABLE = yes
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += td_extras.c tmux.c skdm.c
endif

ifndef ENCODER_ENABLE
	ENCODER_ENABLE = yes
endif
ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += hgencoder.c
endif
ifndef COMBO_ENABLE
	COMBO_ENABLE = no
endif
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combos.c
endif

## Disable all the things I usually want off
ifndef BOOTMAGIC_ENABLE
	BOOTMAGIC_ENABLE = no
endif

ifndef COMMAND_ENABLE
	COMMAND_ENABLE = no
endif

ifndef NKRO_ENABLE
	NKRO_ENABLE = yes
endif

ifndef BACKLIGHT_ENABLE
	BACKLIGHT_ENABLE = no
else
	SLEEP_LED_ENABLE = no
endif

ifndef RGBLIGHT_ENABLE
	RGBLIGHT_ENABLE = no
endif

ifndef AUDIO_ENABLE
	MIDI_ENABLE = no
	AUDIO_ENABLE = no
	FAUXCLICKY_ENABLE = no
endif
