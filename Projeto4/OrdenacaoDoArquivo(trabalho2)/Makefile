# Nome do projeto (gera .exe)
PROJ_NAME=ordenacaoDeArquivo.exe

# Compilador
CC=gcc

# Flags (opções) para o compilador
CC_FLAGS=-c \
         -Wall \
         -g \
         -pedantic \
         -std=c11

# Arquivos .c e .h nesta pasta
C_SOURCE=$(wildcard *.c)
H_SOURCE=$(wildcard *.h)

# Objetos
OBJ=$(C_SOURCE:.c=.o)

.PHONY: all clean

#########################
# Compilação e linkagem #
#########################
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

#########################
# Limpeza               #
#########################
clean:
	-@for %%f in ($(OBJ)) do @if exist "%%f" del /q "%%f"
	-@if exist "$(PROJ_NAME)" del /q "$(PROJ_NAME)"
