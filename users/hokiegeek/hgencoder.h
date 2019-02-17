#ifndef USERSPACE_ENCODER
#define USERSPACE_ENCODER

#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

#define ENC_A PF4
#define ENC_B PB2
#define ENCODERS_PAD_A { PF4 }
#define ENCODERS_PAD_B { PB2 }

typedef struct {
    bool scrollVertical;
    bool monBrightness;
    bool backlightBrightness;
    bool defaultVolume;
} encoder_options;

#define TD_ENCODER_ENTRY [td_encoder] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, encoder_td_actions, NULL, 300)

#define KC_ENC TD(td_encoder)

#endif // USERSPACE_ENCODER
