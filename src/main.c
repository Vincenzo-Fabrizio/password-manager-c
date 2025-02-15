#include <stdio.h>
#include <string.h>
#include "db.h"
#include "crypto.h"

int main() {
    open_db();

    char site[100], username[100], password[100];
    printf("Sito: ");
    scanf("%s", site);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Definisci la chiave e l'IV
    unsigned char key[16] = {0};  // 16 byte per AES (modifica con una chiave sicura)
    unsigned char iv[16] = {0};   // 16 byte per AES (modifica con un IV sicuro)

    unsigned char encrypted[32];  // Dimensione adeguata per il testo cifrato
    encrypt_password(password, encrypted, key, iv);

    add_password(site, username, (char *)encrypted);

    close_db();
    return 0;
};