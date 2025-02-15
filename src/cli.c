#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "crypto.h"

unsigned char key[32] = "my_super_secret_key_32";  
unsigned char iv[16] = "my_init_vector_16";         

void menu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Aggiungi password\n");
    printf("2. Recupera password\n");
    printf("3. Esci\n");
    printf("Scelta: ");
};

int main() {
    int scelta;
    char site[50], username[50], password[50];
    unsigned char encrypted[128];

    while (1) {
        menu();
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("\nInserisci il sito: ");
                scanf("%s", site);
                printf("\nInserisci l'username: ");
                scanf("%s", username);
                printf("\nInserisci la password: ");
                scanf("%s", password);

                encrypt_password(password, encrypted, key, iv);
                open_db();
                store_password(site, username, (char*)encrypted);
                close_db();
                break;

            case 2:
                printf("Inserisci il sito da cercare: ");
                scanf("%s", site);
                retrieve_password(site, key, iv);
                break;

            case 3:
                printf("Uscita...\n");
                exit(0);
        }
    }
};