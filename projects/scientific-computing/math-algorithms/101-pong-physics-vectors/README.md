# 3D Kinematic Vector Tracking & Trajectory Reflection

> Scientific Computing & Applied Mathematics

Calculates 3D velocity vectors, spatial coordinates at time T+n, and collision angle against reflection bounding planes.

## Architecture & Conception

Vector linear kinematics in Cartesian coordinate space with dot product angle resolution.

## Primitives & Spécifications Implémentées

- `Velocity differential vector computation`
- `Future time coordinate extrapolation`
- `Incidence angle trigonometry at reflection plane`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
