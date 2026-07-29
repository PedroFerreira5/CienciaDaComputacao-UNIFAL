#ifndef Palindromo
#define Palindromo
#include <stdbool.h>

struct no{
    char letra;
    struct no *prev, *next;
};

struct Fila{
    struct no *inicio, *fim;
};

char ehAcentuado(unsigned char c1, unsigned char c2);
void normalizar(char *str);
bool ehPalindroma(const char *str);

#endif