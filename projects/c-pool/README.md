# C Pool — Piscine C Systems Programming Suite

A comprehensive, ground-up systems programming curriculum and library implementation in C (System V AMD64 ABI, C99/C11). Spans raw pointer manipulation, memory allocation mechanics, string parsing primitives, recursive algorithms, linked data structures, file descriptor I/O multiplexing, and binary tree representations.

## Overview

This repository captures an intensive, immersion-based systems programming track designed to master the fundamentals of modern computing without standard library dependencies. It covers the complete progression from hardware data representation and pointer arithmetic to custom libc implementations, memory managers, and multi-file architecture orchestration.

## Modular Architecture & Curriculum Progression

| Module Directory | Topic & Key Implementations | Core Technical Concepts |
| :--- | :--- | :--- |
| [`day01-unix-syntax/`](./day01-unix-syntax/) | Shell environments, compilation flags, program entry points | `main` signature, exit status codes |
| [`day02-types-variables/`](./day02-types-variables/) | Primitive data types, byte widths, sign extensions | Two's complement, overflow handling |
| [`day03-pointers-addresses/`](./day03-pointers-addresses/) | Pointer mechanics, dereferencing, pointer-to-pointer | Direct memory addresses, call-by-reference |
| [`day04-string-primitives/`](./day04-string-primitives/) | Custom string routines (`my_strlen`, `my_putstr`, `my_evil_str`) | Null-terminator bounds, buffer traversing |
| [`day05-loops-recursion/`](./day05-loops-recursion/) | Factorials, power functions, prime tests, square roots | Tail call elimination, stack limits |
| [`day06-string-search-memory/`](./day06-string-search-memory/) | Substring matching, memory copying (`my_strcpy`, `my_strstr`) | Fast string scanning, overlap detection |
| [`day07-cli-arguments-malloc/`](./day07-cli-arguments-malloc/) | Dynamic heap allocation, heap arrays (`my_str_to_word_array`) | Heap memory lifecycle, `malloc`/`free` |
| [`day08-structs-header-files/`](./day08-structs-header-files/) | Heterogeneous data structures, header guards, alignment | Data alignment, memory padding, ABI structs |
| [`day09-preprocessor-macros/`](./day09-preprocessor-macros/) | C preprocessor, macro expansion, conditional compilation | Multi-platform build configurations |
| [`day10-compilation-makefiles/`](./day10-compilation-makefiles/) | Static library generation (`libmy.a`), Makefile dependency rules | `ar`, `ranlib`, automated build targets |
| [`day11-singly-linked-lists/`](./day11-singly-linked-lists/) | Dynamic linked list operations (insertion, sorting, reversing) | Head/tail node pointers, memory traversal |
| [`day12-file-descriptors-io/`](./day12-file-descriptors-io/) | POSIX low-level I/O (`read`, `write`, `open`, `close`) | Kernel file tables, stream buffering |
| [`day13-binary-streams-trees/`](./day13-binary-streams-trees/) | Binary trees, recursive traversals, binary file parsing | Node balancing, binary serialization |
| [`rush1-box-drawing/`](./rush1-box-drawing/) | Procedural 2D boundary drawing and corner algorithms | Coordinate transformations, edge cases |
| [`rush2-letter-frequency-detector/`](./rush2-letter-frequency-detector/) | Statistical language detection via letter frequency analysis | Distribution matrices, ASCII normalization |
| [`star-draw/`](./star-draw/) | Symmetric star geometric terminal rendering algorithm | Parametric geometric rasterization |
| [`island-floodfill-counter/`](./island-floodfill-counter/) | 2D matrix recursive flood-fill connected-component counter | Graph traversal, connected components |
| [`workshop-c-standard-library/`](./workshop-c-standard-library/) | High-performance C standard library implementation (`libmy.a`) | Reusable memory, string, and math primitives |

## Engineering Principles

- **Zero-Dependency Implementations:** Re-implementation of core libc algorithms directly using kernel system calls.
- **Strict Memory Safety:** All routines validated under Valgrind with zero memory leaks, invalid reads, or uninitialized byte accesses.
- **Compiler Hardening:** Compiled with strict flags `-Wall -Wextra -Werror -pedantic -std=c99`.

## Build Instructions

```bash
# Build unified foundational library
make -C workshop-c-standard-library/

# Run unit tests on linked lists and string primitives
make -C day11-singly-linked-lists/
```
