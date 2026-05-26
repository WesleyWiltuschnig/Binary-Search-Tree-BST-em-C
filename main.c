#include <stdio.h>
#include "arvore.h"

int main(void) {
    No* raiz = NULL;

    /* Inserção */
    printf("=== Inserção ===\n");
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
        printf("Inserido: %d\n", valores[i]);
    }

    /* Travessias */
    printf("\n=== Travessias ===\n");
    printf("Em ordem   : "); emOrdem(raiz);  printf("\n");
    printf("Pré-ordem  : "); preOrdem(raiz); printf("\n");
    printf("Pós-ordem  : "); posOrdem(raiz); printf("\n");

    /* Busca */
    printf("\n=== Busca ===\n");
    int alvo    = 40;
    No* result  = buscar(raiz, alvo);
    printf("Buscar %d: %s\n", alvo, result ? "encontrado" : "não encontrado");

    alvo   = 99;
    result = buscar(raiz, alvo);
    printf("Buscar %d: %s\n", alvo, result ? "encontrado" : "não encontrado");

    /* Remoção de nó folha */
    printf("\n=== Remoção: nó folha (20) ===\n");
    raiz = remover(raiz, 20);
    printf("Em ordem: "); emOrdem(raiz); printf("\n");

    /* Remoção de nó com um filho */
    printf("\n=== Remoção: nó com um filho (30) ===\n");
    raiz = remover(raiz, 30);
    printf("Em ordem: "); emOrdem(raiz); printf("\n");

    /* Remoção de nó com dois filhos */
    printf("\n=== Remoção: nó com dois filhos (50) ===\n");
    raiz = remover(raiz, 50);
    printf("Em ordem: "); emOrdem(raiz); printf("\n");

    /* Remoção da árvore inteira */
    printf("\n=== Remoção da árvore inteira ===\n");
    raiz = removerArvore(raiz);
    printf("Árvore removida. raiz = %s\n", raiz == NULL ? "NULL" : "não nula");

    return 0;
}
