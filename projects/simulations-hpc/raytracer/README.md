# Raytracer — Multithreaded 3D Raytracing Engine

A high-performance 3D optical raytracer written in modern C++20 featuring recursive reflection, Phong illumination, shadow projection, post-processing visual effects, and a multithreaded tile renderer.

## Technical Overview

- **Language:** C++20
- **Build System:** Make / GCC
- **Parallelism:** Multi-threaded Tile Dispatcher (`std::thread`, work-stealing tile queue)
- **Graphics & Viewport:** SFML (Realtime viewport & event loop), PPM image exporter
- **Configuration:** libconfig scene description parser

## Core Architecture & Engine Components

### 1. Geometric Primitives & Analytical Solvers
The engine computes analytical ray-surface intersections across classical 3D primitives:
- **Spheres & Circles:** Quadratic discriminants for ray-sphere entry/exit points.
- **Planes & Rectangles:** Hyperplane dot-product intersections with 2D bounds tests.
- **Cylinders & Cones:** Truncated quadratic solvers with finite height limits and cap clipping.
- **Triangles & Polygons:** Möller–Trumbore intersection algorithm for arbitrary meshes.
- **Cubes / Axis-Aligned Boxes:** Slab method for robust ray-box intersection.

### 2. Illumination & Optics Pipeline
- **Phong Reflection Model:** Ambient light, Lambertian diffuse reflection, and Blinn-Phong specular highlights.
- **Shadow Projection:** Secondary hard shadow rays evaluated toward point, directional, and environmental emitters.
- **Recursive Ray Bouncing:** Configurable bounce recursion depth (`BOUNCES = 5`) for specular reflections and mirror surfaces.
- **Light Sources:** Ambient, point lights with distance attenuation, directional lights, and spherical environment maps (`.ppm`).

### 3. Post-Processing & Screen Space Effects
- **Bloom Filter:** High-pass luminance thresholding with Gaussian blur blending.
- **Gaussian Blur:** Separable 2D convolution kernel with configurable radius and standard deviation.
- **Chromatic Aberration:** RGB channel radial displacement simulating physical lens dispersion.
- **Luminance Clamping:** Dynamic range tone-mapping preventing color saturation artifacts.

### 4. Multithreaded Tile Dispatcher
- Screen space is decomposed into configurable raster tiles (`100x100 px`).
- Worker threads concurrently process tiles from a shared synchronized job queue (`std::mutex`, `std::queue`).
- Lockless destination frame-buffer writes with cache-line alignment to maximize memory bandwidth.

### 5. Scene Parser & Dual Output Pipeline
- Fully declarative scene configuration files (`.cfg`) defining camera position, field of view, lights, primitives, materials, and post-processing passes.
- Interactive mode (`-sfml`) displaying the live rendering buffer in an SFML window.
- Headless batch mode exporting directly to standard uncompressed PPM files.

## Build & Execution

### Compilation

```sh
make
```

### Usage

```sh
# Headless render to PPM export
./raytracer example/conf2.cfg

# Interactive render with live SFML viewport
./raytracer -sfml example/conf_example.cfg
```
