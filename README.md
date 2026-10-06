# Luis Fernandes — Engineering Portfolio & Technical Implementations

Curated, production-grade systems software, numerical simulations, algorithms, and distributed engineering implementations.

Each project is organized by engineering domain, self-contained, and documented with an architectural overview, specifications, and build instructions.

---

## 🧭 Engineering Domains Overview

| Domain | Scope | Projects | Entry Point |
| :--- | :--- | :---: | :--- |
| **Systems Programming, Kernel Mechanics & Unix Internals** | `systems-kernel` | **11** | [`projects/systems-kernel/`](./projects/systems-kernel/) |
| **Simulations, Graphics, Physics Engines & High-Performance Computing** | `simulations-hpc` | **11** | [`projects/simulations-hpc/`](./projects/simulations-hpc/) |
| **Algorithms, Data Structures, Autonomous Agents & Machine Learning** | `algorithms-ai` | **15** | [`projects/algorithms-ai/`](./projects/algorithms-ai/) |
| **Networking, Concurrency, IPC & Distributed DevOps** | `network-devops` | **5** | [`projects/network-devops/`](./projects/network-devops/) |
| **Scientific Computing, Numerical Methods & Statistical Analysis** | `scientific-computing` | **6** | [`projects/scientific-computing/`](./projects/scientific-computing/) |
| **Distributed Systems, Consensus Protocols & Binary Partitioning** | `distributed-systems` | **1** | [`projects/distributed-systems/`](./projects/distributed-systems/) |
| **Core Language Foundations & Systems Programming Mechanics** | `foundations` | **2** | [`projects/foundations/`](./projects/foundations/) |

**Total implementations:** 51 verified projects across 7 engineering domains.

---

## ⚡ Featured Engineering Implementations

### 1. [Corewar](./projects/systems-kernel/corewar/) (`systems-kernel`)
A low-level virtual machine execution environment and two-pass bytecode assembler in C. Executes competing champions in a circular 6 KB memory arena with simulated CPU registers, cycle cost scheduling, and process branching (`fork`, `lfork`).

### 2. [R-Type](./projects/simulations-hpc/rtype/) (`simulations-hpc`)
Cross-platform networked multiplayer space shooter engine in modern C++20 architected on a custom Entity-Component-System (ECS) registry pattern with non-blocking UDP/TCP client-server state replication and SFML rendering.

### 3. [Arcade](./projects/simulations-hpc/arcade/) (`simulations-hpc`)
Modular gaming engine in modern C++ decoupling core game logic from graphical renderers. Dynamically loads display libraries (SFML, SDL2, NCurses) and games (Snake, Nibbler, Pacman) at runtime via `dlopen`/`dlsym` without recompilation.

### 4. [Zappy](./projects/network-devops/zappy/) (`network-devops`)
Distributed real-time networked simulation featuring an asynchronous TCP multiplexed server in C using `select`/`poll`, autonomous multi-agent AI ecosystems, and a 3D hardware-accelerated viewer.

### 5. [The Plazza](./projects/network-devops/the-plazza/) (`network-devops`)
Concurrent multiprocess, multithreaded task orchestration system in C++. Features dynamic subprocess lifecycle management, bidirectional IPC (named pipes, message queues), and kitchen thread pool scheduling.

### 6. [42sh](./projects/systems-kernel/42sh/) (`systems-kernel`)
POSIX-compliant Unix shell in C featuring abstract syntax tree (AST) lexical parsing, multi-stage piping, job control, environment variables, globbing, history, and shell builtins.

### 7. [Relativistic Raytracer](./projects/simulations-hpc/relativistic-raytracer/) (`simulations-hpc`)
Curved-spacetime optical raytracer numerically integrating null geodesic differential equations under General Relativity around spinning Kerr black holes using Runge-Kutta 4th order (RK4).

### 8. [Silicium Network](./projects/distributed-systems/silicium-eip/) (`distributed-systems`)
High-throughput distributed compute grid harnessing low-power IoT devices via Solana (Rust/Anchor). Employs recursive task delegation (<128 KB footprint) and a containerized C++ ELF binary partitioner.

---

## 📚 Complete Project Index (51 Implementations)

