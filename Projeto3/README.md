# Trabalho 1 - Verificação de Palíndromos

Projeto desenvolvido em linguagem C para verificar se palavras ou frases são palíndromos. O programa lê um arquivo de entrada, processa cada linha, remove acentos, espaços e caracteres especiais, e informa se a sequência é ou não um palíndromo.

## Funcionalidades

- Leitura de um arquivo de entrada (`data.txt`);
- Normalização das palavras e frases:
  - Conversão para letras minúsculas;
  - Remoção de acentos;
  - Remoção de espaços e caracteres não alfanuméricos;
- Verificação de palíndromos utilizando uma lista duplamente encadeada;
- Impressão do resultado no terminal;
- Geração do arquivo de saída (`saida.txt`).

## Estrutura do Projeto

```
.
├── main.c              # Programa principal
├── Palindromo.c        # Implementação das funções
├── Palindromo.h        # Definições e protótipos
├── data.txt            # Arquivo de entrada
├── saida.txt           # Arquivo de saída gerado
├── makefile            # Compilação do projeto
└── README.md
```

## Como funciona

Para cada linha presente em `data.txt`, o programa:

1. Lê a palavra ou frase;
2. Remove acentos;
3. Converte todas as letras para minúsculas;
4. Remove caracteres que não sejam letras ou números;
5. Insere cada caractere em uma lista duplamente encadeada;
6. Compara os caracteres das extremidades até o centro;
7. Exibe:

- `1` → É palíndromo;
- `0` → Não é palíndromo.

Os mesmos resultados também são gravados no arquivo `saida.txt`.

## Exemplo

### Entrada (`data.txt`)

```
arara
Socorram-me subi no ônibus em Marrocos
computador
A grama é amarga
```

### Saída (`saida.txt`)

```
1
1
0
1
```

## Compilação

Utilizando o Makefile:

```bash
make
```

## Execução

```bash
make run
```

ou

```bash
./palindromo
```

## Limpeza dos arquivos compilados

```bash
make clean
```

## Tecnologias utilizadas

- Linguagem C (C11)
- GCC
- Makefile

## Autor

Desenvolvido como Trabalho 1 da disciplina de Estruturas de Dados.
