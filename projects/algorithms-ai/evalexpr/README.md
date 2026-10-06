# EvalExpr — Recursive Descent Expression Parser & AST Evaluation

A lightweight, zero-dependency mathematical expression evaluator in C implementing recursive descent parsing to compute arithmetic expressions with operator precedence and nested parentheses.

## Overview

EvalExpr computes mathematical expressions directly from a character string. By utilizing a recursive descent grammar parser, it eliminates the need for external parsing generators or postfix conversion passes, evaluating values in a single recursive traversal.

## Architecture & Technical Highlights

- **Grammar Hierarchy:** Strict BNF grammar hierarchy resolving parentheses, multiplicative operations (`*`, `/`, `%`), and additive operations (`+`, `-`).
- **Unary Operator Handling:** Clean recursive resolution of sign negation (`-`) and chained operators.
- **Integer Arithmetic & Division Safety:** Zero-division prevention, whitespace skipping, and numerical token extraction.

## Tech Stack

- **Language:** C (C99)
- **Parsing Strategy:** Recursive Descent Grammar Parsing
- **Build System:** GNU Make

## Build & Execution

```bash
# Compile evaluator
make

# Evaluate expression
./eval_expr "(3 + 4) * 5 - 10 / 2"
# Output: 30
```
