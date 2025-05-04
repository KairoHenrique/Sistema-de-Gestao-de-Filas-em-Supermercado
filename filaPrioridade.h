#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "cliente.h"

typedef struct {
    Cliente* inicio;
    Cliente* fim;
} FilaPrioridade;

void inicializarFila(FilaPrioridade* fila);
void enfileirarCliente(FilaPrioridade* fila, Cliente* cliente);
Cliente* desenfileirarCliente(FilaPrioridade* fila);
void imprimirFila(FilaPrioridade* fila);

#endif
