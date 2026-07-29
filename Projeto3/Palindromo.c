#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Palindromo.h"

// Função para mapear caracteres UTF-8 acentuados para suas versões sem acento
char ehAcentuado(unsigned char c1, unsigned char c2) {
    if (c1 == 0xC3) {
        switch (c2) {
            // Letras minúsculas
            case 0xA1: case 0xA0: case 0xA2: case 0xA3: return 'a';  // á à â ã
            case 0xA9: case 0xA8: case 0xAA: return 'e';             // é è ê
            case 0xAD: case 0xAC: case 0xAE: return 'i';             // í ì î
            case 0xB3: case 0xB2: case 0xB4: case 0xB5: return 'o';  // ó ò ô õ
            case 0xBA: case 0xB9: case 0xBB: return 'u';             // ú ù û
            case 0xA7: return 'c';                                   // ç

            // Letras maiúsculas
            case 0x81: case 0x80: case 0x82: case 0x83: return 'a';  // Á À Â Ã
            case 0x89: case 0x88: case 0x8A: return 'e';             // É È Ê
            case 0x8D: case 0x8C: case 0x8E: return 'i';             // Í Ì Î
            case 0x93: case 0x92: case 0x94: case 0x95: return 'o';  // Ó Ò Ô Õ
            case 0x9A: case 0x99: case 0x9B: return 'u';             // Ú Ù Û
            case 0x87: return 'c';                                   // Ç
        }
    }

    return 0; // Não é acentuado tratado
}

// Função para normalizar uma string (remover acentos, converter para minúsculas, remover não-alnum)
void normalizar(char *str) {
    char temp[256];
    int i = 0, j = 0;

    while (str[i]) {
        unsigned char c = str[i];

        if (c < 128) {
            // ASCII normal
            if (isalnum(c)) {
                temp[j++] = tolower(c);
            }
            i++;
        } else {
            // Provavelmente início de um caractere UTF-8 multibyte
            unsigned char c1 = str[i];
            unsigned char c2 = str[i + 1];

            char substituto = ehAcentuado(c1, c2);
            if (substituto) {
                temp[j++] = substituto;
            }
            i += 2; // Pular o caractere UTF-8
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}

void inserir_inicio(struct Fila *lista, char letra) {
    struct no *n = (struct no*)malloc(sizeof(struct no));
    n->letra = letra;
    n->prev = NULL;
    n->next = lista->inicio;
    if(lista->inicio) {
        lista->inicio->prev = n;
    } else {
        lista->fim = n;
    }
    lista->inicio = n;
}

void liberarMemoria(struct Fila *lista){
    struct no *p = lista->inicio;
    while(p){
        struct no *q = p->next;
        free(p);
        p = q;
    }
    lista->inicio = lista->fim = NULL;
}

bool ehPalindroma(const char *str){
    if(!str) return false;
    int quantLetras = (int)strlen(str);
    if(quantLetras < 2) return true;

    struct Fila lista; 
    lista.inicio = NULL; 
    lista.fim = NULL;

    //inserir cada caractere
    for(int i = 0; i < quantLetras; i++) {
        inserir_inicio(&lista, str[i]);
    }

    struct no *a = lista.inicio; // último caractere
    struct no *b = lista.fim;    // primeiro caractere 

    // Comparar pares até metade
    for(int j = 0; j < quantLetras / 2; j++) {
        if(!a || !b || a->letra != b->letra){ //faz a verificação das duas letras para saber se são iguais
            liberarMemoria(&lista);// caso forem diferentes ja manda liberar a memoria e retorna falso
            return false;
        }
        //vai para as proximas letras
        a = a->next;
        b = b->prev;
    }

    liberarMemoria(&lista);
    return true;
}