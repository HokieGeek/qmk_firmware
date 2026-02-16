#include "os.h"

#include "hg_keycodes.h"

uint16_t TARGET_OS = OS_NIX;

void setTargetOS(uint16_t os) {
    TARGET_OS = os;
}

uint16_t getTargetOS() {
    return TARGET_OS;
}
