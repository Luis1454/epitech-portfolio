# Minishell 2 — Multi-Stage Unix Process & Pipe Orchestrator

Advanced Unix command interpreter supporting inter-process communication pipelines, file descriptor redirection, and persistent environment variable management.

## Technical Overview

- **Primary Stack:** C, POSIX process management (`fork`, `execve`, `waitpid`, `pipe`, `dup2`)
- **Core Language:** C

## Key Architecture & Features

- Arbitrary-length pipe cascades (`cmd1 | cmd2 | cmd3 | ...`)
- File descriptor redirection (`>`, `>>`, `<`, `<<`)
- Signal handling preventing shell exit upon child abnormal termination
- Dynamic command execution path resolution via `PATH` parsing

## Build & Execution

```sh
make
./mysh
```
