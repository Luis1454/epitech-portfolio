# Systems & Kernel Software

Low-level systems programming, operating system interfaces, binary analysis, and runtime introspection.

## Projects

| Project | Description | Core Stack |
| --- | --- | --- |
| [42sh](42sh/) | POSIX-compliant Unix shell with AST parser, multi-process pipeline execution, and job control. | C, POSIX, AST |
| [asm-minilibc](asm-minilibc/) | Clean-room libc memory and string primitives in pure x86-64 assembly (System V AMD64 ABI). | x86-64 ASM, System V ABI |
| [strace](strace/) | Linux system call interception utility using `ptrace(2)` and register extraction. | C, ptrace, Linux Kernel |
| [nm-objdump](nm-objdump/) | ELF64 binary analyzer parsing section headers, symbol tables (`.symtab`), and string tables. | C, ELF64, mmap |
| [ftrace](ftrace/) | Dynamic function call and stack depth tracer correlating instruction pointers with ELF symbols. | C, ptrace, ELF |
| [minishell2](minishell2/) | Advanced Unix process tree orchestrator supporting arbitrary pipe cascades and redirections. | C, fork/execve, pipes |
| [minishell1](minishell1/) | Fundamental command interpreter with process lifecycle management and environment tracking. | C, POSIX |
| [my-ls](my-ls/) | High-performance directory listing utility reproducing GNU `ls` with permissions and metadata. | C, stat, dirent |
| [my-printf](my-printf/) | Zero-allocation formatted output engine reimplementing `printf` with variadic arguments. | C, variadic args |
| [navy](navy/) | Terminal battleship game communicating entirely via POSIX signals (`SIGUSR1`, `SIGUSR2`). | C, POSIX signals |
