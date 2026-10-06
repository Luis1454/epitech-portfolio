# Dante's Star — Maze Generator & A* / Dijkstra Pathfinding Engine

High-throughput maze generator creating perfect and imperfect 2D labyrinths paired with optimized A* and Dijkstra pathfinding solvers.

## Technical Overview

- **Primary Stack:** C, Graph Search, Heuristic Algorithms
- **Core Language:** C

## Key Architecture & Features

- Procedural maze generation with randomized Kruskal / recursive backtracking
- A* heuristic pathfinding algorithm with Manhattan distance estimation
- Memory-efficient 2D map parsing and dead-end pruning
- Solves 1000x1000 grids in milliseconds

## Build & Execution

```sh
make
./generator/generator 100 100 perfect > maze.txt
./solver/solver maze.txt
```
