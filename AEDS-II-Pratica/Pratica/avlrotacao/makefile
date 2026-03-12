# Define o compilador C
CC = gcc

# Define as flags de compilação:
# -Wall: Habilita todos os warnings
# -g: Inclui informações de debug
# -std=c99: Usa o padrão C99
CFLAGS = -Wall -g -std=c99

# Define o nome do executável final
TARGET = avl_test

# Define todos os arquivos .o (objetos) necessários
OBJECTS = main.o avl.o

# Regra principal (default) - compila o executável
all: $(TARGET)

# Regra para vincular (linkar) os objetos e criar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Regra para compilar main.o
main.o: main.c avl.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar avl.o
avl.o: avl.c avl.h
	$(CC) $(CFLAGS) -c avl.c

# Regra para limpar os arquivos gerados (.o e o executável)
clean:
	rm -f $(OBJECTS) $(TARGET)