CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I/usr/local/opt/openssl/include  # Aggiungi il percorso degli header OpenSSL
LIBS = -lsqlite3 -lssl -lcrypto -L/usr/local/opt/openssl/lib  # Aggiungi il percorso delle librerie OpenSSL
SRCS = main.c db.c crypto.c
OBJS = $(SRCS:.c=.o)
TARGET = password_manager

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)