| Domain | Project | Description | Stack |
| :--- | :--- | :--- | :--- |
| `algorithms-ai` | [`antman-compression`](./projects/algorithms-ai/antman-compression/) | **Antman — Multi-Format Lossless Data Compression</strong><br>Custom lossless data compression and decompression engine targeting text, HTML, and PBM image data via dictionary encoding and frequency-based bit packing. | `87 files` |
| `algorithms-ai` | [`bistromatic`](./projects/algorithms-ai/bistromatic/) | **Bistromatic — Arbitrary-Precision BigInt Arithmetic Engine</strong><br>Bistromatic evaluates deeply nested arithmetic expressions involving numbers of infinite length (constrained only by available system RAM). It features custom big-integer addition, subtraction, multiplication, division, and modulo routines, paired with an operator-precedence expression evaluator. | `50 files` |
| `algorithms-ai` | [`bsq`](./projects/algorithms-ai/bsq/) | **BSQ — Dynamic Programming Maximal Square Finder</strong><br>High-performance 2D grid processing algorithm finding the largest unobstructed square on a map containing arbitrary obstacles. | `93 files` |
| `algorithms-ai` | [`cryptography`](./projects/algorithms-ai/cryptography/) | **Cryptography — Symmetric & Asymmetric Cipher Toolkit</strong><br>This repository provides foundational implementations of both symmetric and asymmetric encryption schemes. It emphasizes clean mathematical formulations, modular arithmetic operations, and cryptanalytic tooling to demonstrate vulnerability vectors in weak cipher designs. | `7 files` |
| `algorithms-ai` | [`dante-star`](./projects/algorithms-ai/dante-star/) | **Dante's Star — Maze Generator & A* / Dijkstra Pathfinding Engine</strong><br>High-throughput maze generator creating perfect and imperfect 2D labyrinths paired with optimized A* and Dijkstra pathfinding solvers. | `1 files` |
| `algorithms-ai` | [`evalexpr`](./projects/algorithms-ai/evalexpr/) | **EvalExpr — Recursive Descent Expression Parser & AST Evaluation</strong><br>EvalExpr computes mathematical expressions directly from a character string. By utilizing a recursive descent grammar parser, it eliminates the need for external parsing generators or postfix conversion passes, evaluating values in a single recursive traversal. | `40 files` |
| `algorithms-ai` | [`fastatools`](./projects/algorithms-ai/fastatools/) | **FASTAtools — Genomic Sequence Analysis & k-mer Toolkit</strong><br>High-throughput bioinformatics command-line utility analyzing FASTA-formatted DNA and RNA sequences, computing k-mer frequencies, and detecting coding sequences. | `105 files` |
| `algorithms-ai` | [`gomoku-ai`](./projects/algorithms-ai/gomoku-ai/) | **Gomoku AI — Tournament Adversarial Game Engine</strong><br>High-performance Gomoku (Five-in-a-Row) game engine designed for competitive tournament play under the Gomocup protocol. Employs Minimax search with Alpha-Beta pruning, bitboard representations, and heuristic pattern evaluation. | `9 files` |
| `algorithms-ai` | [`infinadd`](./projects/algorithms-ai/infinadd/) | **InfinAdd — Arbitrary-Precision BigInt Arithmetic Engine</strong><br>Arbitrary-precision arithmetic utility performing addition and subtraction on arbitrarily long numerical strings beyond hardware register bounds. | `39 files` |
| `algorithms-ai` | [`lemin`](./projects/algorithms-ai/lemin/) | **Lem-In — Network Flow Pathfinding & Graph Optimization</strong><br>Graph optimization engine solving maximum network flow problems for ant colony routing through a network of connected rooms and tunnels. | `3 files` |
| `algorithms-ai` | [`n4s-autonomous`](./projects/algorithms-ai/n4s-autonomous/) | **Need4Stek — Autonomous Vehicle Lidar Controller</strong><br>Autonomous vehicle control algorithm driving a simulated car through complex tracks by analyzing real-time 32-beam lidar distance streams and computing adaptive PID steering and speed commands. | `1 files` |
| `algorithms-ai` | [`neural-network`](./projects/algorithms-ai/neural-network/) | **Neural Network — Multi-Layer Perceptron & Gradient Descent from Scratch</strong><br>This project implements a multi-layer feedforward perceptron designed for classification and regression tasks. It implements matrix mathematical operations, activation functions, and reverse-mode automatic differentiation (backpropagation) to optimize network weights via stochastic gradient descent. | `14 files` |
| `algorithms-ai` | [`pushswap`](./projects/algorithms-ai/pushswap/) | **Pushswap — Constrained Double-Stack Sorting Optimization</strong><br>Highly constrained algorithmic sorting challenge sorting a list of integers across two stacks (l_a and l_b) using a restricted instruction set (sa, sb, pa, pb, ra, rb, rra, rrb). | `97 files` |
| `algorithms-ai` | [`sokoban`](./projects/algorithms-ai/sokoban/) | **Sokoban — Terminal Warehouse Puzzle Engine</strong><br>Terminal warehouse box-pushing puzzle engine featuring map validation, real-time keyboard interaction, collision detection, and win/loss condition tracking. | `97 files` |
| `algorithms-ai` | [`trade`](./projects/algorithms-ai/trade/) | **Trade — Real-Time Algorithmic Trading Bot & Market Signal Analysis</strong><br>Trade interacts with simulated or live market exchange APIs, processing tick and candlestick data in real time. It computes technical indicators across rolling windows to detect momentum shifts, trend reversals, and breakout opportunities, automatically issuing market and limit orders. | `51 files` |
| `distributed-systems` | [`silicium-eip`](./projects/distributed-systems/silicium-eip/) | **Silicium Network — Decentralized IoT Compute & ELF Partitioner</strong><br>High-throughput distributed computing protocol harnessing low-power IoT devices via Solana and Anchor. Features a containerized C++ ELF binary partitioner and recursive task delegation protocols. | `538 files` |
| `foundations` | [`c-pool`](./projects/foundations/c-pool/) | **C Systems Programming Foundations & Algorithms</strong><br>Comprehensive foundational implementation suite covering standard C library recreation, memory manipulation, string algorithms, linked structures, and binary utilities. | `616 files` |
| `foundations` | [`cpp-pool`](./projects/foundations/cpp-pool/) | **Modern C++ Object-Oriented Systems & Templates</strong><br>Modern C++ progression covering RAII resource management, object-oriented encapsulation, polymorphism, operator overloading, and template metaprogramming. | `172 files` |
| `network-devops` | [`myftp`](./projects/network-devops/myftp/) | **myFTP — RFC 959 BSD Socket FTP Server</strong><br>RFC 959-compliant File Transfer Protocol (FTP) server supporting concurrent multi-client connections over TCP/IP sockets with passive and active data transmission modes. | `1 files` |
| `network-devops` | [`panoramix`](./projects/network-devops/panoramix/) | **Panoramix — Concurrent Multithreading & Semaphore Synchronization</strong><br>Multi-threaded synchronization engine modeling the classic Sleeping Druid / Hungry Villagers concurrency problem using POSIX threads, mutexes, and semaphores. | `7 files` |
| `network-devops` | [`popeye`](./projects/network-devops/popeye/) | **Popeye — Multi-Service Microservices Containerization</strong><br>Enterprise multi-service voting application containerized using Docker, Docker Compose, and multi-stage container builds. | `20 files` |
| `network-devops` | [`the-plazza`](./projects/network-devops/the-plazza/) | **The Plazza — Concurrency, Multiprocess IPC & Dynamic Thread Pools</strong><br>The Plazza simulates a high-throughput order dispatching and processing facility. A main reception engine receives order inputs, analyzes workload metrics, and dynamically spawns kitchen subprocesses. Each kitchen manages a fixed thread pool to cook items concurrently while IPC channels maintain bidirectional state synchronization. | `40 files` |
| `network-devops` | [`zappy`](./projects/network-devops/zappy/) | **Zappy — High-Throughput Networked Simulation & Autonomous AI Protocol</strong><br>Zappy models an alien civilization surviving on a grid-based resource world (`Trantor`). The system comprises three independently communicating components synchronized via a strict custom TCP protocol: | `196 files` |
| `scientific-computing` | [`109titration`](./projects/scientific-computing/109titration/) | **109titration — Chemical pH Curve Numerical Derivative Analysis</strong><br>Computational chemistry utility calculating equivalence points in acid-base titration experiments using cubic spline interpolation and numerical differentiation. | `2 files` |
| `scientific-computing` | [`groundhog`](./projects/scientific-computing/groundhog/) | **Groundhog — Real-Time Financial & Environmental Trend Analysis</strong><br>Real-time rolling telemetry stream processor detecting trend switches, standard deviations, and temperature switches across temporal data feeds. | `6 files` |
| `scientific-computing` | [`math-algorithms`](./projects/scientific-computing/math-algorithms/) | **Numerical Mathematics & Scientific Algorithms</strong><br>Collection of applied numerical computing and scientific calculation utilities in Python and C. | `119 files` |
| `scientific-computing` | [`palindrome`](./projects/scientific-computing/palindrome/) | **Palindrome — Numerical Base Transformation & Palindrome Solver</strong><br>Number theory utility computing forward and reverse palindrome iteration counts across various numerical bases (from base 2 to base 36). | `95 files` |
| `scientific-computing` | [`projtester`](./projects/scientific-computing/projtester/) | **ProjTester — Automated Binary Integration Testing Framework</strong><br>Automated black-box test runner validating binary standard output, error streams, and exit codes against expected reference specifications. | `97 files` |
| `scientific-computing` | [`sbmlparser`](./projects/scientific-computing/sbmlparser/) | **SBML Parser — Systems Biology Markup Language Analyzer</strong><br>XML lexical parser and analyzer for Systems Biology Markup Language (SBML) files, extracting biochemical species, compartments, and kinetic reactions. | `106 files` |
| `simulations-hpc` | [`arcade`](./projects/simulations-hpc/arcade/) | **Arcade — Modular Gaming Platform & Dynamic Graphic Libraries</strong><br>Arcade solves the problem of cross-toolkit graphics abstraction by operating entirely through dynamic shared libraries loaded at runtime (`dlopen(3)`, `dlsym(3)`). The core engine manages event dispatching and entity states, allowing users to switch graphic libraries (e.g. from SFML to SDL2 or an NCurses terminal interface) and game cartridges (Snake, Nibbler, Pacman) on the fly without restarting or recompiling. | `34 files` |
| `simulations-hpc` | [`myhunter`](./projects/simulations-hpc/myhunter/) | **myHunter — 2D Arcade Game Engine & Sprite Animation</strong><br>2D Arcade shooter featuring hardware-accelerated sprite animation, event-driven user interaction, frame rate regulation, and high-score tracking. | `104 files` |
| `simulations-hpc` | [`mypaint`](./projects/simulations-hpc/mypaint/) | **myPaint — 2D Raster Graphics & Canvas Editor</strong><br>GUI drawing application featuring modular tool palettes, layer manipulation, custom brush dynamics, and color selection. | `123 files` |
| `simulations-hpc` | [`myradar`](./projects/simulations-hpc/myradar/) | **myRadar — Real-Time Air Traffic Radar & Collision Simulation</strong><br>2D Air traffic control simulation visualizing flight trajectories, control tower radii, and real-time aircraft collision detection using spatial Quadtree partitioning. | `128 files` |
| `simulations-hpc` | [`myrpg`](./projects/simulations-hpc/myrpg/) | **myRPG — 2D Role-Playing Game Engine & Real-Time Event Loop</strong><br>myRPG is an interactive role-playing game developed from first principles in C. The architecture isolates the rendering loop, input handling, entity management, and user interface layers, delivering smooth 60 FPS performance with custom particle emitters and modular dialogue systems. | `135 files` |
| `simulations-hpc` | [`myworld`](./projects/simulations-hpc/myworld/) | **myWorld — 3D Isometric Terrain Modeling & Heightmap Engine</strong><br>myWorld allows users to generate, visualize, and sculpt three-dimensional terrain maps in real time. It calculates mathematical projections to transform 3D grid vertices into a 2D isometric viewport, providing intuitive elevation controls and texture mapping. | `55 files` |
| `simulations-hpc` | [`relativistic-raytracer`](./projects/simulations-hpc/relativistic-raytracer/) | **Relativistic Raytracer — Curved Spacetime Geodesic Engine</strong><br>Optical raytracing simulation modeling photon trajectories along null geodesics in curved spacetime metrics (Schwarzschild and Kerr black holes) using numerical differential integrators. | `1 files` |
| `simulations-hpc` | [`rtype`](./projects/simulations-hpc/rtype/) | **R-Type — Cross-Platform Multiplayer Networked Game Engine (ECS)</strong><br>R-Type replicates the classic side-scrolling arcade shooter as a distributed, networked multiplayer platform. The engine is architected around an in-house Entity-Component-System (ECS) model to ensure deterministic game state updates, high cache locality, and scalable concurrency across client and server runtimes. | `142 files` |
| `simulations-hpc` | [`screensaver`](./projects/simulations-hpc/screensaver/) | **MyScreensaver — Real-Time Procedural Graphics Animation</strong><br>Modular real-time screensaver rendering procedural visual animations, trigonometric waves, and particle physics in CSFML. | `11 files` |
| `simulations-hpc` | [`tekspice`](./projects/simulations-hpc/tekspice/) | **TekSpice — Discrete Electronic & Digital Logic Circuit Simulator</strong><br>Object-oriented discrete electronic component and digital logic circuit simulation engine in C++20. Parses Netlist component topologies and evaluates cyclic graph state propagation across discrete clock cycles. | `57 files` |
| `simulations-hpc` | [`tetris`](./projects/simulations-hpc/tetris/) | **Tetris — Terminal Grid Engine & NCurses Event Loop</strong><br>This implementation features a robust terminal UI engine running in raw terminal mode, completely detached from line buffering. It dynamically loads external tetromino shape definition files, validates geometries, and drives standard game mechanics (rotation, line clears, score scaling, speed ramping). | `54 files` |
| `systems-kernel` | [`42sh`](./projects/systems-kernel/42sh/) | **42sh — POSIX-Compliant Unix Shell Architecture</strong><br>Complete Unix command language interpreter engineered in C. Features Abstract Syntax Tree (AST) lexical parsing, multi-process pipeline orchestration, signal handling, and interactive terminal job control. | `1 files` |
| `systems-kernel` | [`asm-minilibc`](./projects/systems-kernel/asm-minilibc/) | **ASM MiniLibC — Pure x86-64 Low-Level Assembly Primitives</strong><br>Clean-room implementation of standard C library memory and string primitives written entirely in pure x86-64 assembly, strictly adhering to the System V AMD64 ABI specification. | `14 files` |
| `systems-kernel` | [`corewar`](./projects/systems-kernel/corewar/) | **Corewar — Virtual Machine, Bytecode Assembler & Memory Arena</strong><br>Corewar is composed of two primary subsystems: | `140 files` |
| `systems-kernel` | [`ftrace`](./projects/systems-kernel/ftrace/) | **ftrace — Dynamic Function Call & Call Graph Tracer</strong><br>Process execution tracer capturing user-space function calls, shared library jumps, and system call boundaries using runtime software breakpoints and symbol resolution. | `1 files` |
| `systems-kernel` | [`minishell1`](./projects/systems-kernel/minishell1/) | **Minishell 1 — Unix Process Lifecycle & Command Interpreter</strong><br>Fundamental Unix shell engine handling user input tokenization, child process execution lifecycle, PATH resolution, and built-in commands. | `97 files` |
| `systems-kernel` | [`minishell2`](./projects/systems-kernel/minishell2/) | **Minishell 2 — Multi-Stage Unix Process & Pipe Orchestrator</strong><br>Advanced Unix command interpreter supporting inter-process communication pipelines, file descriptor redirection, and persistent environment variable management. | `100 files` |
| `systems-kernel` | [`my-ls`](./projects/systems-kernel/my-ls/) | **my_ls — POSIX Directory Stream & File Metadata Lister</strong><br>High-performance directory listing utility reproducing GNU `ls` behavior. Queries filesystem metadata, formats permissions, file owners, modification timestamps, and directory hierarchies. | `103 files` |
| `systems-kernel` | [`my-printf`](./projects/systems-kernel/my-printf/) | **my_printf — Zero-Allocation Formatted Output Engine</strong><br>Complete reimplementation of the standard C library `printf` formatted I/O function, handling variadic argument lists with custom buffer management. | `88 files` |
| `systems-kernel` | [`navy`](./projects/systems-kernel/navy/) | **Navy — Inter-Process Terminal Battleship via POSIX Signals</strong><br>Terminal-based multiplayer Battleship game communicating strictly through POSIX user signals (`SIGUSR1` and `SIGUSR2`) without network sockets or pipes. | `96 files` |
| `systems-kernel` | [`nm-objdump`](./projects/systems-kernel/nm-objdump/) | **nm & objdump — ELF64 Binary Format Introspector</strong><br>Binary inspection toolchain analyzing Executable and Linkable Format (ELF64) files. Decodes section headers, symbol tables (`.symtab`), string tables (`.strtab`), and memory segment layouts. | `18 files` |
| `systems-kernel` | [`strace`](./projects/systems-kernel/strace/) | **strace — Linux System Call Interception & Tracing Engine</strong><br>Native Linux binary introspection utility intercepting kernel system calls, signal deliveries, and process state transitions using `ptrace(2)` and ELF64 architecture inspection. | `7 files` |

---

## 🛠 Engineering Principles

- **Memory Safety & Determinism:** Zero unhandled memory leaks, rigorous Valgrind validation, and strict RAII in C++.
- **System V AMD64 ABI & POSIX Conformance:** Low-level assembly primitives, syscall interception, and standard POSIX interface adherence.
- **High Performance & Cache Locality:** Data-oriented design, custom memory arenas, and non-blocking asynchronous multiplexing.
- **Modular Decoupling:** Strict separation of concerns, plugin interfaces, and standalone compilation targets.

---

## 📬 Contact

- **Website:** [luisfernandes.tech](https://luisfernandes.tech)
- **LinkedIn:** [linkedin.com/in/luisfernandes-eng](https://www.linkedin.com/in/luisfernandes-eng)
- **GitHub:** [github.com/Luis1454](https://github.com/Luis1454)
- **Email:** luis.fernandes.contact@gmail.com
