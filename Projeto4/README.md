# Trabalho 2 - Ordenação de Arquivos Maiores que a Memória

Projeto desenvolvido em linguagem C com o objetivo de ordenar arquivos contendo uma quantidade de registros maior do que a memória principal disponível, utilizando técnicas de ordenação externa.

## Objetivo

Implementar um algoritmo capaz de ordenar um arquivo de inteiros armazenado em disco, dividindo o processamento em etapas para que apenas uma parte dos dados permaneça em memória por vez.

O projeto também inclui um gerador de arquivos de teste em C++ para facilitar a criação de conjuntos de dados de diferentes tamanhos.

## Funcionalidades

- Leitura de um arquivo contendo números inteiros;
- Divisão do arquivo em blocos compatíveis com a memória disponível;
- Ordenação de cada bloco individualmente;
- Escrita dos blocos temporários em disco;
- Intercalação (merge) dos blocos ordenados;
- Geração do arquivo final completamente ordenado;
- Gerador de arquivos de teste.

## Estrutura do Projeto

```
.
├── OrdenacaoDoArquivo(trabalho2)
│   ├── main.c              # Programa principal
│   ├── ordenacao.c         # Implementação dos algoritmos
│   ├── ordenacao.h         # Protótipos e definições
│   └── Makefile            # Compilação
│
├── GeradorDoArquivo
│   └── main.cpp            # Gerador de arquivos de teste
│
└── README.md
```

## Como funciona

O programa realiza a ordenação em duas etapas principais:

1. **Criação dos blocos**
   - O arquivo é dividido em partes menores;
   - Cada bloco é carregado para a memória;
   - Os elementos são ordenados internamente;
   - O bloco ordenado é salvo como arquivo temporário.

2. **Intercalação (Merge)**
   - Todos os arquivos temporários são abertos simultaneamente;
   - O menor elemento entre eles é selecionado;
   - O valor é escrito no arquivo final;
   - O processo continua até que todos os registros tenham sido copiados.

Essa estratégia permite ordenar arquivos cujo tamanho ultrapassa a capacidade da memória RAM.

## Compilação

Entre na pasta do projeto:

```bash
cd OrdenacaoDoArquivo\(trabalho2\)
```

Compile utilizando:

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

(caso exista essa regra no Makefile)

## Gerador de Arquivos

O diretório `GeradorDoArquivo` contém um programa em C++ utilizado para criar arquivos de entrada para testes.

Compilação:

```bash
g++ main.cpp -o gerador
```

Execução:

```bash
./gerador
```

## Tecnologias Utilizadas

- Linguagem C
- Linguagem C++
- GCC / G++
- Makefile

## Conceitos Aplicados

- Ordenação Externa
- Manipulação de Arquivos
- Estruturas de Dados
- Algoritmos de Intercalação (Merge)
- Gerenciamento de Memória

## Autor

Desenvolvido como Trabalho 2 da disciplina de Estruturas de Dados.
