#ifndef CAIXA_H
#define CAIXA_H

#include "filaPrioridade.h"

#define NUMERO_CAIXAS 5

typedef struct {
    int Numero;
    int Aberto;
    FilaPrioridade filaPrioridade;
} Caixa;

void inicializarCaixas(Caixa* caixas);

#endif
