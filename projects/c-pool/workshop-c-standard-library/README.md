# Standard C Library Core Primitives Suite

> Systems Programming & Kernel Foundations

Consolidated implementation of core POSIX C library string, memory, and formatted output functions.

## Architecture & Conception

Self-contained library archive providing foundational routines for systems programming projects.

## Primitives & Spécifications Implémentées

- `Unified libmy.a archive`
- `Header collection (my.h)`
- `Verification test harnesses`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
