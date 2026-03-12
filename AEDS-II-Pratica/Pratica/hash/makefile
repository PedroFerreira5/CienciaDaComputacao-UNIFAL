# Makefile simples para compilar o programa de Tabela Hash

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = hash_table

$(TARGET): main.c hash.h
	$(CC) $(CFLAGS) main.c -o $(TARGET)

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)