# Need4Stek — Autonomous Vehicle Lidar Controller

Autonomous vehicle control algorithm driving a simulated car through complex tracks by analyzing real-time 32-beam lidar distance streams and computing adaptive PID steering and speed commands.

## Technical Overview

- **Primary Stack:** C, Robotics & Control Systems, CoppeliaSim API
- **Core Language:** C

## Key Architecture & Features

- Real-time lidar sensor telemetry parsing via stdin/stdout IPC
- Dynamic speed adaptation based on middle and side obstacle clearances
- Proportional-Integral-Derivative (PID) steering regulation
- Track wall collision prevention and dead-end recovery

## Build & Execution

```sh
make
./pipes.sh
```
