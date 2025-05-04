#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"
#include "cliente.h"
#include "filaPrioridade.h"

void imprimirCaixasAbertos(Caixa* caixas) {
    printf("\nCaixas Abertos:\n");
    for (int i = 0; i < NUMERO_CAIXAS; i++) {
        if (caixas[i].Aberto) {
            printf("Caixa %d\n", caixas[i].Numero);
        }
    }
}

void imprimirCaixasFechados(Caixa* caixas) {
    printf("\nCaixas Fechados:\n");
    for (int i = 0; i < NUMERO_CAIXAS; i++) {
        if (!caixas[i].Aberto) {
            printf("Caixa %d\n", caixas[i].Numero);
        }
    }
}

int escolherCaixa(Caixa* caixas) {
    int numeroCaixa;
    while (1) {
        imprimirCaixasAbertos(caixas);
        printf("Escolha o numero do caixa: ");
        scanf("%d", &numeroCaixa);

        if (numeroCaixa < 1 || numeroCaixa > NUMERO_CAIXAS) {
            printf("Caixa invalido. Tente novamente.\n");
        } else if (!caixas[numeroCaixa - 1].Aberto) {
            printf("Caixa %d esta fechado. Escolha outro caixa.\n", numeroCaixa);
        } else {
            return numeroCaixa;
        }
    }
}

void realocarClientes(Caixa* caixas, int caixaFechado) {
    for (int i = 0; i < NUMERO_CAIXAS; i++) {
        if (i != caixaFechado && caixas[i].Aberto) {
            Cliente* cliente = desenfileirarCliente(&caixas[caixaFechado].filaPrioridade);
            while (cliente != NULL) {
                enfileirarCliente(&caixas[i].filaPrioridade, cliente);
                cliente = desenfileirarCliente(&caixas[caixaFechado].filaPrioridade);
            }
            printf("Clientes do caixa %d realocados para o caixa %d.\n", caixaFechado + 1, i + 1);
            break;
        }
    }
}

void imprimirMenuPrincipal() {
    printf("\nMenu:\n");
    printf("1. Cadastrar um Cliente\n");
    printf("2. Atender um Cliente\n");
    printf("3. Abrir ou Fechar um Caixa\n");
    printf("4. Imprimir a Lista de Clientes em Espera\n");
    printf("5. Imprimir o Status dos Caixas\n");
    printf("0. Sair\n");
}

void pausar() {
    printf("Pressione Enter para continuar...");
    getchar(); // Espera o usuario apertar Enter
    getchar(); 
}

int main() {
    int opcao;
    char continuar;
    Caixa caixas[NUMERO_CAIXAS];

    // Inicializa os caixas
    inicializarCaixas(caixas);

    do {
        imprimirMenuPrincipal();

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        int numeroCaixa;

        switch (opcao) {
            case 1: // Cadastrar um Cliente
                do {
                    char nomeCliente[100];
                    int cpf, prioridade, numItens;

                    printf("Digite o nome do cliente: ");
                    scanf(" %[^\n]", nomeCliente); // Recebe uma string

                    printf("Digite o CPF: ");
                    scanf("%d", &cpf);

                    printf("Digite a prioridade (1: Alta, 2: Media, 3: Baixa): ");
                    scanf("%d", &prioridade);

                    printf("Digite o numero de itens no carrinho: ");
                    scanf("%d", &numItens);

                    // Chama a funcao para escolher o caixa
                    numeroCaixa = escolherCaixa(caixas);

                    // Cria o cliente e adiciona a fila do caixa
                    Cliente* novoCliente = criarCliente(nomeCliente, cpf, prioridade, numItens);
                    enfileirarCliente(&caixas[numeroCaixa - 1].filaPrioridade, novoCliente);

                    printf("Cliente adicionado ao caixa %d.\n", numeroCaixa);

                    printf("Deseja adicionar outro cliente? (s/n): ");
                    scanf(" %c", &continuar); 

                } while (continuar == 's' || continuar == 'S');

                pausar();
                break;

            case 2: // Atender um Cliente
                numeroCaixa = escolherCaixa(caixas);

                Cliente* clienteAtendido = desenfileirarCliente(&caixas[numeroCaixa - 1].filaPrioridade);
                if (clienteAtendido != NULL) {
                    printf("Cliente %s atendido no caixa %d.\n", clienteAtendido->Nome, numeroCaixa);
                    free(clienteAtendido);
                } else {
                    printf("Nao ha clientes na fila do caixa %d.\n", numeroCaixa);
                }

                pausar();
                break;

            case 3: // Abrir ou Fechar um Caixa
                imprimirCaixasAbertos(caixas);
                imprimirCaixasFechados(caixas); // Exibe os caixas fechados
                printf("Digite o numero do caixa para abrir/fechar: ");
                scanf("%d", &numeroCaixa);

                if (caixas[numeroCaixa - 1].Aberto) {
                    caixas[numeroCaixa - 1].Aberto = 0; // Fecha o caixa
                    printf("Caixa %d fechado.\n", numeroCaixa);
                    realocarClientes(caixas, numeroCaixa - 1); // Realoca clientes
                } else {
                    caixas[numeroCaixa - 1].Aberto = 1; // Abre o caixa
                    printf("Caixa %d aberto.\n", numeroCaixa);
                }

                pausar();
                break;

            case 4: // Imprimir a Lista de Clientes em Espera
                for (int i = 0; i < NUMERO_CAIXAS; i++) {
                    printf("Caixa %d:\n", caixas[i].Numero);
                    imprimirFila(&caixas[i].filaPrioridade);
                }

                pausar();
                break;

            case 5: // Imprimir o Status dos Caixas
                for (int i = 0; i < NUMERO_CAIXAS; i++) {
                    printf("Caixa %d - %s\n", caixas[i].Numero, caixas[i].Aberto ? "Aberto" : "Fechado");
                }

                pausar();
                break;

            case 0: // Sair
                printf("Saindo\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                pausar();
                break;
        }
    } while (opcao != 0);

    return 0;
}
