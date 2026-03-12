# ==============================
# Makefile para o projeto de Ordenação Externa em C
# ==============================

# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = ordenar_arquivo.exe
SRCS = main.c ordenacao.c

all: $(TARGET)

$(TARGET): $(SRCS)
    $(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
    @echo "Executando..."
    .\$(TARGET)

clean:
    del /Q $(TARGET) 2> NUL || rm -f $(TARGET)
    del /Q *.o 2> NUL || rm -f *.o