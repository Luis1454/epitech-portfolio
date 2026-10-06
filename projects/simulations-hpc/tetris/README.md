# Tetris — Terminal Grid Engine & NCurses Event Loop

A terminal-based implementation of Tetris in pure C utilizing NCurses. Features real-time event loops, dynamic tetromino descriptor parsing, collision detection matrices, and high-score serialization.

## Overview

This implementation features a robust terminal UI engine running in raw terminal mode, completely detached from line buffering. It dynamically loads external tetromino shape definition files, validates geometries, and drives standard game mechanics (rotation, line clears, score scaling, speed ramping).

## Architecture & Technical Highlights

- **Raw Terminal NCurses Engine:** Non-blocking keyboard input processing (`nodelay`, `cbreak`) with customized ANSI color pairs.
- **Dynamic Tetromino Loader:** File parser reading `.tetrimino` shape files at startup, validating syntax, dimensions, and color tags.
- **Matrix Collision Detection:** 2D grid matrix algorithms validating boundary bounds, lateral collisions, and rotation clearances.
- **CLI Configuration Flags:** Complete POSIX command-line argument parser (`--level`, `--key-left`, `--key-right`, `--without-next`, `--debug`).

## Tech Stack

- **Language:** C (C99)
- **Library:** NCurses
- **Build System:** GNU Make

## Build & Execution

```bash
# Compile binary
make

# Run game in default mode
./tetris

# Run with custom keybindings and debug display
./tetris -l 5 -D
```
