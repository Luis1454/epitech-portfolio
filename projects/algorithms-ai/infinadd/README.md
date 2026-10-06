# InfinAdd — Arbitrary-Precision BigInt Arithmetic Engine

Arbitrary-precision arithmetic utility performing addition and subtraction on arbitrarily long numerical strings beyond hardware register bounds.

## Technical Overview

- **Primary Stack:** C, BigInt Numerical Algorithms
- **Core Language:** C

## Key Architecture & Features

- Support for arbitrary digit counts with sign handling (+ and -)
- Column-wise addition and carry propagation
- Dynamic memory allocation scaled to operand magnitude

## Build & Execution

```sh
make
./infin_add 9999999999999999999999 1
```
