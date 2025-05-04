#include <stdio.h>
#include "caixa.h"

void inicializarCaixas(Caixa* caixas) {
    for (int i = 0; i < NUMERO_CAIXAS; i++) {
        caixas[i].Numero = i + 1;  // Numeros de 1 a NUMERO_CAIXAS
        caixas[i].Aberto = 1;  // Todos os caixas comecam abertos
        inicializarFila(&caixas[i].filaPrioridade);
    }
}
