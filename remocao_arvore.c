#include <stddef.h>
#include <stdlib.h>
#include "arvore.h"

/* ──────────────────────────────────────────────
 * Remoção completa da árvore (pós-ordem)
 * Libera todos os nós e retorna NULL.
 *
 * Uso:
 *   raiz = removerArvore(raiz);
 * ────────────────────────────────────────────── */
No* removerArvore(No* raiz) {
    if (raiz == NULL) return NULL;

    raiz->esquerda = removerArvore(raiz->esquerda);
    raiz->direita  = removerArvore(raiz->direita);
    free(raiz);
    return NULL;
}
