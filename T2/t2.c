#include <stdio.h>
#include <stdlib.h>
#include "trabalho2.h"

void inicializar(No *estruturaPrincipal[]) {
    for (int i = 0; i < TAM; i++) {
        estruturaPrincipal[i] = NULL;
    }
}

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inserirElemento(No *estruturaPrincipal[]) {
    int pos, valor;
    printf("Informe a posição (0 a 9): ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= TAM) {
        printf("Posição inválida!\n");
        return;
    }

    printf("Informe o valor a inserir: ");
    scanf("%d", &valor);

    No* novo = criarNo(valor);

    if (estruturaPrincipal[pos] == NULL) {
        estruturaPrincipal[pos] = novo;
    } else {
        No* atual = estruturaPrincipal[pos];
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo;
    }

    printf("Valor inserido na posição %d.\n", pos);
}

void listarEstruturas(No *estruturaPrincipal[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Posição %d: ", i);
        No* atual = estruturaPrincipal[i];
        if (atual == NULL) {
            printf("(vazia)");
        }
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
}

int contarElementos(No *inicio) {
    int count = 0;
    while (inicio != NULL) {
        count++;
        inicio = inicio->prox;
    }
    return count;
}

void copiarParaVetor(No *inicio, int vetor[]) {
    int i = 0;
    while (inicio != NULL) {
        vetor[i++] = inicio->valor;
        inicio = inicio->prox;
    }
}

int comparar(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void listarOrdenadoCada(No *estruturaPrincipal[]) {
    for (int i = 0; i < TAM; i++) {
        No* lista = estruturaPrincipal[i];
        if (lista == NULL) continue;

        int tam = contarElementos(lista);
        int *vetor = (int*) malloc(sizeof(int) * tam);
        copiarParaVetor(lista, vetor);
        qsort(vetor, tam, sizeof(int), comparar);

        printf("Posição %d ordenada: ", i);
        for (int j = 0; j < tam; j++) {
            printf("%d ", vetor[j]);
        }
        printf("\n");
        free(vetor);
    }
}

void listarTodosOrdenado(No *estruturaPrincipal[]) {
    int total = 0;
    for (int i = 0; i < TAM; i++) {
        total += contarElementos(estruturaPrincipal[i]);
    }

    if (total == 0) {
        printf("Nenhum elemento inserido.\n");
        return;
    }

    int *vetor = (int*) malloc(sizeof(int) * total);
    int k = 0;
    for (int i = 0; i < TAM; i++) {
        No* atual = estruturaPrincipal[i];
        while (atual != NULL) {
            vetor[k++] = atual->valor;
            atual = atual->prox;
        }
    }

    qsort(vetor, total, sizeof(int), comparar);
    printf("Todos os números ordenados: ");
    for (int i = 0; i < total; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
}

void excluirElemento(No *estruturaPrincipal[]) {
    int pos, num;
    printf("Informe a posição (0 a 9): ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= TAM || estruturaPrincipal[pos] == NULL) {
        printf("Posição inválida ou vazia.\n");
        return;
    }

    printf("Informe o número a excluir: ");
    scanf("%d", &num);

    No *atual = estruturaPrincipal[pos];
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == num) {
            if (anterior == NULL) {
                estruturaPrincipal[pos] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Elemento %d removido da posição %d.\n", num, pos);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Elemento não encontrado na posição %d.\n", pos);
}
int main() {
    No* estruturaPrincipal[TAM];
    int opcao;

    inicializar(estruturaPrincipal);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir elemento\n");
        printf("2. Listar estruturas\n");
        printf("3. Listar ordenado (por estrutura)\n");
        printf("4. Listar todos ordenados\n");
        printf("5. Excluir elemento\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: inserirElemento(estruturaPrincipal); break;
            case 2: listarEstruturas(estruturaPrincipal); break;
            case 3: listarOrdenadoCada(estruturaPrincipal); break;
            case 4: listarTodosOrdenado(estruturaPrincipal); break;
            case 5: excluirElemento(estruturaPrincipal); break;
            case 6: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 6);

    return 0;
}
