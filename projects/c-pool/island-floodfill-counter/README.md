# Recursive Flood-Fill Component Labeling Engine

> Systems Programming & Kernel Foundations

Recursive 2D matrix traversal detecting connected components and contiguous topological regions.

## Architecture & Conception

Depth-First Search (DFS) grid exploration with in-place cell marking to prevent cyclic recursion.

## Primitives & Spécifications Implémentées

- `count_island: recursive flood-fill entry point`
- `Coordinate validity and boundary enforcement`
- `Cluster counter with ASCII matrix mapping`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
