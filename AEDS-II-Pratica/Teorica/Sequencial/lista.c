#include <stdlib.h>
#include <stdio.h>
#include "variaveis.h"

int insere(No no){
    if (m < n) { // ainda há espaço no vetor
        if (busca2(no.chave) == -1) { // não existe ainda (melhor usar -1 do que 0 para "não encontrado")
            L[m] = no;  // coloca o nó no final
            m++;        // aumenta o tamanho
            return 1;   // sucesso
        } else {
            return 0;   // chave duplicada
        }
    }
    return -1; // lista cheia
}

No *removeLista(int x){
    No *retorno = NULL; //variavel de retorno começa em null
    
    if(m != 0){
        int indice = busca2(x); //variavel que guarda o indice do item a ser removido

        if(indice != -1){ 
            retorno = &L[indice]; //salva o endereço do endereço a ser removido da lista

            for(int i = indice; i < m; i++){ //loop para corrigir os valores dentro da lista
                L[i] = L[i+1]; 
            }

            m--; 
        }
    }
    return retorno; //retorna o endereço do item removido
}