# myRadar — Real-Time Air Traffic Radar & Collision Simulation

2D Air traffic control simulation visualizing flight trajectories, control tower radii, and real-time aircraft collision detection using spatial Quadtree partitioning.

## Technical Overview

- **Primary Stack:** C, CSFML (Simple and Fast Multimedia Library), Quadtree spatial acceleration
- **Core Language:** C

## Key Architecture & Features

- Quadtree 2D spatial partitioning reducing collision checking from O(N²) to O(N log N)
- Kinematic flight models with heading angles, constant velocities, and boundary departures
- Control tower protection zones and landing destinations
- 60 FPS rendering under hardware-accelerated CSFML

## Build & Execution

```sh
make
./my_radar scenarios/air_traffic.script
```
