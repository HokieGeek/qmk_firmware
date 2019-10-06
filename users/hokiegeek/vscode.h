#ifndef USERSPACE_VSCODE
#define USERSPACE_VSCODE

#include "quantum.h"
#include "td_extras.h"

#define _VSCODE 8
#define KC_VSCODE MO(_VSCODE)

/*
 * |      |      |      |      |      |      |      | ED_1 |XPLORE| FIND | SCM  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |PKDEFS|PKSYMS|G2SYM |PALETT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |TGLTST| TERM |RENAME|PROBS |      |      |
 */
#define _____VSCODE_R1_____  _______, _______, _______, _______, _______, _______,    _______,      VSC_ED_1,    VSC_XPLORE,  VSC_FIND,   VSC_SCM,    _______
#define _____VSCODE_R2_____  _______, _______, _______, _______, _______, _______,    _______,      VSC_PKDEFS,  VSC_PKSYMS,  VSC_G2SYM,  VSC_PALETT,  _______
#define _____VSCODE_R3_____  _______, _______, _______, _______, _______, _______,    VSC_TGL_GTST, VSC_TERM,    VSC_RENAME,  VSC_PROBS,  _______,  _______

void vscode_layer_on_hold(td_stage stage);
bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE_VSCODE
