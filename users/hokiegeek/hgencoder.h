#pragma once

#include "quantum.h"

#ifndef ENCODER_RESOLUTION
#   define ENCODER_RESOLUTION 4
#endif

typedef struct {
    bool scrollVertical;
    bool monBrightness;
    bool backlightBrightness;
    bool defaultVolume;
} encoder_options;

/*
encoder_options enc_opts = {
    .scrollVertical = true,
    .monBrightness = true,
    .backlightBrightness = true,
    .defaultVolume = true
};
*/

#define TD_ENCODER_ENTRY [td_encoder] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, encoder_td_actions, NULL)

#define KC_ENC TD(td_encoder)

//void hgencoder_init(void);
