# Parametric Star Polygon Terminal Renderer

> Systems Programming & Kernel Foundations

Terminal rendering engine calculating and plotting symmetric star polygon coordinates at arbitrary scale.

## Architecture & Conception

Mathematical coordinate generation calculating vertex offsets, indentations, and central span lines.

## Primitives & Spécifications Implémentées

- `star: parametric scale processor`
- `Symmetric top/bottom and arm buffer rendering`
- `Edge-case scaling (size 1 to N) handling`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
