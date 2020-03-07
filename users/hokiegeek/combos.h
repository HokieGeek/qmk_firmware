#pragma once

#include "quantum.h"

#define COMBO_CHORD2(k1, k2) const uint16_t PROGMEM chord2_##k1##k2[] = {KC_##k1, KC_##k2, COMBO_END}
#define COMBO_CHORD3(k1, k2, k3) const uint16_t PROGMEM chord3_##k1##k2##k3[] = {KC_##k1, KC_##k2, KC_##k3, COMBO_END}
#define COMBO_CHORD4(k1, k2, k3, k4) const uint16_t PROGMEM chord4_##k1##k2##k3##k4[] = {KC_##k1, KC_##k2, KC_##k3, KC_##k4, COMBO_END}
