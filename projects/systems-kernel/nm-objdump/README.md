# nm & objdump — ELF64 Binary Format Introspector

Binary inspection toolchain analyzing Executable and Linkable Format (ELF64) files. Decodes section headers, symbol tables (`.symtab`), string tables (`.strtab`), and memory segment layouts.

## Technical Overview

- **Primary Stack:** C, Linux ELF specification (`elf.h`), Memory-Mapped I/O (`mmap`)
- **Core Language:** C

## Key Architecture & Features

- Full ELF64 header validation (`e_ident` magic bytes, machine architecture, entrypoint)
- Section header table parsing (`Elf64_Shdr`) and mapping via `mmap(2)`
- Symbol table decoding (`Elf64_Sym`) with symbol binding and type determination (T, U, D, B, R)
- Section content hexadecimal and ASCII dumping mirroring GNU `objdump -fs`
- Robust error handling for corrupted binaries and architecture mismatches

## Build & Execution

```sh
make
./my_nm /bin/ls
./my_objdump /bin/ls
```
