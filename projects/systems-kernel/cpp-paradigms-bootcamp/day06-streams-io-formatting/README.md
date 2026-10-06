# Stream I/O Architecture & File Serialization

> Object-Oriented & Generic C++ Paradigms

File stream processing with std::ifstream/ofstream and string stream formatting with std::stringstream.

## Architecture & Conception

Robust binary and text serialization with stream state validation (fail, bad, eof bits).

## Primitives & Spécifications Implémentées

- `File parsing pipelines`
- `Stream formatting manipulators`
- `In-memory string stream buffering`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
