# BSQ — Dynamic Programming Maximal Square Finder

High-performance 2D grid processing algorithm finding the largest unobstructed square on a map containing arbitrary obstacles.

## Technical Overview

- **Primary Stack:** C, Dynamic Programming, Fast Memory Buffering
- **Core Language:** C

## Key Architecture & Features

- 2D Dynamic Programming algorithm running in O(W × H) linear time
- Custom fast file I/O buffering parsing multi-megabyte grids in milliseconds
- In-place grid state memoization minimizing heap allocations

## Build & Execution

```sh
make
./bsq map.txt
```
