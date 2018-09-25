#ifndef USERSPACE_TD_EXTRAS
#define USERSPACE_TD_EXTRAS

#include "quantum.h"

typedef enum {
    OTHER = 0,
    SINGLE,
    DOUBLE,
    TRIPLE,
    SINGLE_HOLD,
    DOUBLE_HOLD,
    TRIPLE_HOLD
} td_state;

typedef enum {
    TD_ON_EACH_TAP = 0,
    TD_FINISHED,
    TD_RESET
} td_stage;

typedef struct {
    void (*f1)(td_stage);
    void (*f2)(td_stage);
} td_funcs_t;

#define ACTION_TAP_DANCE_TAP_HOLD(f1, f2) { \
    .fn = { NULL, td_tap_hold_funcs_finished, td_tap_hold_funcs_reset }, \
    .user_data = (void *)&((td_funcs_t) { f1, f2 }),  \
  }

#define ACTION_TAP_DANCE_DOUBLE_FUNCS(f1, f2) { \
    .fn = { NULL, td_single_double_funcs, NULL }, \
    .user_data = (void *)&((td_funcs_t) { f1, f2 }),  \
  }
// .custom_tapping_term = 

td_state process_td_state(qk_tap_dance_state_t *state, void *user_data);

void td_tap_hold_funcs_finished(qk_tap_dance_state_t *state, void *user_data);
void td_tap_hold_funcs_reset(qk_tap_dance_state_t *state, void *user_data);
void td_single_double_funcs(qk_tap_dance_state_t *state, void *user_data);

void td_key_mod(td_stage, uint16_t);
void td_key(td_stage, uint16_t);

void td_shift(td_stage);

#endif // USERSPACE_TD_EXTRAS
