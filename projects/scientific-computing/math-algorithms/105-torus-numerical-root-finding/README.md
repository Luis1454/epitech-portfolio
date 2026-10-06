# Numerical Root-Finding for Quartic Torus Equations

> Scientific Computing & Applied Mathematics

Iterative numerical solvers (Bisection, Newton-Raphson, Secant) calculating ray-torus intersection coordinates.

## Architecture & Conception

Polynomial evaluation and iterative convergence loops with tolerance-based stopping criteria and divergence guards.

## Primitives & Spécifications Implémentées

- `Bisection interval division method`
- `Newton-Raphson first-derivative iteration`
- `Secant method two-point approximation`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
