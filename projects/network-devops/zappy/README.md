# Zappy — High-Throughput Networked Simulation & Autonomous AI Protocol

A distributed real-time simulation engine featuring an asynchronous TCP multiplexed server in C, an autonomous multi-agent AI ecosystem, and a hardware-accelerated 3D graphical visualizer.

## Overview

Zappy models an alien civilization surviving on a grid-based resource world (`Trantor`). The system comprises three independently communicating components synchronized via a strict custom TCP protocol:
1. **Asynchronous Game Server:** Manages spatial tile maps, resource generation, team lifespans, and command queues with non-blocking network I/O.
2. **Autonomous AI Clients:** Self-organizing decision agents balancing survival, hunger depletion, team communication, and hierarchical elevation rituals.
3. **Real-Time Graphical Viewer:** Connects via TCP to stream and render world events, player evolutions, and resource extractions in real time.

## Architecture & Technical Highlights

- **Non-Blocking I/O Multiplexing:** Server written in C leveraging `select(2)` / `poll(2)` to handle dozens of concurrent AI and GUI socket connections with zero thread-locking contention.
- **Action Scheduling Queue:** Command frequency unit scheduler (`f` parameter) enforcing timed execution delays per action (`Fork`, `Incantation`, `Broadcast`, `Look`, `Inventory`).
- **Spatial Audio Broadcasting:** Tile-distance directional sound propagation algorithm computing incoming sound direction numbers (1 to 8) based on toroidal world geometry.
- **Multi-Agent Coordination:** Autonomous clients coordinating complex 6-player elevation ceremonies through cryptographic/encoded team broadcasts.

## Tech Stack

- **Server:** C (POSIX BSD Sockets, non-blocking multiplexing)
- **AI Clients:** Python / C++ (Autonomous FSM decision loops)
- **GUI Viewer:** C++ / 3D Engine (TCP state subscriber)
- **Build System:** GNU Make

## Build & Execution

```bash
# Build server, GUI, and AI binaries
make

# Run the server on port 4242 with 10x10 map and 100 frequency units
./zappy_server -p 4242 -x 10 -y 10 -n TeamA TeamB -c 4 -t 100

# Connect AI client
python3 ./IA/ai_client.py -p 4242 -n TeamA -h 127.0.0.1
```
