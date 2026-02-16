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

// see: quantum/process_keycode/process_tap_dance.h
#define ACTION_TAP_DANCE_TAP_HOLD(fn_tap, fn_hold) { \
    .fn = { NULL, td_tap_hold_funcs_finished, td_tap_hold_funcs_reset }, \
    .user_data = (void *)&((td_funcs_t) { fn_tap, fn_hold }),  \
  }

#define ACTION_TAP_DANCE_TAPKEY_HOLDLAYER(name) \
    ACTION_TAP_DANCE_TAP_HOLD(td_tap_##name, td_layer_on_hold_##name)

#define ACTION_TAP_DANCE_TAPKEY_HOLDLAYER_FUNCS(name, key, layer) \
void td_tap_##name(td_stage stage) { \
    tap_code16(key); \
} \
void td_layer_on_hold_##name(td_stage stage) { \
    td_layer_on_hold(stage, layer); \
}

#define ACTION_TAP_DANCE_DOUBLE_FUNCS(fn_single, fn_double) { \
    .fn = { NULL, td_single_double_funcs, NULL }, \
    .user_data = (void *)&((td_funcs_t) { fn_single, fn_double }),  \
  }
// .state = 
// .custom_tapping_term = 

td_state process_td_state(tap_dance_state_t *state, void *user_data);

void td_tap_hold_funcs_finished(tap_dance_state_t *state, void *user_data);
void td_tap_hold_funcs_reset(tap_dance_state_t *state, void *user_data);
void td_single_double_funcs(tap_dance_state_t *state, void *user_data);

void td_key_mod(td_stage, uint16_t);
void td_key(td_stage, uint16_t);
void td_layer_on_hold(td_stage stage, uint16_t layer);

#endif // USERSPACE_TD_EXTRAS
