# Logistic Map Dynamical Systems & Bifurcation Analysis

> Scientific Computing & Applied Mathematics

Simulates non-linear population dynamics using the logistic map equation, identifying periodic cycles and chaos transitions.

## Architecture & Conception

Iterative non-linear recurrence simulation mapping attractor points and Feigenbaum bifurcation cascades.

## Primitives & Spécifications Implémentées

- `Logistic recurrence step evaluation: x_{n+1} = r * x_n * (1 - x_n)`
- `Cycle stability detection`
- `Bifurcation density distribution generator`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
