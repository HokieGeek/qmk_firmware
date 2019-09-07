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
#define _____VSCODE_R1_____  _______, _______, _______, _______, _______, _______,    _______, _______, VSC_PROBS,   VSC_SCM,     VSC_FIND,    VSC_TERM
#define _____VSCODE_R2_____  _______, _______, _______, _______, _______, _______,    _______, _______, _______,     VSC_PKDEFS,  VSC_PKSYMS,  VSC_G2SYM
#define _____VSCODE_R3_____  _______, _______, _______, _______, _______, _______,    _______, _______, VSC_RENAME,  VSC_PALETT,  VSC_XPLORE,  VSC_ED_1

void vscode_layer_on_hold(td_stage stage);
bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE_VSCODE
