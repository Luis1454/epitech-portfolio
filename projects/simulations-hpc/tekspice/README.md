# TekSpice — Discrete Electronic & Digital Logic Circuit Simulator

Object-oriented discrete electronic component and digital logic circuit simulation engine in C++20. Parses Netlist component topologies and evaluates cyclic graph state propagation across discrete clock cycles.

## Technical Overview

- **Primary Stack:** C++20, Object-Oriented Design, Graph Traversal Algorithms, CMake/Make
- **Core Language:** C++20

## Key Architecture & Features

- Netlist parser validating component declarations (`.chipsets`) and graph links (`.links`)
- Standard elementary logic gates: AND, OR, XOR, NOT, NAND, NOR, XNOR
- Advanced 4000-series CMOS logic chips: 4001, 4011, 4030, 4069, 4071, 4081, 4008 (4-bit full adder), 4013 (Dual D-type flip-flop), 4017 (Johnson decade counter)
- Three-state logic system: `TRUE`, `FALSE`, and `UNDEFINED`
- Cyclic graph state resolution, clock pulse generation, and interactive simulation terminal

## Build & Execution

```sh
make
./nanotekspice circuits/4008_adder.nts in_a=1 in_b=1
```
