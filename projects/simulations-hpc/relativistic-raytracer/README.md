# Relativistic Raytracer — Curved Spacetime Geodesic Engine

Optical raytracing simulation modeling photon trajectories along null geodesics in curved spacetime metrics (Schwarzschild and Kerr black holes) using numerical differential integrators.

## Technical Overview

- **Primary Stack:** C++20, Numerical Methods (RK4), Differential Geometry, Make
- **Core Language:** C++20

## Key Architecture & Features

- Runge-Kutta 4th-order (RK4) numerical integration of geodesic differential equations
- Gravitational lensing, photon sphere deflection, and event horizon shadow calculation
- Accretion disk rendering with relativistic Doppler beaming and gravitational redshift
- Modular camera model, ray generation, and image export

## Build & Execution

```sh
make
./raytracer scenes/blackhole.cfg
```
