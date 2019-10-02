#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

#define NO_ACTION_ONESHOT

#if !defined(USE_SERIAL) && !defined(USE_I2C)
#define USE_SERIAL
#endif // !USE_SERIAL && !USE_I2C

#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 180

#ifdef COMBO_ENABLE
#define COMBO_TERM 30
#endif // COMBO_ENABLE

#ifdef TAPPING_TOGGLE
#undef TAPPING_TOGGLE
#endif //TAPPING_TOGGLE
#define TAPPING_TOGGLE 3

#if !defined(MASTER_LEFT) && !defined(MASTER_RIGHT) && !defined(EE_HANDS)
#undef MASTER_LEFT
#define EE_HANDS
#endif

#endif
