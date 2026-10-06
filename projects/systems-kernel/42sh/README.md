# 42sh — POSIX-Compliant Unix Shell Architecture

Complete Unix command language interpreter engineered in C. Features Abstract Syntax Tree (AST) lexical parsing, multi-process pipeline orchestration, signal handling, and interactive terminal job control.

## Technical Overview

- **Primary Stack:** C (C11), POSIX.1-2008 APIs, GNU Make, GCC/Clang
- **Core Language:** C

## Key Architecture & Features

- Lexical analyzer & recursive-descent parser generating an execution AST
- Multi-stage pipe execution using `pipe()`, `fork()`, `dup2()`, and `execve()`
- Stream redirections (`<`, `>`, `>>`, `<<` here-documents)
- Signal masking & handling (`SIGINT`, `SIGTSTP`, `SIGCHLD`)
- POSIX built-ins: `cd`, `setenv`, `unsetenv`, `env`, `exit`, `echo`, `alias`, `which`, `where`
- Interactive line editing and command history navigation

## Build & Execution

```sh
make
./42sh
```
