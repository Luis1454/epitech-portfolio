import sys

def xor_encrypt(message, hex_key, block_mode=False):
    key = bytes.fromhex(hex_key)
    encrypted = []
    message = message[::-1]
    key_length = len(key)

    for i in range(len(message)):
        encrypted_char = ord(message[i]) ^ key[i % key_length]
        encrypted.append(chr(encrypted_char))

    return ''.join(encrypted).encode().hex()

def xor_decrypt(ciphered_hex, hex_key, block_mode=False):
    if len(ciphered_hex) % 2 != 0:
        print('Invalid ciphered_hex length', file=sys.stderr)
        exit(84)
    key = bytes.fromhex(hex_key)
    ciphered = bytes.fromhex(ciphered_hex)
    decrypted = []
    key_length = len(key)

    for i in range(len(ciphered)):
        decrypted_char = ciphered[i] ^ key[i % key_length]
        decrypted.append(chr(decrypted_char))

    return ''.join(decrypted[::-1])
