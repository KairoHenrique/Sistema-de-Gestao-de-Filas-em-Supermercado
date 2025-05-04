#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    char Nome[100];
    int CPF;
    int Prioridade;
    int NumItens;
    struct Cliente* Proximo;
} Cliente;

Cliente* criarCliente(char* nome, int cpf, int prioridade, int numItens);

#endif
