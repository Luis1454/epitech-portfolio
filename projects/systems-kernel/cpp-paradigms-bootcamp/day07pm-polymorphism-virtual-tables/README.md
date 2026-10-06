# Virtual Methods & Dynamic Dispatch (vtable)

> Object-Oriented & Generic C++ Paradigms

Runtime polymorphism through virtual functions, virtual destructors, and vtable dispatch mechanics.

## Architecture & Conception

Interface-based runtime dispatch allowing heterogeneous collections of derived objects via base pointers.

## Primitives & Spécifications Implémentées

- `Virtual member functions & overriding`
- `Virtual destructors preventing resource leaks`
- `Dynamic dispatch mechanics`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
