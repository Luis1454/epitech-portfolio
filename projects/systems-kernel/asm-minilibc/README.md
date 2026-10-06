# ASM MiniLibC — Pure x86-64 Low-Level Assembly Primitives

Clean-room implementation of standard C library memory and string primitives written entirely in pure x86-64 assembly, strictly adhering to the System V AMD64 ABI specification.

## Technical Overview

- **Primary Stack:** x86-64 Assembly (NASM / Yasm), System V AMD64 ABI, ELF64 Shared Object
- **Core Language:** Assembly x86_64

## Key Architecture & Features

- Memory routines: `memcpy`, `memmove`, `memset`, `rindex`
- String operations: `strlen`, `strcmp`, `strncmp`, `strcasecmp`, `strchr`, `strstr`, `strpbrk`, `strcspn`
- Optimized register allocation leveraging scratch registers without stack overhead
- Direct kernel system call invocations (`SYS_read`, `SYS_write`)
- Compiled as shared object (`libasm.so`) usable across any Linux binary via `LD_PRELOAD`

## Build & Execution

```sh
make
LD_PRELOAD=./libasm.so ls -la
```
