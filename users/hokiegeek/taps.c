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

inline void tap_ctltab() {
    register_code(KC_LCTL);
    register_code(KC_TAB);
    unregister_code(KC_TAB);
    unregister_code(KC_LCTL);
}

/*
void tap_ctltab_td(td_stage stage) {
    tap_ctltab();
}
*/
