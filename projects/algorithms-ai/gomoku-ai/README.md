# Gomoku AI — Tournament Adversarial Game Engine

High-performance Gomoku (Five-in-a-Row) game engine designed for competitive tournament play under the Gomocup protocol. Employs Minimax search with Alpha-Beta pruning, bitboard representations, and heuristic pattern evaluation.

## Technical Overview

- **Primary Stack:** Python 3, Adversarial Search Algorithms, Game Theory
- **Core Language:** Python

## Key Architecture & Features

- Alpha-Beta pruning with iterative deepening and transposition tables
- Fast 20x20 bitboard representation with pattern matching (open threes, broken fours, five-in-a-row)
- Principal variation search and dynamic move ordering
- Gomocup tournament protocol compliance (sub-5 second turn constraints)

## Build & Execution

```sh
python3 main.py
```
