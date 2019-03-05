#ifndef USERSPACE_ENCODER
#define USERSPACE_ENCODER

#include "quantum.h"

#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

typedef struct {
    bool scrollVertical;
    bool monBrightness;
    bool backlightBrightness;
    bool defaultVolume;
} encoder_options;

encoder_options enc_opts;

#define TD_ENCODER_ENTRY [td_encoder] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, encoder_td_actions, NULL, 300)

#define KC_ENC TD(td_encoder)

void hgencoder_init(void);

#endif // USERSPACE_ENCODER
