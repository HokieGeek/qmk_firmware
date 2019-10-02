# HokieGeek

## Features

### Accents
Spanish accents and special symbols are supported with a one-tap key called `KC_LATIN` or tap-dance combo with Shift using keycode `SFT_LAT`:

Mapping of keycode with symbol
| keycode | accent |
|---|---|
| `KC_A`    | á |
| `KC_E`    | é |
| `KC_I`    | í |
| `KC_O`    | ó |
| `KC_U`    | ú |
| `KC_N`    | ň |
| `KC_Q`, `KC_1`, `KC_EXCLAIM`, `KC_EXLM` | ¡ |
| `KC_SLASH`, `KC_SLSH`, `KC_QUESTION`, `KC_QUES` | ¿ |

The symbols will be entered as linux unicode values unless you set `setTargetOS(OS_MAC)` which will perform a MacOS key combo to get the symbols.

### TMUX
The default prefix is set as `X_A` but can be overridden by setting the alternate value as the `TMUX_PREFIX` define.

#### Keycodes
The following keycodes allow you to perform some tmux-related actions that I frequently use.

| keycode | action |
|---|---|
| `TMUX_NEXT` | Traverses to next window |
| `TMUX_PREV` | Traverses to previous window |
| `TMUX_LAST` | Switches to last active window |
| `TMUX_PEEK` | Momentarily switches to last active window while key is down |

#### Tapdance
There is also a tapdance accessible via the `KC_TMUX` keycode which provides several of the same actions as the keycodes above.

| dance move | action |
|---|---|
| Single tap | Traverses to next window |
| Double tap | Switches to last active window |
| Single hold | Sends TMUX prefix |
| Double hold | Momentarily switches to last active window while key is down |

### SKDM
Single-key Dynamic Macro is a tapdance accessible via the `KC_SKDM1` and `KC_SKDM2` keycodes. Allows you to do recording and playback of a macro 1 with a single key.

| dance move | action |
|---|---|
| Single tap | Playback any recorded macro in the register |
| Double tap | Stop recording macro to the indicated register |
| Triple tap | Begin recording macro to the indicated register |

### Swap Hands
Added a define which has a matrix that correctly swaps each half of a 5x12 ortho (particularly a split one).

Requires that the QMK [Swap Hands](https://docs.qmk.fm/#/feature_swap_hands) feature be enabled.

### vscode
Just a layer for some shortcuts and macros in VSCode
