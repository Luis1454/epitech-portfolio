# Numerical Quadrature of Oscillatory Borwein Integrals

> Scientific Computing & Applied Mathematics

High-precision numerical integration of oscillatory Borwein sinc product integrals using Midpoint, Trapezoid, and Simpson rules.

## Architecture & Conception

Discretized Riemann sum approximation with error bound estimation comparing composite quadrature techniques.

## Primitives & Spécifications Implémentées

- `Midpoint rectangular integration rule`
- `Composite Trapezoidal quadrature rule`
- `Simpson parabolic integration rule`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
