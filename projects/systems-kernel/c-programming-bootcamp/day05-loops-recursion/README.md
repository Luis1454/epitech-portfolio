# Iterative & Recursive Mathematical Computations

> Systems Programming & Kernel Foundations

High-efficiency implementations of combinatorial, arithmetic, and number-theoretic algorithms.

## Architecture & Conception

Compares iterative loop execution with stack-allocated recursive calls, handling integer overflow boundaries.

## Primitives & Spécifications Implémentées

- `my_compute_factorial_it / rec: factorial computation`
- `my_compute_power_it / rec: integer exponentiation`
- `my_compute_square_root: integer root search`
- `my_is_prime / my_find_prime_sup: primality testing`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
