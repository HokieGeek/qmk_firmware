#ifndef USERSPACE_SKDM
#define USERSPACE_SKDM

#include "quantum.h"

void td_skdm1_finished(tap_dance_state_t *state, void *user_data);
void td_skdm1_reset(tap_dance_state_t *state, void *user_data);
void td_skdm2_finished(tap_dance_state_t *state, void *user_data);
void td_skdm2_reset(tap_dance_state_t *state, void *user_data);

#define TD_SKDM1_ENTRY [td_skdm1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_skdm1_finished, td_skdm1_reset)
#define TD_SKDM2_ENTRY [td_skdm2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_skdm2_finished, td_skdm2_reset)
#define KC_SKDM1 TD(td_skdm1)
#define KC_SKDM2 TD(td_skdm2)

#endif // USERSPACE_SKDM
