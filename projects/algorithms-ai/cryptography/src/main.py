import sys

def print_usage():
    print("USAGE: ./my_pgp CRYPTO_SYSTEM MODE [OPTIONS] [key]")
    print("DESCRIPTION:")
    print("The MESSAGE is read from standard input")
    print("CRYPTO_SYSTEM:")
    print(" xor        - XOR encryption")
    print(" aes        - AES encryption")
    print(" rsa        - RSA encryption")
    print(" pgp-xor    - PGP using XOR")
    print(" pgp-aes    - PGP using AES")
    print("MODE:")
    print(" -c         - Cipher the message")
    print(" -d         - Decipher the message")
    print(" -g         - Generate RSA keys (for RSA only)")
    print("OPTIONS:")
    print(" -b         - Block mode encryption/decryption")
    sys.exit(84)

def main():
    if len(sys.argv) < 3:
        print_usage()

    crypto_system = sys.argv[1]
    mode = sys.argv[2]
    block_mode = '-b' in sys.argv
    key = sys.argv[-1] if len(sys.argv) > 3 else None
    message = sys.stdin.read().strip()
    if crypto_system == 'xor':
        if mode == '-c':
            print(xor_encrypt(message, key, block_mode))
        elif mode == '-d':
            print(xor_decrypt(message, key, block_mode))
        else:
            print_usage()

    elif crypto_system == 'aes':
        if mode == '-c':
            print(aes_encrypt(message, key, block_mode))
        elif mode == '-d':
            print(aes_decrypt(message, key, block_mode))
        else:
            print_usage()

    elif crypto_system == 'rsa':
        if mode == '-g':
            P = sys.argv[3]
            Q = sys.argv[4]
            generate_rsa_keys(P, Q)
        elif mode == '-c':
            print(rsa_encrypt(message, key))
        elif mode == '-d':
            print(rsa_decrypt(message, key))
        else:
            print_usage()

    elif crypto_system == 'pgp-xor':
        if mode == '-c':
            print(pgp_xor_encrypt(message, key, block_mode))
        elif mode == '-d':
            print(pgp_xor_decrypt(message, key, block_mode))
        else:
            print_usage()

    elif crypto_system == 'pgp-aes':
        if mode == '-c':
            print(pgp_aes_encrypt(message, key, block_mode))
        elif mode == '-d':
            print(pgp_aes_decrypt(message, key, block_mode))
        else:
            print_usage()

    else:
        print_usage()

if __name__ == "__main__":
    main()
