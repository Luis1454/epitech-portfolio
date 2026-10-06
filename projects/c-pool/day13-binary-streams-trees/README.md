# Binary Search Trees & Structured Data Traversal

> Systems Programming & Kernel Foundations

Binary Search Tree (BST) construction, balanced node lookup, and in-order/pre-order traversal algorithms.

## Architecture & Conception

Hierarchical node pointer branching providing O(log N) average lookup and sorted node serialization.

## Primitives & Spécifications Implémentées

- `btree_create_node: heap node allocation`
- `btree_apply_prefix / infix / postfix: tree traversal functional iterators`
- `btree_search_item: key lookup via comparator callbacks`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
