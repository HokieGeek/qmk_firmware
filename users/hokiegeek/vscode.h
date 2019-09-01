#ifndef USERSPACE_VSCODE
#define USERSPACE_VSCODE

#include "quantum.h"

/*
 * |CMDPLT|XPLORE| TERM |      |      |      | ED_1 | ED_2 | ED_3 |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |RENAME|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 */
#define _____VSCODE_R1_____  C(S(KC_P)), C(S(KC_E)), C(KC_GRAVE), _______, _______, _______,    C(KC_1), C(KC_2), C(KC_3), _______, _______, _______
#define _____VSCODE_R2_____  _______, KC_F2, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
#define _____VSCODE_R3_____  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______

bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE_VSCODE
