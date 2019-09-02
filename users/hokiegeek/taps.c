#include "taps.h"

#include <mousekey.h>
#include "quantum.h"

inline void tap_mousekey(uint8_t code) {
    mousekey_on(code);
    mousekey_send();
    mousekey_off(code);
    mousekey_send();
}

inline void tap_key(uint8_t code) {
    register_code(code);
    unregister_code(code);
}

inline void tap_mod_key(uint8_t mod, uint8_t key) {
    register_code(mod);
    tap_key(key);
    unregister_code(mod);
}

inline void tap_mods_key(uint8_t* mods, uint8_t key) {
    for(int i = 1; i <= mods[0]; i++) {
        register_code(mods[i]);
    }

    tap_key(key);

    for(int i = mods[0]; i >= 1; i--) {
        unregister_code(mods[i]);
    }
}
