# Static Library Compilation & Makefile Automation

> Systems Programming & Kernel Foundations

Automated multi-target Makefiles, object archiving with ar, and static library distribution (libmy.a).

## Architecture & Conception

Dependency tracking in GNU Make, incremental compilation, clean / fclean / re maintenance rules.

## Primitives & Spécifications Implémentées

- `libmy.a static archive packaging`
- `Makefile dependency graph generation`
- `Automated header and binary deployment`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
