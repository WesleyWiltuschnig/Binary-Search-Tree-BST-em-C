#include <stddef.h>
#include "arvore.h"

/* ──────────────────────────────────────────────
 * Busca recursiva
 * Retorna o nó encontrado ou NULL.
 * ────────────────────────────────────────────── */
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);

    return buscar(raiz->direita, valor);
}
