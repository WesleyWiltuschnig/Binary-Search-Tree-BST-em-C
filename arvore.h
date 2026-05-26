#ifndef ARVORE_H
#define ARVORE_H

/* ──────────────────────────────────────────────
 * Definição da estrutura do nó
 * ────────────────────────────────────────────── */
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

/* Criação de nó */
No* criarNo(int valor);

/* Inserção */
No* inserir(No* raiz, int valor);

/* Busca */
No* buscar(No* raiz, int valor);

/* Remoção de nó */
No* remover(No* raiz, int valor);
No* encontrarMinimo(No* raiz);

/* Remoção da árvore inteira */
No* removerArvore(No* raiz);

/* Travessias */
void emOrdem(No* raiz);
void preOrdem(No* raiz);
void posOrdem(No* raiz);

#endif /* ARVORE_H */
