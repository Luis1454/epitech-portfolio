# Modern C++ & Software Engineering Paradigms Suite

An advanced, immersion-based software engineering curriculum in Modern C++ (C++17 / C++20). Covers object-oriented design patterns, RAII lifecycle guarantees, operator overloading, stream metaprogramming, runtime polymorphism, virtual table mechanics, template metaprogramming, and STL algorithms.

## Overview

This repository captures an intensive deep dive into C++ object-oriented paradigms and modern idioms, bridging low-level procedural systems with modern high-level abstraction. The modules systematically dismantle the abstraction cost of C++, exploring internal compiler memory layouts, virtual method dispatch overhead, compile-time template evaluation, and zero-overhead idioms.

## Modular Architecture & Paradigm Progression

| Module Directory | Paradigm & Architecture | Core Engineering Concepts |
| :--- | :--- | :--- |
| [`day01-c-to-cpp-migration/`](./day01-c-to-cpp-migration/) | Transitioning from C procedural memory to C++ encapsulation | Memory safety, type-safe references |
| [`day02-raii-encapsulation/`](./day02-raii-encapsulation/) | Resource Acquisition Is Initialization (RAII), object lifetimes | Scope-bound resource cleanup, invariants |
| [`day03-references-memory-management/`](./day03-references-memory-management/) | Reference semantics vs pointers, dynamic object lifecycle | `new` / `delete`, memory leakage elimination |
| [`day04am-namespaces-static-members/`](./day04am-namespaces-static-members/) | Scoping, static class members, namespace organization | Symbol isolation, singleton-like states |
| [`day04pm-copy-constructors-assignment/`](./day04pm-copy-constructors-assignment/) | Rule of Three / Rule of Five, copy/move semantics | Deep copy vs shallow copy, resource duplication |
| [`day05-operator-overloading/`](./day05-operator-overloading/) | Custom arithmetic, assignment, comparison, and stream operators | Domain-Specific Language (DSL) syntax |
| [`day06-streams-io-formatting/`](./day06-streams-io-formatting/) | Type-safe I/O streaming, buffer manipulators | Custom `std::ostream` / `std::istream` adapters |
| [`day07am-single-inheritance/`](./day07am-single-inheritance/) | Object composition vs inheritance, access specifiers | `protected` / `private` inheritance semantics |
| [`day07pm-polymorphism-virtual-tables/`](./day07pm-polymorphism-virtual-tables/) | Dynamic dispatch, vtables, virtual destructors | Memory layout of virtual function tables |
| [`day08-abstract-classes-interfaces/`](./day08-abstract-classes-interfaces/) | Pure abstract interfaces (`IComponent`), dependency inversion | Decoupled architecture, plug-in design |
| [`day09-template-functions-classes/`](./day09-template-functions-classes/) | Generic programming, parameterized types | Compile-time code generation, zero-overhead |
| [`day10-template-specialization/`](./day10-template-specialization/) | Explicit template specialization, type traits | Static polymorphism, compile-time branching |
| [`day11-stl-containers-iterators/`](./day11-stl-containers-iterators/) | Standard Template Library containers, iterator categories | Cache-efficient vector storage, map trees |
| [`day12-lambdas-functors-algorithms/`](./day12-lambdas-functors-algorithms/) | Higher-order functional programming, lambdas, closures | `std::transform`, `std::for_each`, functors |
| [`day13-smart-pointers-raii-lifetime/`](./day13-smart-pointers-raii-lifetime/) | Modern memory management (`std::unique_ptr`, `std::shared_ptr`) | Automatic ref-counting, move-only ownership |

## Engineering Principles

- **Zero-Cost Abstractions:** Utilizing templates, inlining, and compile-time evaluations without runtime penalties.
- **Strict Exception & Memory Safety:** Guaranteed strong exception safety and deterministic destruction order.
- **Modern Idioms:** Strict adherence to modern C++ best practices (const-correctness, explicit constructors, override/final keywords).

## Build Instructions

```bash
# Compile and test generic template specialization modules
make -C day10-template-specialization/

# Build and execute smart pointer lifetime benchmark
make -C day13-smart-pointers-raii-lifetime/
```
