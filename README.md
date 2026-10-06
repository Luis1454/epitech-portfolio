# Engineering Project Portfolio — Luis Fernandes

> Systems & Embedded Software Engineer · HPC & Numerical Simulation · Low-Level Tooling

A curated engineering portfolio showcasing low-level systems programming, Linux kernel introspection, numerical simulations, algorithm optimization, and distributed architectures. All implementations prioritize deterministic execution, memory safety, hardware boundary awareness, and POSIX compliance.

---

## Technical Domains & Navigation

| Domain | Focus & Architecture | Key Technologies | Projects |
| --- | --- | --- | ---: |
| [Systems & Kernel](projects/systems-kernel/) | Unix process orchestration, ptrace interception, ELF introspection, libc ASM. | C, x86-64 ASM, POSIX, ptrace | 10 |
| [Simulations & HPC](projects/simulations-hpc/) | Discrete logic nets, curved-spacetime raytracing, Quadtree collision detection. | C++20, CSFML, RK4, Quadtree | 6 |
| [Algorithms & AI](projects/algorithms-ai/) | Minimax with Alpha-Beta, network flow, maze pathfinding, dynamic programming. | Python, C, Graph Theory, DP | 10 |
| [Network & DevOps](projects/network-devops/) | RFC 959 BSD socket servers, POSIX thread synchronization, containerization. | C, BSD Sockets, pthreads, Docker | 3 |
| [Scientific Computing](projects/scientific-computing/) | Cubic spline interpolation, time-series telemetry processing, SBML XML analysis. | Python 3, C, Numerical Analysis | 6 |
| [Distributed Systems](projects/distributed-systems/) | Decentralized IoT compute protocols, Solana smart contracts, ELF partitioners. | Rust, C++, Solana, Docker | 1 |
| [Foundations](projects/foundations/) | Intensive progressions covering core memory manipulation, pointer arithmetic, and modern C++. | C, C++20, STL, Shell | 2 |

---

## Featured Engineering Builds

### 1. [42sh — POSIX Unix Shell](projects/systems-kernel/42sh/)
Full-featured Unix command interpreter in C. Implements lexical analysis and recursive-descent parsing producing Abstract Syntax Trees (ASTs), arbitrary pipe cascades (`pipe`, `fork`, `dup2`), stream redirections, signal handling, and interactive job control.

### 2. [TekSpice — Digital Logic & Circuit Simulator](projects/simulations-hpc/tekspice/)
Object-oriented discrete electronic circuit simulation engine in C++20. Parses Netlist component topologies and evaluates cyclic graph state propagation across discrete clock cycles for CMOS 4000-series integrated circuits (adders, flip-flops, decade counters).

### 3. [ASM MiniLibC — x86-64 Low-Level Assembly Primitives](projects/systems-kernel/asm-minilibc/)
Clean-room implementation of standard C library memory and string primitives (`memcpy`, `memset`, `strlen`, `strcmp`, `strchr`, etc.) written entirely in pure x86-64 assembly under strict System V AMD64 ABI compliance. Compiles as a shared object injectable via `LD_PRELOAD`.

### 4. [strace & nm-objdump — Linux Binary Toolchain](projects/systems-kernel/strace/)
Native Linux binary introspection utilities. Intercepts system calls and signal deliveries using `ptrace(2)` register decoding, and analyzes ELF64 binary headers, section tables (`Elf64_Shdr`), and symbol tables (`.symtab`) via memory-mapped I/O (`mmap`).

### 5. [Gomoku AI — Tournament Adversarial Game Engine](projects/algorithms-ai/gomoku-ai/)
Competitive Gomoku (Five-in-a-Row) engine compliant with the Gomocup tournament protocol. Combines Minimax search with Alpha-Beta pruning, principal variation search, bitboard representations, and heuristic pattern evaluation under strict real-time turn limits.

---

## Complete Project Index

