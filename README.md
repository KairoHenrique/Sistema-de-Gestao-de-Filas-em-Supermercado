# 🛒 Sistema de Gestão de Filas em Supermercado 🛒

- **Aluno:** Kairo Henrique Ferreira Martins  
- **Professor:** Eduardo Habib Bechelane Maia  
- **Disciplina:** INTRODUÇÃO À PROGRAMAÇÃO DE COMPUTADORES

---

## Introdução

Este projeto em C implementa um sistema de gestão de filas para um supermercado com múltiplos caixas.  
Clientes são cadastrados com nome, CPF, prioridade de atendimento e número de itens no carrinho.  
O operador pode abrir/fechar caixas, realocar clientes de caixas fechados e chamar clientes de acordo com sua prioridade.

---

## Objetivos

- Modelar filas de atendimento com prioridade (alta, média, baixa).  
- Permitir cadastro e atendimento de clientes em diferentes caixas.  
- Controlar abertura e fechamento de caixas, realocando filas conforme necessidade.  
- Exibir relatórios em console: status dos caixas e conteúdo das filas.

---

## Funcionalidades Principais

1. **Cadastro de Clientes**  
   - Usuário informa nome, CPF, prioridade (1-Alta, 2-Média, 3-Baixa) e número de itens.  
   - Cliente é inserido na fila do caixa escolhido, respeitando ordem de prioridade.

2. **Atendimento de Clientes**  
   - Remove (desenfileira) o primeiro cliente da fila prioritária do caixa escolhido.  
   - Exibe nome do cliente atendido.

3. **Abertura/Fechamento de Caixas**  
   - Lista caixas abertos e fechados.  
   - Ao fechar um caixa, todos os clientes em sua fila são realocados automaticamente para o primeiro caixa aberto.  
   - Ao abrir um caixa, ele volta a receber novos cadastros.

4. **Visualização de Filas e Caixas**  
   - Menu para imprimir, a qualquer momento:
     - A lista de clientes em espera em cada caixa (com nome, CPF, prioridade e itens).  
     - O status (Aberto/Fechado) de todos os caixas.

---

## Estrutura do Projeto
```

├── .gitignore
├── Trabalho2_2024.pdf # Enunciado e documentação da proposta
├── caixa.h # Declarações da struct Caixa e funções de gerenciamento
├── caixa.c # Implementação de inicialização, impressão e realocação
├── cliente.h # Declarações da struct Cliente e construtor
├── cliente.c # Função de criação e liberação de Cliente
├── filaPrioridade.h # Protótipos de enfileirar/desenfileirar com prioridade
├── filaPrioridade.c # Implementação de fila prioritária usando listas ligadas
├── main.c # Interface de menu e loop principal

```

---

## Descrição dos Módulos

### `cliente.h` / `cliente.c`

- **`struct Cliente`**  
  Armazena nome, CPF, prioridade e número de itens.  
- **`criarCliente(...)`**  
  Aloca e inicializa um novo cliente.  
- **`liberarCliente(...)`**  
  Desaloca corretamente o cliente após atendimento.

### `caixa.h` / `caixa.c`

- **`struct Caixa`**  
  Contém número do caixa, flag `Aberto` e `filaPrioridade` (fila de clientes).  
- **`inicializarCaixas(...)`**  
  Configura todos os caixas como abertos e filas vazias.  
- **`imprimirCaixasAbertos/Fechados(...)`**  
  Exibe no console quais caixas estão disponíveis ou não.  
- **`realocarClientes(...)`**  
  Move toda a fila de um caixa fechado para o primeiro caixa aberto.

### `filaPrioridade.h` / `filaPrioridade.c`

- Implementa enfileiramento e desenfileiramento de clientes em ordem de prioridade:
  - Primeiro clientes de prioridade 1, depois 2, depois 3.  
  - Usa lista ligada ou arrays de ponteiros internos para manter a ordem.

### `main.c`

- Menu interativo com opções:
  1. Cadastrar um Cliente  
  2. Atender um Cliente  
  3. Abrir/Fechar um Caixa  
  4. Imprimir Filas de Espera  
  5. Imprimir Status dos Caixas  
  0. Sair  
- Chama funções dos módulos conforme escolha do usuário.  
- Usa `getchar()` para pausar entre operações.

---

## Como Compilar e Executar

Requisitos: GCC (ou qualquer compilador C compatível), Make (opcional)

```bash
# Se houver Makefile
make all

# Ou compilação manual:
gcc -o gestor_fifo main.c caixa.c cliente.c filaPrioridade.c

# Executar
./gestor_fifo

Exemplo de Uso

Menu:
1. Cadastrar um Cliente
2. Atender um Cliente
3. Abrir ou Fechar um Caixa
4. Imprimir a Lista de Clientes em Espera
5. Imprimir o Status dos Caixas
0. Sair

Escolha uma opção: 1
Digite o nome do cliente: João Silva
Digite o CPF: 123456789
Digite a prioridade (1: Alta, 2: Média, 3: Baixa): 1
Digite o número de itens no carrinho: 15
Caixas Abertos:
Caixa 1
Caixa 2
Escolha o número do caixa: 1
Cliente adicionado ao caixa 1.
Pressione Enter para continuar...

Autor

    Kairo Henrique Ferreira Martins