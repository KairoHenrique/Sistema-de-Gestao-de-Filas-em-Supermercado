#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridade.h"

void inicializarFila(FilaPrioridade* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enfileirarCliente(FilaPrioridade* fila, Cliente* cliente) {
    if (fila->fim == NULL) {
        fila->inicio = cliente;
        fila->fim = cliente;
    } else {
        fila->fim->Proximo = cliente;
        fila->fim = cliente;
    }
}

Cliente* desenfileirarCliente(FilaPrioridade* fila) {
    if (fila->inicio == NULL) {
        return NULL;
    }
    Cliente* cliente = fila->inicio;
    fila->inicio = cliente->Proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    return cliente;
}

void imprimirFila(FilaPrioridade* fila) {
    Cliente* atual = fila->inicio;
    while (atual != NULL) {
        printf("Cliente: %s, CPF: %d, Prioridade: %d, Itens: %d\n", 
               atual->Nome, atual->CPF, atual->Prioridade, atual->NumItens);
        atual = atual->Proximo;
    }
}
