# Dynamic Heap Allocation & Command-Line Argument Ingestion

> Systems Programming & Kernel Foundations

Dynamic buffer allocation via malloc, argument array ingestion, and string concatenation primitives.

## Architecture & Conception

Safe heap allocation with null-pointer defensive checks and explicit heap deallocation contracts.

## Primitives & Spécifications Implémentées

- `my_strdup: heap string duplication`
- `my_strcat / my_strncat: dynamic string concatenation`
- `CLI parameter traversal and formatted printing`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
