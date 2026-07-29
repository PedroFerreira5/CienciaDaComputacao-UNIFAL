#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Palindromo.h"
/* +--[Trabalho 1: verificação de palavras palindromas]--+

    O projeto pega um arquivo de entrada(data.txt), onde
    tem uma palavra ou frase por linha para fazer a verificação
    se é palindromo ou não e retorna no terminal e em um arquivo 
    de saida(saida.txt) o resultado de cada linha do arquivo de entrada.
*/

int main(){
    FILE *entrada = fopen("data.txt","r");
    FILE *saida = fopen("saida.txt","w");
    char palavra[128];
    while(fgets(palavra, sizeof palavra, entrada)){
        palavra[strcspn(palavra, "\r\n")] = '\0';

        normalizar(palavra);
        if(ehPalindroma(palavra)){
            printf("%d\n",1);
            fprintf(saida,"1\n");
        }else{
            printf("%d\n",0);
            fprintf(saida, "0\n");
        }
    }
    fclose(entrada);
    fclose(saida);
}