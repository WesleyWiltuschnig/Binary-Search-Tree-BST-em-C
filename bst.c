/*
 * Binary Search Tree (BST) em C
 * Operações: inserção, busca, remoção de nó e remoção da árvore
 */

#include <stdio.h>
#include <stdlib.h>

/* ──────────────────────────────────────────────
 * Definição da estrutura
 * ────────────────────────────────────────────── */
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

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
 * Inserção
 * ────────────────────────────────────────────── */
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita  = inserir(raiz->direita, valor);
    /* valor == raiz->valor: duplicatas são ignoradas */

    return raiz;
}

/* ──────────────────────────────────────────────
 * Busca
 * ────────────────────────────────────────────── */
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);

    return buscar(raiz->direita, valor);
}

/* ──────────────────────────────────────────────
 * Auxiliar: encontra o menor nó de uma subárvore
 * ────────────────────────────────────────────── */
No* encontrarMinimo(No* raiz) {
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

/* ──────────────────────────────────────────────
 * Remoção de um nó
 * Casos tratados:
 *   1. Nó folha                → remove diretamente
 *   2. Nó com um filho         → substitui pelo filho
 *   3. Nó com dois filhos      → substitui pelo sucessor
 *                                 in-order (mínimo da direita)
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
        /* Dois filhos: copia o valor do sucessor e remove o sucessor */
        No* succ      = encontrarMinimo(raiz->direita);
        raiz->valor   = succ->valor;
        raiz->direita = remover(raiz->direita, succ->valor);
    }

    return raiz;
}

/* ──────────────────────────────────────────────
 * Remoção completa da árvore (pós-ordem)
 * Libera todos os nós e retorna NULL
 * ────────────────────────────────────────────── */
No* removerArvore(No* raiz) {
    if (raiz == NULL) return NULL;

    raiz->esquerda = removerArvore(raiz->esquerda);
    raiz->direita  = removerArvore(raiz->direita);
    free(raiz);
    return NULL;
}

/* ──────────────────────────────────────────────
 * Travessias (auxiliares para visualização)
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

/* ──────────────────────────────────────────────
 * Main – demonstração de todas as operações
 * ────────────────────────────────────────────── */
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
    printf("Em ordem   : "); emOrdem(raiz);   printf("\n");
    printf("Pré-ordem  : "); preOrdem(raiz);  printf("\n");
    printf("Pós-ordem  : "); posOrdem(raiz);  printf("\n");

    /* Busca */
    printf("\n=== Busca ===\n");
    int alvo = 40;
    No* resultado = buscar(raiz, alvo);
    printf("Buscar %d: %s\n", alvo, resultado ? "encontrado" : "não encontrado");

    alvo = 99;
    resultado = buscar(raiz, alvo);
    printf("Buscar %d: %s\n", alvo, resultado ? "encontrado" : "não encontrado");

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

    /* Remoção completa da árvore */
    printf("\n=== Remoção da árvore inteira ===\n");
    raiz = removerArvore(raiz);
    printf("Árvore removida. raiz = %s\n", raiz == NULL ? "NULL" : "não nula");

    return 0;
}
