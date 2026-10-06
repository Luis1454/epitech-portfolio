# Primitive Data Representation & Standard I/O Primitives

> Systems Programming & Kernel Foundations

Low-level integer representation, bitwise arithmetic operations, and unbuffered byte output routines in C.

## Architecture & Conception

Direct interaction with stdout file descriptor (fd 1) via unbuffered write(2) syscalls. Zero standard library dependency.

## Primitives & Spécifications Implémentées

- `my_putchar: unbuffered byte output`
- `Integer sign encoding & two complement validation`
- `Base conversion primitives`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
