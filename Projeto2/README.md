# Manipulador de Imagens PGM

Projeto acadêmico em C++ para manipulação de imagens no formato **PGM (Portable Gray Map)**, utilizando **ponteiros** para percorrer e transformar matrizes de pixels carregadas a partir de arquivos-texto.

## 👥 Autores

- Guilherme de Oliveira Aredes 
- Pedro Ferreira Prado 

**Data:** 20/02/2025

## 🎯 Objetivo

Adquirir conhecimentos de manipulação de matrizes (imagens) com ponteiros, implementando funcionalidades que geram novas matrizes (imagens) a partir de valores carregados de arquivos-texto em formato PGM.

## 🖼️ Sobre o formato PGM

O programa trabalha com o formato **PGM ASCII (P2)**, que representa imagens em tons de cinza como texto puro. A estrutura do arquivo é:

```
P2
<colunas> <linhas>
<valor máximo de cinza>
<pixel 1> <pixel 2> <pixel 3> ...
```

> ⚠️ A leitura atual (`lerImagem`) não trata linhas de comentário iniciadas com `#`, portanto os arquivos de entrada não devem conter esse tipo de linha.

## ⚙️ Funcionalidades

O programa oferece um menu interativo com as seguintes opções:

| Opção | Funcionalidade | Descrição |
|-------|-----------------|-----------|
| 1 | Ler imagem PGM | Carrega uma imagem a partir de um arquivo `.pgm` (formato P2) |
| 2 | Clarear imagem | Aumenta o valor dos pixels por um fator informado (limitado ao valor máximo) |
| 3 | Escurecer imagem | Diminui o valor dos pixels por um fator informado (limitado a 0) |
| 4 | Rotacionar para direita | Gira a imagem 90° no sentido horário |
| 5 | Rotacionar para esquerda | Gira a imagem 90° no sentido anti-horário |
| 6 | Negativa da imagem | Inverte os tons (calcula `maxValor - pixel`) |
| 7 | Binarizar imagem | Converte a imagem para preto e branco com base em um limiar |
| 8 | Iconizar imagem | Reduz a imagem para um ícone de 64x64 pixels |
| 0 | Sair | Encerra o programa e libera a memória alocada |

## 🧠 Estrutura do código

- **`lerImagem`** — abre o arquivo, valida o formato P2, lê as dimensões e aloca dinamicamente a matriz de pixels.
- **`escreverImagem`** — grava a matriz de pixels em disco, respeitando o cabeçalho PGM.
- **`clarearImagem` / `escurecerImagem`** — percorrem o array via ponteiros, ajustando cada pixel.
- **`rotacionarDireita` / `rotacionarEsquerda`** — geram uma nova matriz com as dimensões trocadas (linhas ↔ colunas), reposicionando cada pixel.
- **`negativaImagem`** — inverte os tons da imagem.
- **`binarizarImagem`** — aplica um limiar, transformando a imagem em preto e branco.
- **`iconizarImagem`** — reamostra a imagem original para uma versão reduzida de 64x64 pixels.

Todas as funções que alteram a imagem trabalham diretamente com ponteiros (`int*`), percorrendo a matriz de forma linear ou calculando o deslocamento (offset) equivalente às posições de linha/coluna.

## 🛠️ Como compilar

É necessário um compilador C++ compatível com C++11 ou superior (ex: `g++`).

```bash
g++ -o pgm_editor main.cpp
```

## ▶️ Como executar

```bash
./pgm_editor
```

Ao rodar o programa, o menu será exibido no terminal. Basta digitar o número da opção desejada e seguir as instruções (nome do arquivo de entrada/saída, fatores, limiares, etc).

### Exemplo de uso

```
=== MENU PGM ===
1. Ler imagem PGM
2. Clarear imagem
3. Escurecer imagem
4. Rotacionar para direita
5. Rotacionar para esquerda
6. Negativa da imagem
7. Binarizar imagem
8. Iconizar imagem (64x64)
0. Sair
Escolha uma opcao: 1
Nome do arquivo PGM de entrada: imagem.pgm
Imagem carregada com sucesso: 256x256 pixels
```

## ⚠️ Observações

- É necessário carregar uma imagem (opção 1) antes de usar as demais funcionalidades — caso contrário, o programa exibirá uma mensagem de erro.
- Nas operações de rotação, as dimensões da imagem resultante são invertidas (a largura original vira a altura, e vice-versa).
- A memória alocada dinamicamente é liberada automaticamente ao final de cada operação de rotação/iconização e ao encerrar o programa.
- Os arquivos de entrada devem estar em formato PGM P2 puro, sem linhas de comentário (`#`) e sem quebras adicionais no cabeçalho.
- O programa não impede que o arquivo de saída tenha o mesmo nome do arquivo de entrada — nesse caso, o arquivo original será sobrescrito.
- As únicas rotações disponíveis são de 90° para a direita e para a esquerda; não há operação de espelhamento (flip) horizontal ou vertical.
- Mensagens de erro e confirmação (`cout`) são exibidas tanto pela `main` quanto pelas funções de processamento (ex: `lerImagem`, `escurecerImagem`), não ficando restritas apenas à função `main`.

## 📄 Licença

Projeto acadêmico desenvolvido para fins educacionais.
