# The Plazza — Concurrency, Multiprocess IPC & Dynamic Thread Pools

A multi-process, multi-threaded task orchestration system in C++ demonstrating asynchronous load balancing, inter-process communication (IPC), and thread pool execution.

## Overview

The Plazza simulates a high-throughput order dispatching and processing facility. A main reception engine receives order inputs, analyzes workload metrics, and dynamically spawns kitchen subprocesses. Each kitchen manages a fixed thread pool to cook items concurrently while IPC channels maintain bidirectional state synchronization.

## Architecture & Technical Highlights

- **Dynamic Kitchen Lifecycle:** Master reception process automatically forks new kitchen child processes when existing capacities are saturated, and terminates idle kitchens after inactivity timeouts.
- **Inter-Process Communication (IPC):** Bidirectional messaging between reception and kitchen nodes implemented using POSIX message queues and named pipes (`mkfifo`).
- **Thread Pool Architecture:** Each kitchen implements an internal worker thread pool with thread-safe task queues, protected by `std::mutex` and signaled via `std::condition_variable`.
- **Resource Management & Stock Tracking:** Shared ingredient replenishment threads simulating time-based stock regenerations with deadlock-free locking primitives.

## Tech Stack

- **Language:** Modern C++ (C++17 / C++20)
- **Concurrency:** `std::thread`, `std::mutex`, `std::condition_variable`, POSIX processes (`fork`, `waitpid`)
- **IPC:** Named Pipes (FIFO), Message Queues (`mq_open`, `mq_send`, `mq_receive`)
- **Build System:** GNU Make

## Build & Execution

```bash
# Compile system
make

# Execute with: multiplier factor, cooks per kitchen, ingredient refill time (ms)
./plazza 2 5 2000
```
