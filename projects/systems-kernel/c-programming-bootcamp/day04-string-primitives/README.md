# C-String Operations & In-Place String Reversal

> Systems Programming & Kernel Foundations

Fundamental string length determination, buffer iteration, and in-place array manipulation without heap allocation.

## Architecture & Conception

Linear scanning algorithms with O(N) time complexity and O(1) auxiliary space.

## Primitives & Spécifications Implémentées

- `my_strlen: null-byte string length`
- `my_putstr: buffer streaming to stdout`
- `my_revstr: two-pointer in-place string reversal`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
