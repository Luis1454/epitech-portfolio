# R-Type — Cross-Platform Multiplayer Networked Game Engine (ECS)

A high-performance, cross-platform networked multiplayer 2D space shooter in modern C++20 built on a custom Entity-Component-System (ECS) architecture with non-blocking UDP/TCP client-server synchronization.

## Overview

R-Type replicates the classic side-scrolling arcade shooter as a distributed, networked multiplayer platform. The engine is architected around an in-house Entity-Component-System (ECS) model to ensure deterministic game state updates, high cache locality, and scalable concurrency across client and server runtimes.

## Architecture & Technical Highlights

- **Custom ECS Architecture:** Modular registry pattern managing dense component arrays (position, velocity, hitboxes, health, renderable sprites) and decoupled systems (movement, collision, rendering, AI behavior).
- **Network Protocol & Serialization:** Custom lightweight binary communication protocol operating over UDP sockets for low-latency player state replication and entity interpolation.
- **Authoritative Server Model:** Dedicated game server validating physics, projectile trajectories, and collision resolutions to ensure state consistency.
- **Client Extrapolation & Interpolation:** Smooth client-side entity smoothing compensating for network jitter and packet loss.
- **Audio & Visual Pipeline:** Hardware-accelerated 2D rendering and spatial audio playback using SFML.

## Tech Stack

- **Language:** Modern C++20
- **Architectural Pattern:** Entity-Component-System (ECS)
- **Networking:** Asynchronous BSD / ASIO sockets (UDP / TCP)
- **Graphics & Audio:** SFML 2.5+
- **Build System:** CMake (Cross-platform Linux & Windows)

## Build & Execution

```bash
# Configure and build client and server binaries
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Start authoritative game server
./build/r-type_server -p 4242

# Launch graphical client
./build/r-type_client -h 127.0.0.1 -p 4242
```
