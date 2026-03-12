CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Nome do executável
TARGET = hash_colisao

# Arquivos fonte e objeto
SRCS = hash.c
OBJS = $(SRCS:.c=.o)

# Regra principal: compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)