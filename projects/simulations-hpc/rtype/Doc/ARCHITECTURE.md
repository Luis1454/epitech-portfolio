# Project Architecture Overview
 
This document provides a structured overview of the project's key files and their purposes, focusing on the essential components.
 
---
 
## Table of Contents
1. [Client](#client)
2. [Protocol](#protocol)
3. [Server](#server)
 
---
 
## Client
The `client` directory contains the client-side implementation, including asset files, components, and game logic.
 
### Assets
Stores media resources such as images and fonts used in the client application.
- **`bcg.png`**: Background image.
- **`blue.png`, `enemy.png`, `player.png`, `projectile.png`**: Sprites for various in-game entities.
- **`story.json`**: A JSON file containing story data.
 
### Components
Encapsulates visual elements and client-side components.
- **`Sprite.cpp` / `Sprite.hpp`**: Handles sprite rendering and related logic.
 
### System
Manages client-side systems for rendering.
- **`Render.cpp` / `Render.hpp`**: Implements rendering functionality.
 
### Core Files
- **`game.cpp` / `game.hpp`**: Core game logic.
- **`menu.cpp` / `menu.hpp`**: Menu system implementation.
- **`setting.cpp` / `setting.hpp`**: Manages settings configurations.
- **`story.cpp` / `story.hpp`**: Handles story-related logic.
- **`UdpClient.cpp` / `UdpClient.hpp`**: Implements UDP client communication.
 
---
 
## Protocol
The `protocol` directory defines communication protocols between the client and the server.
 
### Buffer
Handles the internal buffer for protocol data.
- **`Buffer.cpp` / `Buffer.hpp`**: Core buffer management implementation.
 
### Protocol Core
- **`Protocol.cpp` / `Protocol.hpp`**: Implements the primary protocol logic.
 
### Requests
Defines specific request types for communication.
- **`AskEntityPos.cpp` / `AskEntityPos.hpp`**: Request to query entity positions.
- **`CreateEntity.cpp` / `CreateEntity.hpp`**: Handles entity creation requests.
- **`MovePlayer.cpp` / `MovePlayer.hpp`**: Manages player movement requests.
- **`ReceiveName.cpp` / `ReceiveName.hpp`**: Handles name reception.
- **`SendEntityPos.cpp` / `SendEntityPos.hpp`**: Sends entity position data.
 
---
 
## Server
The `server` directory contains the server-side implementation, including the ECS framework and UDP server.
 
### ECS (Entity-Component-System)
- **Components**: Defines data structures for entities.
  - **`Component.cpp` / `Component.hpp`**: Base class for components.
  - **`Enemy.cpp` / `Enemy.hpp`**: Represents enemy entities.
  - **`Player.cpp` / `Player.hpp`**: Represents player entities.
  - **`Position.cpp` / `Position.hpp`**: Manages position data.
  - **`Velocity.cpp` / `Velocity.hpp`**: Handles velocity data.
 
- **Entities**:
  - **`Entity.cpp` / `Entity.hpp`**: Base class for all entities.
 
- **Systems**: Defines behaviors and processes.
  - **`Gravity.cpp` / `Gravity.hpp`**: Implements gravity logic.
  - **`Motion.cpp` / `Motion.hpp`**: Handles motion updates.
  - **`System.cpp` / `System.hpp`**: Base class for systems.
 
- **Core Files**:
  - **`ECS.cpp` / `ECS.hpp`**: Core ECS management.
  - **`Sparse.hpp`**: Sparse array implementation for efficient data storage.
 
### Core Server Files
- **`main.cpp`**: Entry point for the server application.
- **`Parser.cpp` / `Parser.hpp`**: Parses incoming data.
- **`UdpServer.cpp` / `UdpServer.hpp`**: Implements UDP server communication.
 
---
 
## Conclusion
This structure outlines the core components and their respective roles within the project. The client and server are well-separated, with the protocol acting as the communication bridge. The ECS framework on the server provides a scalable and modular foundation for managing entities and systems.
 
For further details, consult the source code or related documentation files.