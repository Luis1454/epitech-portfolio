# String Searching, Memory Copy & Transformation

> Systems Programming & Kernel Foundations

String buffer copying, bounded substring search, and lexical transformation routines.

## Architecture & Conception

Implements standard string manipulation algorithms conforming to POSIX specifications with strict bounds checking.

## Primitives & Spécifications Implémentées

- `my_strcpy / my_strncpy: bounded memory copy`
- `my_strcmp / my_strncmp: lexicographical comparison`
- `my_strstr: substring search algorithm`
- `my_strupcase / my_strlowcase: in-place ASCII normalization`

## Compilation & Exécution

```bash
gcc -Wall -Wextra *.c
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
