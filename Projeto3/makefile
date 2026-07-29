# Makefile para compilar e executar o projeto Palíndromo

# Nome do executável
PROJ_NAME = palindromo

# Fontes e cabeçalhos
SRC = main.c \
      Palindromo.c

HEADERS = Palindromo.h

# Objetos
OBJ = $(SRC:.c=.o)

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -O2
LDFLAGS =

.PHONY: all clean run debug

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Regra genérica para compilar qualquer .c em .o, dependendo dos headers do projeto
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Executa o programa (Windows gera .exe automaticamente)
run: $(PROJ_NAME)
	./$(PROJ_NAME)

# Variante com símbolos de debug
debug: CFLAGS += -g -O0
debug: clean all

clean:
	rm -f $(OBJ) $(PROJ_NAME) $(PROJ_NAME).exe saida.txt
