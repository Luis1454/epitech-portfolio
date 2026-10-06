# ftrace — Dynamic Function Call & Call Graph Tracer

Process execution tracer capturing user-space function calls, shared library jumps, and system call boundaries using runtime software breakpoints and symbol resolution.

## Technical Overview

- **Primary Stack:** C, Linux ptrace, ELF introspection, POSIX
- **Core Language:** C

## Key Architecture & Features

- Real-time function entry and exit interception
- Symbol resolution correlating instruction pointers (`%rip`) with ELF symbol tables
- System call tracing integrated with user-level call stack indentation
- Child process execution monitoring and stack depth tracking

## Build & Execution

```sh
make
./ftrace /bin/ls
```
