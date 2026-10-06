# Procedural C to Modern C++ Architecture Transition

> Object-Oriented & Generic C++ Paradigms

Migration of procedural architectures to C++ strong typing, namespaces, and stream-based I/O.

## Architecture & Conception

Namespaced scoping, const correctness, memory ownership transition, and stream formatting.

## Primitives & Spécifications Implémentées

- `Namespace encapsulation`
- `Standard stream manipulation (std::cin, std::cout)`
- `Type-safe memory buffers`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
