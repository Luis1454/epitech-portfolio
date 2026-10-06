# Networking, Concurrency, IPC & Distributed DevOps

This directory contains **4 implementations** in the `network-devops` engineering domain.

| Project | Title / Description | Files |
| :--- | :--- | :---: |
| [`panoramix`](./panoramix/) | **Panoramix — Concurrent Multithreading & Semaphore Synchronization</strong><br>Multi-threaded synchronization engine modeling the classic Sleeping Druid / Hungry Villagers concurrency problem using POSIX threads, mutexes, and semaphores. | `7` |
| [`popeye`](./popeye/) | **Popeye — Multi-Service Microservices Containerization</strong><br>Enterprise multi-service voting application containerized using Docker, Docker Compose, and multi-stage container builds. | `20` |
| [`the-plazza`](./the-plazza/) | **The Plazza — Concurrency, Multiprocess IPC & Dynamic Thread Pools</strong><br>The Plazza simulates a high-throughput order dispatching and processing facility. A main reception engine receives order inputs, analyzes workload metrics, and dynamically spawns kitchen subprocesses. Each kitchen manages a fixed thread pool to cook items concurrently while IPC channels maintain bidirectional state synchronization. | `40` |
| [`zappy`](./zappy/) | **Zappy — High-Throughput Networked Simulation & Autonomous AI Protocol</strong><br>Zappy models an alien civilization surviving on a grid-based resource world (`Trantor`). The system comprises three independently communicating components synchronized via a strict custom TCP protocol: | `196` |
