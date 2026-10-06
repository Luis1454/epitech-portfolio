# my_ls — POSIX Directory Stream & File Metadata Lister

High-performance directory listing utility reproducing GNU `ls` behavior. Queries filesystem metadata, formats permissions, file owners, modification timestamps, and directory hierarchies.

## Technical Overview

- **Primary Stack:** C, POSIX filesystem interfaces
- **Core Language:** C

## Key Architecture & Features

- Flags support: `-l` (long listing), `-R` (recursive traversal), `-d` (directory only), `-r` (reverse sort), `-t` (time-based sort), `-a` (hidden files)
- POSIX file metadata extraction using `stat(2)` and `lstat(2)`
- Directory stream reading via `opendir(3)` and `readdir(3)`
- File permission octal-to-string formatting (`drwxr-xr-x`)

## Build & Execution

```sh
make
./my_ls -la
```
