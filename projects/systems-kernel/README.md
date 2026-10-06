# Systems Programming, Kernel Mechanics & Low-Level Foundations

This directory contains **11 implementations** in the `systems-kernel` engineering domain.

| Project | Title / Description | Files |
| :--- | :--- | :---: |
| [`42sh`](./42sh/) | **42sh — POSIX-Compliant Unix Shell Architecture</strong><br>Complete Unix command language interpreter engineered in C. Features Abstract Syntax Tree (AST) lexical parsing, multi-process pipeline orchestration, signal handling, and interactive terminal job control. | `109` |
| [`asm-minilibc`](./asm-minilibc/) | **ASM MiniLibC — Pure x86-64 Low-Level Assembly Primitives</strong><br>Clean-room implementation of standard C library memory and string primitives written entirely in pure x86-64 assembly, strictly adhering to the System V AMD64 ABI specification. | `14` |
| [`corewar`](./corewar/) | **Corewar — Virtual Machine, Bytecode Assembler & Memory Arena</strong><br>Corewar is composed of two primary subsystems: | `140` |
| [`ftrace`](./ftrace/) | **ftrace — Dynamic Function Call & Call Graph Tracer</strong><br>Process execution tracer capturing user-space function calls, shared library jumps, and system call boundaries using runtime software breakpoints and symbol resolution. | `26` |
| [`minishell1`](./minishell1/) | **Minishell 1 — Unix Process Lifecycle & Command Interpreter</strong><br>Fundamental Unix shell engine handling user input tokenization, child process execution lifecycle, PATH resolution, and built-in commands. | `97` |
| [`minishell2`](./minishell2/) | **Minishell 2 — Multi-Stage Unix Process & Pipe Orchestrator</strong><br>Advanced Unix command interpreter supporting inter-process communication pipelines, file descriptor redirection, and persistent environment variable management. | `100` |
| [`my-ls`](./my-ls/) | **my_ls — POSIX Directory Stream & File Metadata Lister</strong><br>High-performance directory listing utility reproducing GNU `ls` behavior. Queries filesystem metadata, formats permissions, file owners, modification timestamps, and directory hierarchies. | `103` |
| [`my-printf`](./my-printf/) | **my_printf — Zero-Allocation Formatted Output Engine</strong><br>Complete reimplementation of the standard C library `printf` formatted I/O function, handling variadic argument lists with custom buffer management. | `88` |
| [`navy`](./navy/) | **Navy — Inter-Process Terminal Battleship via POSIX Signals</strong><br>Terminal-based multiplayer Battleship game communicating strictly through POSIX user signals (`SIGUSR1` and `SIGUSR2`) without network sockets or pipes. | `96` |
| [`nm-objdump`](./nm-objdump/) | **nm & objdump — ELF64 Binary Format Introspector</strong><br>Binary inspection toolchain analyzing Executable and Linkable Format (ELF64) files. Decodes section headers, symbol tables (`.symtab`), string tables (`.strtab`), and memory segment layouts. | `18` |
| [`strace`](./strace/) | **strace — Linux System Call Interception & Tracing Engine</strong><br>Native Linux binary introspection utility intercepting kernel system calls, signal deliveries, and process state transitions using `ptrace(2)` and ELF64 architecture inspection. | `7` |
