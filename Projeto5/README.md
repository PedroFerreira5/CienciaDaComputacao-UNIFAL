# Trabalho 3 - Ordenação de Structs

Projeto desenvolvido em linguagem C para comparar diferentes algoritmos de ordenação aplicados a um vetor de estruturas (`struct`) contendo informações de jogadores de futebol. Além da ordenação, o programa mede métricas de desempenho como tempo de execução, número de comparações, movimentações e estimativa de memória utilizada.

## Objetivo

Implementar e comparar algoritmos de ordenação sobre registros estruturados (`struct`), avaliando sua eficiência na ordenação de jogadores pelo campo **nome**.

## Funcionalidades

- Leitura dos dados a partir de um arquivo CSV (`jogadores.csv`);
- Armazenamento dos registros em um vetor de estruturas;
- Ordenação pelo nome do jogador;
- Comparação entre diferentes algoritmos de ordenação;
- Exibição das métricas de desempenho:
  - Tempo de execução;
  - Número de comparações;
  - Número de movimentações;
  - Estimativa de memória utilizada.

## Algoritmos Implementados

### Bubble Sort
- Algoritmo simples baseado em trocas entre elementos adjacentes.
- Complexidade média: **O(n²)**.

### Merge Sort
- Algoritmo baseado na estratégia de divisão e conquista.
- Complexidade: **O(n log n)**.
- Utiliza memória auxiliar durante a intercalação.

### Radix Sort
- Ordenação linear aplicada aos nomes dos jogadores.
- Utiliza **Counting Sort** como algoritmo auxiliar.
- As strings são tratadas com `strxfrm()` para respeitar a ordenação definida pelo locale.

## Estrutura do Projeto

```
.
├── main.c            # Implementação completa do projeto
├── jogadores.csv     # Arquivo de entrada
├── makefile          # Compilação
└── README.md
```

## Estrutura dos Dados

Cada jogador é armazenado na seguinte estrutura:

```c
typedef struct {
    char nome[100];
    char posicao[50];
    char naturalidade[50];
    char clube[50];
    int idade;
} Jogador;
```

## Como funciona

1. O programa lê todos os registros presentes em `jogadores.csv`;
2. O usuário escolhe um dos algoritmos de ordenação;
3. Os jogadores são ordenados pelo campo **nome**;
4. Os registros ordenados são exibidos na tela;
5. Ao final são apresentadas as métricas de desempenho.

## Exemplo de Execução

```
-- Escolha um algoritmo de ordenação --

1: Ordenação Simples (Bubble)
2: Ordenação Ótima (Merge)
3: Ordenação Linear (Radix)

R: 2
```

Após a execução, o programa exibe:

- Lista dos jogadores ordenados;
- Tempo de execução (ms);
- Número de comparações;
- Número de movimentações;
- Memória estimada utilizada.

## Compilação

```bash
make
```

## Execução

```bash
./main
```

ou

```bash
make run
```

(caso a regra esteja presente no Makefile)

## Tecnologias Utilizadas

- Linguagem C
- GCC
- Makefile

## Conceitos Aplicados

- Structs
- Manipulação de arquivos CSV
- Alocação dinâmica de memória
- Bubble Sort
- Merge Sort
- Radix Sort
- Counting Sort
- Análise de desempenho de algoritmos
- Medição de tempo de execução

## Autores

- Diego Vianna Leite Montemor
- Francisco Toro Tonissi
- Pedro Ferreira Prado

Projeto desenvolvido para a disciplina de **Algoritmos e Estruturas de Dados II (AEDS II)**.
