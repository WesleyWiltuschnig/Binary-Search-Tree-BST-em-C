#include <stdlib.h>
#include "arvore.h"

/* ──────────────────────────────────────────────
 * Auxiliar: menor nó de uma subárvore
 * ────────────────────────────────────────────── */
No* encontrarMinimo(No* raiz) {
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

/* ──────────────────────────────────────────────
 * Remoção de um nó — três casos:
 *   1. Nó folha         → remove diretamente
 *   2. Um filho         → substitui pelo filho
 *   3. Dois filhos      → substitui pelo sucessor
 *                         in-order (mínimo da direita)
 * ────────────────────────────────────────────── */
No* remover(No* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita  = remover(raiz->direita, valor);
    } else {
        /* Nó encontrado */
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        /* Dois filhos: copia valor do sucessor e o remove */
        No* succ      = encontrarMinimo(raiz->direita);
        raiz->valor   = succ->valor;
        raiz->direita = remover(raiz->direita, succ->valor);
    }

    return raiz;
}
