# Static Class Members & Scoped Namespaces

> Object-Oriented & Generic C++ Paradigms

Class-level static variables, factory methods, and hierarchical namespace organization.

## Architecture & Conception

Class-wide state tracking across instances without global variable pollution.

## Primitives & Spécifications Implémentées

- `Static member variables & functions`
- `Hierarchical namespace resolution`
- `Instance counting and shared state`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
