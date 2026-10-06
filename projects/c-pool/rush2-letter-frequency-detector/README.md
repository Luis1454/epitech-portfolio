# Statistical Monogram Language Classifier

> Systems Programming & Kernel Foundations

Language detection engine comparing character distribution frequencies against English, French, German, and Spanish corpora.

## Architecture & Conception

Letter frequency histogram extraction and Euclidean distance minimization against linguistic frequency profiles.

## Primitives & Spécifications Implémentées

- `Letter frequency normalization`
- `Corpus distance metric calculation`
- `Language probability score ranking`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
