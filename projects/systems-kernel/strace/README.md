# strace — Linux System Call Interception & Tracing Engine

Native Linux binary introspection utility intercepting kernel system calls, signal deliveries, and process state transitions using `ptrace(2)` and ELF64 architecture inspection.

## Technical Overview

- **Primary Stack:** C, Linux Kernel Interfaces (`sys/ptrace.h`, `sys/user.h`), POSIX
- **Core Language:** C

## Key Architecture & Features

- Process attachment and child execution monitoring via `PTRACE_TRACEME` and `PTRACE_SYSCALL`
- Architecture-specific register extraction (`user_regs_struct` on AMD64)
- System call identification and parameter formatting (file descriptors, memory addresses, buffer lengths)
- Signal trapping and process exit code propagation
- Return value formatting and error number stringification

## Build & Execution

```sh
make
./strace /bin/ls
```
