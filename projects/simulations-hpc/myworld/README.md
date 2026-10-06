# myWorld — 3D Isometric Terrain Modeling & Heightmap Engine

An interactive 3D terrain modeling and visualization tool developed in C with CSFML, implementing isometric projection transformations, dynamic vertex sculpting, and real-time mesh rendering.

## Overview

myWorld allows users to generate, visualize, and sculpt three-dimensional terrain maps in real time. It calculates mathematical projections to transform 3D grid vertices into a 2D isometric viewport, providing intuitive elevation controls and texture mapping.

## Architecture & Technical Highlights

- **Isometric Projection Matrix:** Mathematical transformation converting 3D coordinates $(x, y, z)$ into 2D screen space $(X_{2D}, Y_{2D})$ using angle parameters $(lpha, eta)$.
- **Dynamic Mesh Manipulation:** Real-time brush-based vertex elevation modification (raising/lowering points, smoothing terrain, flattening plateaus).
- **Shading & Texture Mapping:** Color gradient interpolation based on vertex altitude (water, sand, grass, rock, snow) with polygon fill rendering.
- **File Serialization:** Custom format parser to save and load terrain heightmaps to and from disk.

## Tech Stack

- **Language:** C (C99)
- **Library:** CSFML
- **Math:** 3D-to-2D Isometric Geometry & Coordinate Transformations
- **Build System:** GNU Make

## Build & Execution

```bash
# Build binary
make

# Run terrain editor
./my_world
```
