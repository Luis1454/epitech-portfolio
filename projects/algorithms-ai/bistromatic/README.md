# Bistromatic — Arbitrary-Precision BigInt Arithmetic Engine

An arbitrary-precision mathematical calculator in C capable of evaluating mathematical expressions with arbitrarily large numbers, customizable character bases, and arithmetic operator sets.

## Overview

Bistromatic evaluates deeply nested arithmetic expressions involving numbers of infinite length (constrained only by available system RAM). It features custom big-integer addition, subtraction, multiplication, division, and modulo routines, paired with an operator-precedence expression evaluator.

## Architecture & Technical Highlights

- **Base-Agnostic Arithmetic:** Operates on any custom numerical base (Binary, Octal, Decimal, Hexadecimal, or arbitrary symbol alphabets) via string-mapped arithmetic algorithms.
- **Arbitrary-Precision Primitives:** Handcrafted BigInt arithmetic algorithms handling carry propagation, borrow tracking, and long division with zero memory leaks.
- **Expression Evaluation Engine:** Tokenizer and parser resolving operator precedence (`*`, `/`, `%` over `+`, `-`) and arbitrarily deep nested parentheses.
- **Strict Memory Management:** Dynamic buffer allocation and zero-allocation string manipulation ensuring leak-free execution under Valgrind.

## Tech Stack

- **Language:** C (C99)
- **Algorithms:** BigInt arithmetic, Shunting-Yard / Recursive expression parsing
- **Build System:** GNU Make

## Build & Execution

```bash
# Compile calculator
make

# Run evaluation: [base] [operators] [expression_length]
echo "(123456789101112131415 + 987654321) * 42" | ./calc "0123456789" "()+-*/%" 41
```
