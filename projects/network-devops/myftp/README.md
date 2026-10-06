# myFTP — RFC 959 BSD Socket FTP Server

RFC 959-compliant File Transfer Protocol (FTP) server supporting concurrent multi-client connections over TCP/IP sockets with passive and active data transmission modes.

## Technical Overview

- **Primary Stack:** C, BSD Sockets (`sys/socket.h`), I/O Multiplexing, POSIX
- **Core Language:** C

## Key Architecture & Features

- I/O multiplexing utilizing `select(2)` and `poll(2)` for non-blocking client concurrency
- Complete RFC 959 command implementation: USER, PASS, CWD, CDUP, QUIT, DELE, PWD, PASV, PORT, HELP, NOOP, RETR, STOR, LIST
- Dual data connection architecture: Active (`PORT`) and Passive (`PASV`) data sockets
- Strict authentication and filesystem access sandbox

## Build & Execution

```sh
make
./myftp 4242 /path/to/share
```
