# Sistema de Gerenciamento de Imóveis (C++)

Sistema em C++ desenvolvido para leitura, manipulação, busca e persistência de dados de imóveis a partir de um arquivo de texto de banco de dados (`BD_Imoveis2`). 

O projeto foi desenvolvido como trabalho acadêmico por **Francisco Tóro Tonissi** e **Pedro Ferreira Prado**.

---

## 📋 Sumário
- [Características](#-características)
- [Estrutura de Dados](#-estrutura-de-dados)
- [Funcionalidades](#-funcionalidades)
- [Estrutura do Arquivo de Dados](#-estrutura-do-arquivo-de-dados)
- [Como Compilar e Executar](#-como-compilar-e-executar)
- [Autores](#-autores)

---

## 🛠 Características

- **Capacidade:** Suporta até 200 registros armazenados em memória via vetor de structs.
- **Persistência em Arquivo:** Lê dados do arquivo `BD_Imoveis2` no início da execução.
- **Formatação amigável:** Strings tratadas com underline (`_`) no lugar de espaços para facilitar leitura via *stream* de arquivo.

---

## 📐 Estrutura de Dados

O imóvel é representado pela estrutura `Imovel`:

```cpp
typedef struct {
    char Tipo[30];          // casa, apartamento, terreno, sala_comercial, galpao
    char Finalidade[10];    // venda, locacao, temporada
    char Endereco[50];      // Endereço (utiliza '_' no lugar de espaços)
    char Bairro[20];        // Bairro
    char Cidade[20];        // Cidade
    int Area;               // Área em m²
    char Valor[12];         // Valor de venda ou aluguel (ex: "250000" ou "1500/dia")
    int IPTU;               // Valor do IPTU
    int Quartos;            // Qtd. de quartos
    int Suites;             // Qtd. de suítes
    int Banheiros;          // Qtd. de banheiros
    int Vagas;              // Qtd. de vagas de garagem
    char Cozinha[4];        // sim / não
    char Sala[4];           // sim / não
    char Varanda[4];        // sim / não
    char AreaServico[4];    // sim / não
    char Piso[20];          // Tipo de piso (ex: ceramica, madeira)
    char Estado[10];        // novo, usado, reformado
    char Armarios[4];       // sim / não
    char ArCondicionado[4]; // sim / não
    char Aquecedor[4];      // sim / não
    char Ventilador[4];     // sim / não
} Imovel;
```

---

## 🚀 Funcionalidades

1. **Inclusão de Novo Imóvel (`menuInclusao`):**
   - Cadastro guiado via terminal com validação de dados de entrada.
   - Conversão automática de opções numéricas para strings correspondentes.

2. **Menu de Busca Avançada (`menuBusca`):**
   - Busca por **Tipo** (Casa, Apartamento, Terreno, Sala Comercial, Galpão).
   - Busca por **Finalidade** (Venda, Aluguel, Temporada).
   - Busca por **Endereço**, **Bairro** ou **Cidade**.
   - Busca por **Faixa de Área** (mínima e máxima em m²).
   - Busca por **Faixa de Valor** (mínimo e máximo para compra ou aluguel).

3. **Relatório de Estatísticas (`relatorio`):**
   - Total de imóveis cadastrados.
   - Porcentagem de imóveis por finalidade (Venda vs. Locação).
   - Porcentagem de casas que possuem suítes.
   - Porcentagem de salas comerciais com piso de cerâmica.

4. **Listagem de Imóveis (`listarImoveis`):**
   - Exibe todos os imóveis cadastrados e seus detalhes formatados na tela.

5. **Exclusão de Imóvel (`excluirImovel`):**
   - Permite localizar um imóvel por Endereço, Tipo, Bairro ou Cidade.
   - Exige confirmação prévia e realiza o reposicionamento dos elementos no vetor.

---

## 📂 Estrutura do Arquivo de Dados

O arquivo de entrada/saída `BD_Imoveis2` deve estar no mesmo diretório do executável. Cada linha corresponde a um imóvel com os campos separados por espaços:

```text
casa venda Rua_das_Flores_123 Centro Alfenas 120 350000 500 3 1 2 2 sim sim sim sim ceramica novo sim sim nao sim
```

*Obs: Para termos compostos (como nomes de ruas, bairros ou cidades), utilize `_` (underline) em vez de espaço.*

---

## 💻 Como Compilar e Executar

### Pré-requisitos
- Compilador C++ (ex: `g++` ou `clang++`).

### Passos:
1. Garanta que o arquivo de dados `BD_Imoveis2` exista no mesmo diretório do código-fonte.
2. Compile o código:
   ```bash
   g++ -Wall -Wextra main.cpp -o geraci_imoveis
   ```
3. Execute o programa:
   ```bash
   ./geraci_imoveis
   ```

---

## 👥 Autores

- **Francisco Tóro Tonissi** 
- **Pedro Ferreira Prado** 
