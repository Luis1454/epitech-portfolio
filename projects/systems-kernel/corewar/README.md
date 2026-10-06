# Corewar — Virtual Machine, Bytecode Assembler & Memory Arena

A low-level virtual machine execution environment, two-pass champion assembler, and instruction interpreter written in C. Simulates an isolated memory arena where competing compiled champion bytecodes fight for survival by executing instructions in real time.

## Overview

Corewar is composed of two primary subsystems:
1. **The Assembler (`asm`):** A compiler translating human-readable champion assembly source code (`.s`) into compact bytecode binaries (`.cor`), verifying header magic numbers, instruction validity, and parameter encodings.
2. **The Virtual Machine (`corewar`):** A CPU emulator that instantiates a 6 KB circular memory arena (`MEM_SIZE`), schedules concurrent champion execution threads with instruction cycle delays, and tracks live signals.

## Architecture & Technical Highlights

- **Two-Pass Lexer & Assembler:** Validates champion name/comment metadata, computes label relative offsets, and generates binary bytecode with instruction opcode tables and parameter coding bytes (PCB).
- **Circular Memory Arena:** 6,144-byte continuous circular RAM buffer (`MEM_SIZE = 6144`) where champion bytecodes are loaded with calculated spacing.
- **Instruction Cycle Scheduler:** Accurate cycle execution simulation handling 16 machine instructions (`live`, `ld`, `st`, `add`, `sub`, `and`, `or`, `xor`, `zjmp`, `ldi`, `sti`, `fork`, `lld`, `lldi`, `lfork`, `aff`) with specific cycle costs and instruction pointer wrapping.
- **Process Spawning & Threading:** Reentrant champion process list supporting programmatic branching (`fork`, `lfork`) with copied register banks (`REG_NUMBER = 16`).

## Tech Stack

- **Language:** C (C99 / C11, System V AMD64 ABI)
- **Compiler Flags:** `-Wall -Wextra -Werror -pedantic`
- **Build System:** GNU Make

## Build & Execution

```bash
# Compile assembler and virtual machine
make

# Assemble champion source files
./asm/asm champions/abel.s

# Run virtual machine with competing champions
./corewar/corewar -dump 1000 champions/abel.cor champions/bill.cor
```
