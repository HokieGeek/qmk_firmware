#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

#if !defined(USE_SERIAL) && !defined(USE_I2C)
#define USE_SERIAL
#endif

#define PERMISSIVE_HOLD

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 150

#ifdef TAPPING_TOGGLE
#undef TAPPING_TOGGLE
#endif //TAPPING_TOGGLE
#define TAPPING_TOGGLE 3

#endif
