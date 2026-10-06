# Numerical Mathematics & Scientific Algorithms Suite

A comprehensive collection of scientific computing implementations, numerical methods, physical motion simulations, and linear algebra routines.

## Overview

This repository aggregates applied scientific computing algorithms implemented in Python and C. Each sub-module addresses a specific analytical problem spanning kinematics, projective geometry, matrix inversions, non-linear root finding, discrete chaotic dynamical systems, Laplace transfer functions, and higher-order Taylor expansions.

## Scientific Implementations

| Algorithm Directory | Scientific Domain | Method & Implementation Highlights |
| :--- | :--- | :--- |
| [`101-pong-physics-vectors/`](./101-pong-physics-vectors/) | Classical Kinematics & Mechanics | 3D velocity vectors, linear trajectory prediction, impact incidence angle |
| [`102-affine-transformation-matrices/`](./102-affine-transformation-matrices/) | Linear Algebra & Computer Graphics | Homogeneous coordinate matrices, translation, scaling, 3D rotation compositions |
| [`103-matrix-encryption-inversion/`](./103-matrix-encryption-inversion/) | Linear Algebra & Cryptography | Matrix multiplication, determinant calculation, Gauss-Jordan matrix inversion |
| [`104-geometric-surface-intersections/`](./104-geometric-surface-intersections/) | Analytical Geometry & Ray Casting | Quadratic surfaces (sphere, cylinder, cone) ray-surface intersection equations |
| [`105-torus-numerical-root-finding/`](./105-torus-numerical-root-finding/) | Numerical Analysis & Optimization | Quartic polynomial solving via Bisection, Newton-Raphson, and Secant methods |
| [`106-chaotic-population-bifurcations/`](./106-chaotic-population-bifurcations/) | Non-Linear Dynamical Systems | Verhulst population growth model, bifurcation diagrams, chaotic transition analysis |
| [`107-transfer-function-frequency-poles/`](./107-transfer-function-frequency-poles/) | Signals & Systems Engineering | Rational polynomial Laplace transfer functions, frequency response, pole analysis |
| [`108-taylor-series-matrix-exponential/`](./108-taylor-series-matrix-exponential/) | Advanced Calculus & Matrix Analysis | Matrix exponential, hyperbolic Taylor series expansions with convergence limits |
| [`110-borwein-numerical-quadratures/`](./110-borwein-numerical-quadratures/) | Numerical Quadrature & Integration | Midpoint rule, Trapezoidal rule, and Simpson's 3/8 rule applied to Borwein integrals |

## Execution

```bash
# Run 3D kinematic trajectory solver
./101-pong-physics-vectors/101pong 1 2 3 4 5 6 2

# Compute Matrix Taylor expansion
./108-taylor-series-matrix-exponential/108trigo EXP 4 1 2 3 4
```
