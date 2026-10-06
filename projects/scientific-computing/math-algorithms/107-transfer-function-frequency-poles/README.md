# Linear Filter Transfer Functions & Frequency Response

> Scientific Computing & Applied Mathematics

Analyzes continuous linear system transfer functions, computing frequency response magnitude, phase, and pole-zero stability.

## Architecture & Conception

Laplace domain polynomial rational function evaluation across frequency spectra.

## Primitives & Spécifications Implémentées

- `Rational polynomial evaluation H(s) = N(s)/D(s)`
- `Bode magnitude and phase angle computation`
- `System stability verification`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
