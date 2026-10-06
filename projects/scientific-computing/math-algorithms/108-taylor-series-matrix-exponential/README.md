# Matrix Exponential Computation via Taylor Series

> Scientific Computing & Applied Mathematics

Calculates the matrix exponential exp(A) of square matrices using truncated Taylor series expansions and Padé approximants.

## Architecture & Conception

Iterative matrix multiplication, factorial accumulation, and spectral radius convergence monitoring.

## Primitives & Spécifications Implémentées

- `Matrix multiplication and addition operators`
- `Taylor series polynomial summation: sum(A^k / k!)`
- `Frobenius norm convergence criterion`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
