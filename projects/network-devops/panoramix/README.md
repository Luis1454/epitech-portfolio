# Panoramix — Concurrent Multithreading & Semaphore Synchronization

Multi-threaded synchronization engine modeling the classic Sleeping Druid / Hungry Villagers concurrency problem using POSIX threads, mutexes, and semaphores.

## Technical Overview

- **Primary Stack:** C, POSIX Threads (`pthreads`), Semaphores
- **Core Language:** C

## Key Architecture & Features

- Thread lifecycle management (`pthread_create`, `pthread_join`)
- Race condition prevention using mutexes (`pthread_mutex_t`)
- Resource signaling using condition variables and semaphores (`sem_t`)
- Clean shutdown and deadlock-free execution

## Build & Execution

```sh
make
./panoramix 3 5 4 2
```
