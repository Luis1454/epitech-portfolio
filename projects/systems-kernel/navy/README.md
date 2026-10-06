# Navy — Inter-Process Terminal Battleship via POSIX Signals

Terminal-based multiplayer Battleship game communicating strictly through POSIX user signals (`SIGUSR1` and `SIGUSR2`) without network sockets or pipes.

## Technical Overview

- **Primary Stack:** C, POSIX signals (`sigaction`, `kill`)
- **Core Language:** C

## Key Architecture & Features

- Process-to-process handshake and PID exchange via signals
- Bitstream transmission encoding coordinates and attack confirmations using signal frequencies
- Grid board representation, ship placement validation, and hit/miss detection
- Real-time terminal interface

## Build & Execution

```sh
make
./navy [target_pid] navy_positions.txt
```