| Project | Domain | Stack | Description |
| --- | --- | --- | --- |
| [42sh](projects/systems-kernel/42sh/) | Systems & Kernel | C, POSIX, AST | POSIX Unix shell with AST parser, pipe pipelines, and job control. |
| [ASM MiniLibC](projects/systems-kernel/asm-minilibc/) | Systems & Kernel | x86-64 ASM, System V ABI | Memory and string libc primitives in pure x86-64 assembly. |
| [strace](projects/systems-kernel/strace/) | Systems & Kernel | C, ptrace, Linux Kernel | Kernel system call tracer using `ptrace(2)` and register extraction. |
| [nm-objdump](projects/systems-kernel/nm-objdump/) | Systems & Kernel | C, ELF64, mmap | ELF64 binary introspector parsing sections, `.symtab`, and symbol bindings. |
| [ftrace](projects/systems-kernel/ftrace/) | Systems & Kernel | C, ptrace, ELF | Dynamic function call and stack depth tracer for user/kernel transitions. |
| [Minishell 2](projects/systems-kernel/minishell2/) | Systems & Kernel | C, fork/execve, pipes | Unix process tree orchestrator handling pipe cascades and redirections. |
| [Minishell 1](projects/systems-kernel/minishell1/) | Systems & Kernel | C, POSIX | Process lifecycle command interpreter with PATH resolution. |
| [my_ls](projects/systems-kernel/my-ls/) | Systems & Kernel | C, stat, dirent | Directory listing utility reproducing GNU `ls` with file metadata and sorting. |
| [my_printf](projects/systems-kernel/my-printf/) | Systems & Kernel | C, variadic args | Zero-allocation formatted output engine reimplementing `printf`. |
| [Navy](projects/systems-kernel/navy/) | Systems & Kernel | C, POSIX signals | Terminal multiplayer game communicating via `SIGUSR1`/`SIGUSR2` signals. |
| [TekSpice](projects/simulations-hpc/tekspice/) | Simulations & HPC | C++20, Logic Netlists | Discrete electronic circuit and logic gate simulator evaluating cyclic graphs. |
| [Relativistic Raytracer](projects/simulations-hpc/relativistic-raytracer/) | Simulations & HPC | C++20, RK4 | Curved-spacetime optical raytracer solving null geodesics in Kerr metrics. |
| [myRadar](projects/simulations-hpc/myradar/) | Simulations & HPC | C, CSFML, Quadtree | Air traffic control simulation with Quadtree spatial collision detection. |
| [myPaint](projects/simulations-hpc/mypaint/) | Simulations & HPC | C, CSFML | Raster graphics drawing suite with layer and brush dynamics. |
| [myHunter](projects/simulations-hpc/myhunter/) | Simulations & HPC | C, CSFML | 2D interactive arcade game with sprite animation and frame regulation. |
| [Screensaver](projects/simulations-hpc/screensaver/) | Simulations & HPC | C, CSFML | Real-time procedural animation rendering trigonometric vector fields. |
| [Gomoku AI](projects/algorithms-ai/gomoku-ai/) | Algorithms & AI | Python 3, Minimax | Tournament game engine with Alpha-Beta pruning and bitboards. |
| [Dante's Star](projects/algorithms-ai/dante-star/) | Algorithms & AI | C, Graph Search, A* | Procedural maze generator and high-throughput A* / Dijkstra solver. |
| [Lem-In](projects/algorithms-ai/lemin/) | Algorithms & AI | C, Network Flow, BFS | Maximum network flow pathfinding optimizing ant colony dispersal. |
| [Need4Stek](projects/algorithms-ai/n4s-autonomous/) | Algorithms & AI | C, Robotics, PID Control | Autonomous vehicle controller parsing 32-beam lidar telemetry. |
| [Pushswap](projects/algorithms-ai/pushswap/) | Algorithms & AI | C, Stack Optimization | Dual-stack sorting optimization operating under a restricted instruction set. |
| [BSQ](projects/algorithms-ai/bsq/) | Algorithms & AI | C, Dynamic Programming | 2D dynamic programming algorithm finding the maximal square in linear time. |
| [FASTAtools](projects/algorithms-ai/fastatools/) | Algorithms & AI | C, Bioinformatics | Sequence analysis utility computing k-mer frequencies and RNA transcription. |
| [Antman](projects/algorithms-ai/antman-compression/) | Algorithms & AI | C, Data Compression | Lossless multi-format data compression via dictionary bit packing. |
| [Sokoban](projects/algorithms-ai/sokoban/) | Algorithms & AI | C, Ncurses | Terminal warehouse puzzle engine with deadlock state detection. |
| [InfinAdd](projects/algorithms-ai/infinadd/) | Algorithms & AI | C, Arbitrary Precision | Arbitrary-precision BigInt arithmetic engine for unlimited integer sizes. |
| [myFTP](projects/network-devops/myftp/) | Network & DevOps | C, BSD Sockets, RFC 959 | RFC 959 FTP server with non-blocking I/O multiplexing (`select`/`poll`). |
| [Panoramix](projects/network-devops/panoramix/) | Network & DevOps | C, pthreads, Semaphores | Concurrent multithreaded simulation modeling synchronized resource access. |
| [Popeye](projects/network-devops/popeye/) | Network & DevOps | Docker, Microservices | Multi-tier voting app containerized and orchestrated via Docker Compose. |
| [109titration](projects/scientific-computing/109titration/) | Scientific Computing | Python 3, Numerical Analysis | Chemical pH curve analysis computing derivatives via cubic splines. |
| [Groundhog](projects/scientific-computing/groundhog/) | Scientific Computing | Python 3, Time Series | Real-time rolling telemetry processor detecting trend switches and deviations. |
| [SBML Parser](projects/scientific-computing/sbmlparser/) | Scientific Computing | C, XML Parsing | XML parser for Systems Biology Markup Language extracting chemical reactions. |
| [Palindrome](projects/scientific-computing/palindrome/) | Scientific Computing | C, Number Theory | Number theory engine solving palindrome operations across arbitrary bases. |
| [ProjTester](projects/scientific-computing/projtester/) | Scientific Computing | C, Testing | Automated integration test runner validating binary output and exit codes. |
| [Math Algorithms](projects/scientific-computing/math-algorithms/) | Scientific Computing | Python, C | Applied mathematical suite: affine matrices, Hill cipher, numerical integrals. |
| [Silicium Network](projects/distributed-systems/silicium-eip/) | Distributed Systems | Rust, C++, Solana | Decentralized IoT compute protocol with C++ ELF partitioner and Solana. |
| [C Pool](projects/foundations/c-pool/) | Foundations | C, Shell, POSIX | Foundational C language suite covering pointer arithmetic and data structures. |
| [C++ Pool](projects/foundations/cpp-pool/) | Foundations | C++20, STL, Templates | Modern C++ progression covering RAII, polymorphism, and generic templates. |

---

## Directory Organization

```text
projects/
├── systems-kernel/        # Unix internals, ptrace, ELF introspection, libc assembly
├── simulations-hpc/       # Circuit netlists, relativistic raytracing, spatial quadtrees
├── algorithms-ai/         # Minimax game theory, network flow, maze pathfinding, compression
├── network-devops/        # RFC 959 BSD socket servers, POSIX concurrency, Docker orchestration
├── scientific-computing/  # Numerical methods, cubic splines, time-series, biological XML
├── distributed-systems/   # Decentralized IoT compute networks, Solana smart contracts
└── foundations/           # Core C & C++ language progression suites
```

---

## Engineering Standards

- **Low Overhead:** Zero unnecessary dynamic memory allocations in performance-critical paths; direct use of POSIX system calls and custom buffers.
- **Portability & Determinism:** Written to ISO C11 and C++20 standards, verified with strict compiler diagnostics (`-Wall -Wextra -Werror`).
- **Clean Architecture:** Modular separation between parsers, data structures, evaluation engines, and presentation layers.

---

## Contact & Links

- **Engineering Portfolio:** [luisfernandes.tech](https://luisfernandes.tech)
- **GitHub Profile:** [@Luis1454](https://github.com/Luis1454)
- **Email:** [luis.fernandes.contact@gmail.com](mailto:luis.fernandes.contact@gmail.com)
