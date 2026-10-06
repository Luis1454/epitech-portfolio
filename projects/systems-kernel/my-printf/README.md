# my_printf — Zero-Allocation Formatted Output Engine

Complete reimplementation of the standard C library `printf` formatted I/O function, handling variadic argument lists with custom buffer management.

## Technical Overview

- **Primary Stack:** C (C99), POSIX
- **Core Language:** C

## Key Architecture & Features

- Format specifiers: `%d`, `%i`, `%u`, `%s`, `%c`, `%x`, `%X`, `%o`, `%p`, `%b` (binary)
- Flag modifiers: `#`, `+`, `-`, `0`, space, and precision specifiers
- Variadic argument parsing via `stdarg.h` (`va_start`, `va_arg`, `va_end`)
- Zero external library dependency, direct buffered `write(2)` syscalls

## Build & Execution

```sh
make
```
