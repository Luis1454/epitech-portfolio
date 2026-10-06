# Dynamic Singly-Linked List Architecture

> Systems Programming & Kernel Foundations

Heap-allocated dynamic node chaining, element search, insertion, filtering, and reversal operations.

## Architecture & Conception

Recursive and iterative node traversal with head pointer management and leak-free node destruction.

## Primitives & Spécifications Implémentées

- `my_params_to_list: list initialization from argv`
- `my_list_size: node counting`
- `my_rev_list: in-place node pointer reversal`
- `my_delete_nodes: predicate-based node removal`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
