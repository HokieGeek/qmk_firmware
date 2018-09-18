# HokieGeek

## Features

### Accents
Spanish accents and special symbols are supported with the following keycodes:

| keycode | accent |
|---|---|
| `LATIN_E`    | é |
| `LATIN_A`    | á |
| `LATIN_I`    | í |
| `LATIN_O`    | ó |
| `LATIN_U`    | ú |
| `LATIN_N`    | ň |
| `LATIN_IEXC` | ¡ |
| `LATIN_IQS`  | ¿ |

The symbols will be entered as linux unicode values unless you set the `ACCENTS_MAC` define which will perform a MacOS key combo to get the symbols.

### TMUX
#### Keycodes
The following keycodes allow you to perform some tmux-related actions that I frequently use.

| keycode | action |
|---|---|
| `TMUX_NEXT` | Traverses to next window |
| `TMUX_PREV` | Traverses to previous window |
| `TMUX_LAST` | Switches to last active window |
| `TMUX_PEEK` | Momentarily switches to last active window while key is down |

The default prefix is set as "a" but can be overridden by setting the alternate value as the `TMUX_PREFIX` define.

#### Tapdance
There is also a tapdance accessible via the `KC_TMUX` which provides several of the same actions as the keycodes.

| dance move | action |
|---|---|
| Single tap | Traverses to next window |
| Double tap | Switches to last active window |
| Hold | Momentarily switches to last active window while key is down |


### Swap Hands
Added a define which has a matrix that correctly swaps each half of a 5x12 ortho (particularly a split one).

Requires that the QMK [Swap Hands](https://docs.qmk.fm/#/feature_swap_hands) feature be enabled.
