# Sokoban — Terminal Warehouse Puzzle Engine

Terminal warehouse box-pushing puzzle engine featuring map validation, real-time keyboard interaction, collision detection, and win/loss condition tracking.

## Technical Overview

- **Primary Stack:** C, Ncurses, Game Loops
- **Core Language:** C

## Key Architecture & Features

- Ncurses-powered terminal rendering with dynamic terminal resizing management
- Box pushing physics and wall obstruction checks
- Storage goal verification and deadlock state detection

## Build & Execution

```sh
make
./my_sokoban map.txt
```
