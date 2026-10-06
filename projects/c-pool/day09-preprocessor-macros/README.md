# C Preprocessor Metaprogramming & Macros

> Systems Programming & Kernel Foundations

Macro metaprogramming, conditional compilation directives, and parameter-safe macro utilities.

## Architecture & Conception

Compile-time code expansion for bounds checking, type abstraction, and conditional debugging symbols.

## Primitives & Spécifications Implémentées

- `Macro definitions for min/max, absolute value, and sign deduction`
- `Header inclusion idempotence mechanisms`
- `Struct alignment and helper macros`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
