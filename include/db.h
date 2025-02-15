#ifndef DB_H
#define DB_H

void open_db();
void close_db();
void add_password(const char *site, const char *username, const char *password);

#endif