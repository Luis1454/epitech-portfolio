# myRPG — 2D Role-Playing Game Engine & Real-Time Event Loop

A comprehensive 2D game engine in C utilizing CSFML (C Simple and Fast Multimedia Library), featuring a decoupled game state machine, sprite animations, spatial tilemap collisions, and custom event handlers.

## Overview

myRPG is an interactive role-playing game developed from first principles in C. The architecture isolates the rendering loop, input handling, entity management, and user interface layers, delivering smooth 60 FPS performance with custom particle emitters and modular dialogue systems.

## Architecture & Technical Highlights

- **State Machine Loop:** Finite State Machine (FSM) governing game progression (Main Menu, World Exploration, In-Game Pause, Inventory Inspection, Combat Encounters).
- **Spatial Map & Collision Engine:** Grid-based layer parsing managing collision masks, foreground overlays, and depth-sorted isometric/orthographic entity rendering.
- **Entity & Particle System:** Reentrant linked data structures for monsters, NPCs, and projectile particle effects with velocity vectors and lifetime damping.
- **Interactive UI & Dialogue Engine:** Custom button event traps, hover states, quest tracking queues, and character dialogue trees.

## Tech Stack

- **Language:** C (C99)
- **Graphics & Audio:** CSFML (SFML C bindings)
- **Build System:** GNU Make

## Build & Execution

```bash
# Compile game executable
make

# Launch RPG
./my_rpg
```
