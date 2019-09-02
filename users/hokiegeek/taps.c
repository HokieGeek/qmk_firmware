#include "taps.h"

#include <mousekey.h>
#include "quantum.h"

inline void mousekey_tap(uint8_t code) {
    mousekey_on(code);
    mousekey_send();
    mousekey_off(code);
    mousekey_send();
}

inline void key_tap(uint8_t code) {
    register_code(code);
    unregister_code(code);
}

inline void tap_mod_key(uint8_t mod, uint8_t code) {
    register_code(mod);
    key_tap(code);
    unregister_code(mod);
}

inline void tap_ctrl_key(uint8_t code) {
    tap_mod_key(KC_LCTL, code);
}

inline void tap_ctltab() {
    tap_mod_key(KC_LCTL, KC_TAB);
}

inline void tap_gui_shift_enter() {
    register_code(KC_LGUI);
    register_code(KC_LSHIFT);
    key_tap(KC_ENTER);
    unregister_code(KC_LSHIFT);
    unregister_code(KC_LGUI);
}
