#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include "db.h"
#include "crypto.h"

sqlite3 *db;

void retrieve_password(const char *site, unsigned char *key, unsigned char *iv) {
    open_db();

    char sql[256];
    sprintf(sql, "SELECT username, password FROM passwords WHERE site='%s';", site);

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const char *username = (const char *)sqlite3_column_text(stmt, 0);
            const char *encrypted_password = (const char *)sqlite3_column_text(stmt, 1);
            char decrypted_password[128];

            decrypt_password((unsigned char*)encrypted_password, decrypted_password, key, iv);
            printf("Sito: %s\nUsername: %s\nPassword: %s\n", site, username, decrypted_password);
        }
    } else {
        printf("Errore nel recupero della password!\n");
    }
    sqlite3_finalize(stmt);
    close_db();
};

void open_db() {
    if (sqlite3_open("database/passwords.db", &db)) {
        fprintf(stderr, "Errore apertura DB: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
};

void close_db() {
    sqlite3_close(db);
};

void add_password(const char *site, const char *username, const char *password) {
    char sql[256];
    sprintf(sql, "INSERT INTO passwords (site, username, password) VALUES ('%s', '%s', '%s');", site, username, password);
    
    if (sqlite3_exec(db, sql, 0, 0, NULL) != SQLITE_OK) {
        fprintf(stderr, "Errore inserimento: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Password salvata!\n");
    }
};