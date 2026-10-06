# Arithmetic & Stream Operator Overloading

> Object-Oriented & Generic C++ Paradigms

Natural syntax operator overloading for mathematical types, comparisons, and stream serialization.

## Architecture & Conception

Canonical operator overloading patterns (+, -, *, /, ==, !=, <, >, <<, >>) with const correctness.

## Primitives & Spécifications Implémentées

- `Compound assignment operators (+=, -=)`
- `Stream output injection (operator<<)`
- `Type coercion and equivalence relations`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
