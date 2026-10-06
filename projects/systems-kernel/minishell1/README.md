# Minishell 1 — Unix Process Lifecycle & Command Interpreter

Fundamental Unix shell engine handling user input tokenization, child process execution lifecycle, PATH resolution, and built-in commands.

## Technical Overview

- **Primary Stack:** C, POSIX system calls
- **Core Language:** C

## Key Architecture & Features

- Command tokenization and whitespace normalization
- Child process spawning with `fork()` and image replacement with `execve()`
- Built-in environment management (`cd`, `setenv`, `unsetenv`, `env`, `exit`)
- Return code tracking and error status reporting

## Build & Execution

```sh
make
./mysh
```
