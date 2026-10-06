# Arcade — Modular Gaming Platform & Dynamic Graphic Libraries

A decoupled, modular gaming engine in C++ demonstrating runtime dynamic polymorphism and hot-swappable shared libraries (`.so`). Arcade cleanly separates game state logic from graphical rendering pipelines via strict abstract interface definitions.

## Overview

Arcade solves the problem of cross-toolkit graphics abstraction by operating entirely through dynamic shared libraries loaded at runtime (`dlopen(3)`, `dlsym(3)`). The core engine manages event dispatching and entity states, allowing users to switch graphic libraries (e.g. from SFML to SDL2 or an NCurses terminal interface) and game cartridges (Snake, Nibbler, Pacman) on the fly without restarting or recompiling.

## Architecture & Technical Highlights

- **Dynamic Plugin System:** Dynamic library loaders with strict RAII resource lifecycle management and automated symbol extraction.
- **Graphic Toolkit Abstraction:** Pure abstract `IGraphic` interfaces implemented across **SFML**, **SDL2**, and **NCurses**.
- **Game Logic Decoupling:** Standalone `IGame` implementations handling collision grids, scoring, entity state loops, and frame-rate throttling independently from rendering backends.
- **Hot-Swapping at Runtime:** Instant switching between graphical drivers and games with persistent state preservation and seamless display reconstruction.

## Tech Stack

- **Language:** Modern C++ (C++17 / C++20)
- **Dynamic Linker:** `dlopen`, `dlsym`, `dlclose`, `dlerror` (POSIX)
- **Renderers:** SFML, SDL2, NCurses
- **Build System:** GNU Make / CMake

## Build & Execution

```bash
# Compile core engine and all dynamic graphic/game libraries
make

# Launch arcade with an initial graphic shared library
./arcade ./lib/arcade_sfml.so
# or
./arcade ./lib/arcade_ncurses.so
```
