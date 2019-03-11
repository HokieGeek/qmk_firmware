#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

// #undef MASTER_LEFT
// #define MASTER_RIGHT

#ifdef MASTER_LEFT
#undef TMUX_ENTRY_TAPPING_TERM
#define TMUX_ENTRY_TAPPING_TERM 200
#endif

#define ACCENTS_LINUX

#undef RGBLED_NUM
#define RGBLED_NUM 20

#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { F4 }

#endif
