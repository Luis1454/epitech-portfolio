# Quadric Surface Ray Intersection Algorithms

> Scientific Computing & Applied Mathematics

Calculates 3D line intersection points with quadric surfaces (spheres, cylinders, cones) using algebraic discriminant analysis.

## Architecture & Conception

Solves quadratic polynomial equations for ray parameter t with normal vector derivation at contact points.

## Primitives & Spécifications Implémentées

- `Sphere intersection quadratic solver`
- `Cylinder and cone ray intersection formulation`
- `Surface normal vector derivation at contact points`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
