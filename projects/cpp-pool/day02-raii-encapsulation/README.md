# RAII Resource Management & Class Encapsulation

> Object-Oriented & Generic C++ Paradigms

Resource Acquisition Is Initialization (RAII) patterns, constructors, destructors, and member isolation.

## Architecture & Conception

Deterministic resource acquisition in constructor and unconditional release in destructor preventing memory leaks.

## Primitives & Spécifications Implémentées

- `Class lifecycle management`
- `Member access encapsulation (private/public)`
- `Resource cleanup contracts`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
