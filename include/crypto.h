#ifndef CRYPTO_H
#define CRYPTO_H

void encrypt_password(const char *plaintext, unsigned char *encrypted, unsigned char *key, unsigned char *iv);
void decrypt_password(unsigned char *encrypted, char *plaintext, unsigned char *key, unsigned char *iv);

#endif