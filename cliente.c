#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* criarCliente(char* nome, int cpf, int prioridade, int numItens) {
    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }
    strcpy(novoCliente->Nome, nome);
    novoCliente->CPF = cpf;
    novoCliente->Prioridade = prioridade;
    novoCliente->NumItens = numItens;
    novoCliente->Proximo = NULL;
    return novoCliente;
}
