# Hill Cipher Encryption & Modular Matrix Inversion

> Scientific Computing & Applied Mathematics

Symmetric cryptography engine implementing the Hill cipher via matrix multiplication and modular matrix inversion.

## Architecture & Conception

Modular arithmetic determinant computation, adjugate matrix transposition, and modular multiplicative inverse.

## Primitives & Spécifications Implémentées

- `Hill key matrix generation from ASCII`
- `Modular determinant calculation (mod 26 / mod 256)`
- `Ciphertext encryption and decryption pipelines`

## Compilation & Exécution

```bash
make
```

## Garanties Techniques & Qualité

- **Déterminisme** : Exécution pure sans effets de bord non contrôlés.
- **Gestion Mémoire** : Zero fuite mémoire (validé sous Valgrind / AddressSanitizer).
- **Standards** : Respect strict des spécifications POSIX et conformité du typage.
