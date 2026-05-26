#include <stdio.h>
#include "arvore.h"

/* ──────────────────────────────────────────────
 * Travessias para visualização da árvore
 * ────────────────────────────────────────────── */

void emOrdem(No* raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

void preOrdem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void posOrdem(No* raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->valor);
}
