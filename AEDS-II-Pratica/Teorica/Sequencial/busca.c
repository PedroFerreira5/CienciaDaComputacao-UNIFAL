#include <stdlib.h>
#include <stdio.h>
#include "variaveis.h"

int busca(int x){
    int i = 0; int busca1=-1;
    while(i <= n){
        if(L[i].chave = x){
            busca1 = i;
            i=n+1;
        } else{
            i++;
        }
    }   
    return busca;
}

int busca2(int x){
    int i = 0; int busca2;
    L[n].chave = x;
    while(L[i].chave != x){
        i++;
    } if(i != n){
        busca2 = i; //Caso seja encontramos a chave no vetor e retornamos a posicao
    } else {
        busca2 = -1; //Caso nao seja, a chave nao se encontra no vetor e retornamos -1
    }
    

}