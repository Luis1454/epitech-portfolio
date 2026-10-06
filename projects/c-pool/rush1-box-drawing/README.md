# Parametric ASCII Geometric Box Renderer

> Systems Programming & Kernel Foundations

2D terminal box drawing engine supporting variable dimensions and corner character rules.

## Architecture & Conception

Row-major buffer rendering with coordinate-based edge character assignment and invalid input rejection.

## Primitives & Spécifications Implémentées

- `rush1-1 through rush1-5 style variants`
- `Geometric dimension validation (X > 0, Y > 0)`
- `Direct terminal byte streaming`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
