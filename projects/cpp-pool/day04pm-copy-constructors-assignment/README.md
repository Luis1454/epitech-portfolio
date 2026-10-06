# Deep Copy Semantics & The Rule of Three

> Object-Oriented & Generic C++ Paradigms

Copy constructors, copy assignment operator overloading, and deep heap memory cloning.

## Architecture & Conception

Prevents double-free vulnerabilities and shallow pointer aliasing when passing objects by value.

## Primitives & Spécifications Implémentées

- `Copy constructor implementation`
- `operator= assignment overloading with self-assignment check`
- `Deep dynamic buffer cloning`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
