#include <stdio.h>
#include <string.h>
#include "auth.h"

#define MASTER_PASSWORD "password123"

int authenticate() {
    char input[50];
    printf("Inserisci la master password: ");
    scanf("%s", input);
    
    if (strcmp(input, MASTER_PASSWORD) == 0) {
        return 1;
    } else {
        printf("Accesso negato!\n");
        return 0;
    }
};