#include "os.h"

#include "keycodes.h"

uint16_t TARGET_OS = OS_NIX;

void setTargetOS(uint16_t os) {
    TARGET_OS = os;
}

uint16_t getTargetOS() {
    return TARGET_OS;
}

bool os_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // OS
        case KC_OS_NIX:
            if (record->event.pressed) {
                setTargetOS(OS_NIX);
            }
            return false;
            break;
        case KC_OS_MAC:
            if (record->event.pressed) {
                setTargetOS(OS_MAC);
            }
            return false;
            break;
        case KC_OS_WIN:
            if (record->event.pressed) {
                setTargetOS(OS_WIN);
            }
            return false;
            break;
    }
    return true;
}

