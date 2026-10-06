# Template Specialization & Metaprogramming Traits

> Object-Oriented & Generic C++ Paradigms

Full and partial template specialization, compile-time type traits, and optimized specific instances.

## Architecture & Conception

Compile-time branching selecting specialized implementations for specific hardware or primitive types.

## Primitives & Spécifications Implémentées

- `Full template specialization`
- `Type trait deduction templates`
- `Compile-time constants and static assertions`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
