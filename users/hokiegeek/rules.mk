EXTRAFLAGS += -flto

SRC += hokiegeek.c taps.c latin.c

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

ifndef ENCODER_ENABLE
	ENCODER_ENABLE = no
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += td_extras.c tmux.c skdm.c
endif
