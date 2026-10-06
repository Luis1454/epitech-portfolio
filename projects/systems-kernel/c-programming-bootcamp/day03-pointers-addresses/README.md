# Pointer Arithmetic & Memory Address Resolution

> Systems Programming & Kernel Foundations

Direct memory address manipulation, pointer dereferencing, and in-place variable swap operations.

## Architecture & Conception

Examines memory alignment, stack frame allocations, and pointer arithmetic mechanics on x86_64 architecture.

## Primitives & Spécifications Implémentées

- `my_swap: atomic memory swap`
- `my_div_to_mod: quotient/remainder pointer assignment`
- `my_put_nbr: recursive base-10 integer printer`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
