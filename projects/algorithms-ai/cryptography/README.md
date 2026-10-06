# Cryptography — Symmetric & Asymmetric Cipher Toolkit

A cryptographic engineering toolkit implementing classical and modern encryption algorithms, frequency analysis cryptanalysis tools, and modular arithmetic primitives.

## Overview

This repository provides foundational implementations of both symmetric and asymmetric encryption schemes. It emphasizes clean mathematical formulations, modular arithmetic operations, and cryptanalytic tooling to demonstrate vulnerability vectors in weak cipher designs.

## Architecture & Technical Highlights

- **Asymmetric Encryption (RSA):** Key generation with extended Euclidean algorithm, modular exponentiation (square-and-multiply), and prime testing routines.
- **Symmetric Ciphers:** Stream and block cipher implementations including XOR substitution, Vigenère cipher, and AES matrix transformations.
- **Cryptanalysis Tools:** Letter and n-gram frequency analysis, index of coincidence calculation, and automated ciphertext cracking algorithms.
- **BigInt Arithmetic Compatibility:** Designed for large prime numbers and modular arithmetic operations without integer overflows.

## Tech Stack

- **Language:** C / C++ / Python
- **Algorithms:** RSA, Extended Euclidean Algorithm, Modular Exponentiation, AES primitives
- **Build System:** GNU Make

## Build & Execution

```bash
# Compile cryptography utilities
make

# Encrypt data with RSA
./crypto rsa --generate-keys 2048
./crypto rsa --encrypt --key public.pem -i message.txt -o cipher.bin
```
