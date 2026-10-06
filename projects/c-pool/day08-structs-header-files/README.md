# Heterogeneous Data Structures & Header Modularity

> Systems Programming & Kernel Foundations

Definition of C struct layouts, header file guards, and array-of-struct data management.

## Architecture & Conception

Enforces modular separation of interfaces (.h) and implementations (.c) with data packing considerations.

## Primitives & Spécifications Implémentées

- `struct info_param: metadata container for CLI arguments`
- `my_params_to_array: parameter struct array builder`
- `my_show_param_array: formatted metadata serializer`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
