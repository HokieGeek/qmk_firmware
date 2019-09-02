#ifndef USERSPACE_VSCODE
#define USERSPACE_VSCODE

#include "quantum.h"
#include "td_extras.h"

#define _VSCODE 8
#define KC_VSCODE MO(_VSCODE)

/*
 * |      |      |      |      |      |      |      |      |PROBS | SCM  | FIND | TERM |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |PKDEFS|PKSYMS|G2SYM |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |RENAME|PALETT|XPLORE| ED_1 |
 */
#define _____VSCODE_R1_____  _______, _______, _______, _______, _______, _______,    _______, _______, C(S(KC_M)),  VSC_SCM,      C(S(KC_F)), C(KC_GRAVE)
#define _____VSCODE_R2_____  _______, _______, _______, _______, _______, _______,    _______, _______, _______,     C(S(KC_F10)), S(KC_F12),  C(S(KC_O))
#define _____VSCODE_R3_____  _______, _______, _______, _______, _______, _______,    _______, _______, KC_F2,       C(KC_P),      C(S(KC_E)), C(KC_1)

void vscode_layer_on_hold(td_stage stage);
bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE_VSCODE
