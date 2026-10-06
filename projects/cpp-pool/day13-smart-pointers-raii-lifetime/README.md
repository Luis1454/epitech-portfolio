# Modern Memory Safety: Smart Pointers & Ownership

> Object-Oriented & Generic C++ Paradigms

Deterministic heap memory management with std::unique_ptr, std::shared_ptr, and std::weak_ptr.

## Architecture & Conception

Eliminates dangling pointers and double frees through clear exclusive vs shared ownership semantics.

## Primitives & Spécifications Implémentées

- `std::unique_ptr for unique exclusive ownership`
- `std::shared_ptr with reference counting`
- `std::weak_ptr for breaking cyclic reference graphs`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
