# Low-Level POSIX System Call I/O Architecture

> Systems Programming & Kernel Foundations

Direct operating system I/O using open, read, write, and close system calls with fixed-size buffers.

## Architecture & Conception

Zero-buffering pipeline streaming data across file descriptors with rigorous errno and EOF handling.

## Primitives & Spécifications Implémentées

- `cat implementation with chunked read buffers`
- `File error classification (ENOENT, EACCES)`
- `Standard stream multiplexing`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
