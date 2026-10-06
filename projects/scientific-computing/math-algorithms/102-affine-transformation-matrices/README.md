# 3D Affine Transformations & Homogeneous Coordinates

> Scientific Computing & Applied Mathematics

Calculates composite transformation matrices (translation, scaling, rotation, reflection) on 3D homogeneous coordinates.

## Architecture & Conception

Matrix multiplication pipelines chaining spatial transformations into a unified 4x4 matrix operator.

## Primitives & Spécifications Implémentées

- `Translation matrix generator`
- `3D Euler angle rotation matrices`
- `Homogeneous matrix multiplication engine`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
