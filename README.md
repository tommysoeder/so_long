# so_long

`so_long` is a small 2D game written in C for the 42 curriculum. The player moves through a tile-based map, collects every collectible, and then reaches the exit. The project focuses on window management, event handling, texture rendering, map parsing, path validation, and careful resource cleanup.

The game uses the Linux version of MiniLibX and renders each map cell as a 96 × 96 pixel tile.

## Gameplay

The objective is simple:

1. Move through the map without crossing walls.
2. Collect every `C` tile.
3. Reach the `E` tile after all collectibles have been collected.

The exit remains blocked until the collection is complete. Each successful move is printed to the terminal, and the game closes after winning, pressing `Esc`, or using the window close button.

### Controls

| Key | Action |
| --- | --- |
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `Esc` | Close the game |

## Map format

Maps are plain-text files conventionally stored with the `.ber` extension. The parser recognizes five characters:

| Character | Meaning |
| --- | --- |
| `0` | Walkable floor |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player starting position |

Example:

```text
11111
1P0C1
100E1
11111
```

Before opening a window, the program verifies that the map:

- is not empty;
- is rectangular;
- is completely enclosed by walls;
- contains only `0`, `1`, `C`, `E`, and `P`;
- contains exactly one player and one exit;
- contains at least one collectible;
- provides a path from the player to every collectible and the exit.

Reachability is checked on a duplicate of the grid with a recursive flood-fill algorithm, leaving the playable map unchanged.

## Technical overview

The project is split into a small set of focused components:

- **File loading:** reads the complete map from a file descriptor and builds a two-dimensional grid.
- **Validation:** checks the map shape, boundary walls, allowed content, required elements, and reachable paths.
- **Game state:** stores the grid, player position, collectible counts, movement count, MiniLibX context, window, and texture handles.
- **Rendering:** draws the floor or wall for every cell, overlays collectibles and the exit, and finally renders the player.
- **Input:** registers MiniLibX hooks for keyboard and window-close events.
- **Movement:** rejects walls and premature exit attempts, collects items, updates coordinates, counts valid moves, and detects victory.
- **Cleanup:** destroys loaded images and the window, then releases the allocated map.

The floor texture has a generated solid-color fallback if its XPM file cannot be loaded. The other required textures cause a controlled error when loading fails.

## Project structure

```text
.
├── README.md
└── So_long/
    ├── Makefile
    ├── include/so_long.h
    ├── src/                  # Parsing, validation, rendering, input, and cleanup
    ├── libft/                # Local Libft and ft_printf implementation
    ├── maps/                 # Valid and invalid example maps
    ├── textures/             # XPM game assets
    ├── minilibx-linux/       # MiniLibX build location
    └── minilibx-linux.tgz    # Bundled Linux MiniLibX source archive
```

The repository also contains MiniLibX archives for macOS, but the current project Makefile, linker flags, and key codes target the Linux/X11 implementation.

## Requirements

The current build requires a Linux environment with:

- `cc` or GCC;
- GNU Make;
- X11 development files;
- the XShm extension development files;
- BSD development utilities required by MiniLibX.

On Debian or Ubuntu, the MiniLibX documentation recommends:

```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

An active graphical X11 display is required to run the game. When using WSL, an X server or WSLg must also be available.

## Build

Clone the repository and enter the project directory:

```bash
git clone https://github.com/tommysoeder/so_long.git
cd so_long/So_long
```

The repository includes the Linux MiniLibX source as `minilibx-linux.tgz`. Extract and compile it before building the game:

```bash
tar -xzf minilibx-linux.tgz
make -C minilibx-linux
make
```

This creates the `so_long` executable in `So_long/`.

Available Makefile targets:

```bash
make          # Build the game
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Rebuild from scratch
make bonus    # Build the same target as `make`
```

## Run

Run the executable from `So_long/` so that its relative texture paths resolve correctly:

```bash
./so_long maps/simple.ber
```

Another valid example with several collectibles is available at `maps/collect.ber`:

```bash
./so_long maps/collect.ber
```

Invalid examples under `maps/` can be used to observe validation errors, such as an unknown character, missing exit, non-rectangular shape, open boundary, or unreachable objective.

## Error handling

The program writes errors to standard error, releases initialized resources, and exits with a failure status when it encounters invalid arguments, an unreadable or empty map, invalid map content, an unreachable objective, allocation failure, MiniLibX initialization failure, or a missing required texture.

The executable expects exactly one map path:

```text
./so_long <map-file>
```

## Concepts practised

- C structures and modular program design.
- Dynamic memory allocation and cleanup.
- File descriptors and file parsing.
- Two-dimensional grids and coordinate systems.
- Recursive flood fill and reachability validation.
- Event-driven input with MiniLibX hooks.
- XPM texture loading and tile-based rendering.
- Makefiles, static libraries, and linker flags.

## Current scope

This implementation provides the mandatory gameplay loop. The `bonus` target currently builds the same executable and does not add enemies, animation, or an on-screen movement counter. Movement is reported in the terminal. The parser accepts any readable filename and validates its contents, but it does not enforce the `.ber` filename extension.

The window size is calculated directly from the map dimensions and the fixed 96-pixel tile size, so large maps may exceed the available display area. The recursive path check is appropriate for the included maps but has not been designed or benchmarked for unusually large inputs.

## Author

Created by [tommysoeder](https://github.com/tommysoeder) as part of the 42 curriculum.

AI tools were used to review the repository and improve this documentation. The behavior described here was checked against the source code; this statement does not attribute AI use to the implementation where the repository provides no such record.
