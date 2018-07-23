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
The following keycodes allow you to perform some tmux-related actions that I frequently use.

| keycode | action |
|---|---|
| `TMUX_NEXT` | Traverses to next window |
| `TMUX_PREV` | Traverses to previous window |
| `TMUX_LAST` | Switches to last active window |
| `TMUX_PEEK` | Momentarily switches to last active window while key is down |

The default prefix is set as "a" but can be overridden by setting the alternate value as the `TMUX_PREFIX` define.
