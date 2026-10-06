# 109titration — Chemical pH Curve Numerical Derivative Analysis

Computational chemistry utility calculating equivalence points in acid-base titration experiments using cubic spline interpolation and numerical differentiation.

## Technical Overview

- **Primary Stack:** Python 3, Numerical Analysis, Mathematical Modeling
- **Core Language:** Python

## Key Architecture & Features

- First and second derivative estimation over experimental volume/pH data points
- Cubic spline interpolation with second-order polynomial fitting
- Equivalence point detection where second derivative crosses zero

## Build & Execution

```sh
./109titration data.csv
```
