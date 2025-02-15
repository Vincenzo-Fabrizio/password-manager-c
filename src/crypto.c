#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include "crypto.h"

#define AES_KEY_SIZE 32  // 256-bit key
#define AES_IV_SIZE 16   // 128-bit IV

void encrypt_password(const char *plaintext, unsigned char *encrypted, unsigned char *key, unsigned char *iv) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len, ciphertext_len;

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, encrypted, &len, (unsigned char*)plaintext, strlen(plaintext));
    ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, encrypted + len, &len);
    ciphertext_len += len;

    encrypted[ciphertext_len] = '\0';  // Null-terminate
    EVP_CIPHER_CTX_free(ctx);
}

void decrypt_password(unsigned char *encrypted, char *plaintext, unsigned char *key, unsigned char *iv) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len, plaintext_len;

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, (unsigned char*)plaintext, &len, encrypted, strlen((char*)encrypted));
    plaintext_len = len;
    EVP_DecryptFinal_ex(ctx, (unsigned char*)plaintext + len, &len);
    plaintext_len += len;

    plaintext[plaintext_len] = '\0';  // Null-terminate
    EVP_CIPHER_CTX_free(ctx);
}