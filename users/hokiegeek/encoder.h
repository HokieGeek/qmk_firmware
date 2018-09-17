#ifndef USERSPACE_ENCODER
#define USERSPACE_ENCODER

#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

#define ENC_A PF4
#define ENC_B PB2

enum { td_encoder = 0 };

#define ENCODER_TD_ENTRY [td_encoder] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, encoder_td_actions, NULL, 400)

#define KC_ENC TD(td_encoder)

#endif // USERSPACE_ENCODER
