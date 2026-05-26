# Binary Search Tree (BST) em C

Implementação modular de uma **Árvore Binária de Busca** em C, com operações de inserção, busca, remoção de nó e remoção completa da árvore.

---

## Estrutura do Projeto

```
.
├── arvore.h            # Definição da struct e protótipos
├── insercao.c          # criarNo() e inserir()
├── busca.c             # buscar()
├── remocao.c           # encontrarMinimo() e remover()
├── remocao_arvore.c    # removerArvore()
├── travessias.c        # emOrdem(), preOrdem(), posOrdem()
├── main.c              # Demonstração de todas as operações
├── Makefile            # Compilação do projeto
└── bst.c               # Versão completa em arquivo único
```

---

## Como compilar e executar

### Pré-requisitos
- GCC instalado
- Make instalado

### Compilar
```bash
make
```

### Executar
```bash
./bst
```

### Limpar arquivos compilados
```bash
make clean
```

---

## Operações

### Inserção — `insercao.c`
Insere um valor na árvore de forma recursiva. Duplicatas são ignoradas.

```c
No* raiz = NULL;
raiz = inserir(raiz, 50);
raiz = inserir(raiz, 30);
raiz = inserir(raiz, 70);
```

### Busca — `busca.c`
Busca um valor e retorna o nó encontrado, ou `NULL` caso não exista.

```c
No* resultado = buscar(raiz, 30); // retorna o nó com valor 30
No* nulo      = buscar(raiz, 99); // retorna NULL
```

### Remoção de nó — `remocao.c`
Remove um nó tratando os três casos possíveis:

| Caso | Comportamento |
|------|--------------|
| Nó folha | Remove diretamente |
| Um filho | Substitui pelo filho existente |
| Dois filhos | Substitui pelo sucessor in-order (mínimo da subárvore direita) |

```c
raiz = remover(raiz, 30);
```

### Remoção da árvore — `remocao_arvore.c`
Libera todos os nós em percurso pós-ordem e retorna `NULL`.

```c
raiz = removerArvore(raiz); // raiz == NULL ao final
```

---

## Travessias disponíveis

| Função | Ordem |
|--------|-------|
| `emOrdem(raiz)` | Esquerda → Raiz → Direita |
| `preOrdem(raiz)` | Raiz → Esquerda → Direita |
| `posOrdem(raiz)` | Esquerda → Direita → Raiz |

---

## Exemplo de saída

```
=== Inserção ===
Inserido: 50 | 30 | 70 | 20 | 40 | 60 | 80

=== Travessias ===
Em ordem   : 20 30 40 50 60 70 80
Pré-ordem  : 50 30 20 40 70 60 80
Pós-ordem  : 20 40 30 60 80 70 50

=== Busca ===
Buscar 40: encontrado
Buscar 99: não encontrado

=== Remoção: nó folha (20) ===
Em ordem: 30 40 50 60 70 80

=== Remoção: nó com dois filhos (50) ===
Em ordem: 40 60 70 80

=== Remoção da árvore inteira ===
Árvore removida. raiz = NULL
```

---

## Complexidade

| Operação | Médio | Pior caso (degenerada) |
|----------|-------|------------------------|
| Inserção | O(log n) | O(n) |
| Busca | O(log n) | O(n) |
| Remoção | O(log n) | O(n) |
| Remoção total | O(n) | O(n) |

---

## Versão completa (single-file)

O arquivo `bst.c` reúne todas as operações em um único arquivo, ideal para referência rápida ou uso sem `make`:

```bash
gcc -Wall -Wextra -o bst bst.c && ./bst
```

