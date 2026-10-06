# C++ References & Heap Lifetime Management

> Object-Oriented & Generic C++ Paradigms

Lvalue references, memory aliasing, dynamic heap allocation via new/delete, and const reference passing.

## Architecture & Conception

Eliminates pointer overhead using references for argument passing while maintaining strict memory contracts.

## Primitives & Spécifications Implémentées

- `Reference semantics vs pointer semantics`
- `Heap allocation lifecycle with new[] and delete[]`
- `Const reference efficiency`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
