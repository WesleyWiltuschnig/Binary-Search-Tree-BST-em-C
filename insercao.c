#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/* ──────────────────────────────────────────────
 * Criar nó
 * ────────────────────────────────────────────── */
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor    = valor;
    novo->esquerda = NULL;
    novo->direita  = NULL;
    return novo;
}

/* ──────────────────────────────────────────────
 * Inserção recursiva
 * Duplicatas são ignoradas.
 * ────────────────────────────────────────────── */
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita  = inserir(raiz->direita, valor);

    return raiz;
}
