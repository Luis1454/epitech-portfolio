# Lem-In — Network Flow Pathfinding & Graph Optimization

Graph optimization engine solving maximum network flow problems for ant colony routing through a network of connected rooms and tunnels.

## Technical Overview

- **Primary Stack:** C, Graph Theory, Network Flow Optimization
- **Core Language:** C

## Key Architecture & Features

- Breadth-First Search (BFS) and Edmonds-Karp / Ford-Fulkerson maximum flow algorithm
- Disjoint path extraction minimizing total step counts across concurrent ant movements
- Real-time movement simulator preventing room collision bottlenecks

## Build & Execution

```sh
make
./lem_in < anthill.map
```
