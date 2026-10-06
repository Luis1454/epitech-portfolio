# STL Algorithms, Functors & Lambda Expressions

> Object-Oriented & Generic C++ Paradigms

Modern algorithmic pipelines using std::sort, std::transform, function objects, and anonymous lambda closures.

## Architecture & Conception

Functional programming paradigms in C++ eliminating manual loop boilerplate and maximizing compiler vectorization.

## Primitives & Spécifications Implémentées

- `Standard algorithms (for_each, transform, find_if)`
- `Custom predicate functors with operator()`
- `Lambda expressions with capture specifications`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
