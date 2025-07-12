#ifndef TRABALHO2_H
#define TRABALHO2_H

#define TAM 10

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inicializar(No *estruturaPrincipal[]);
void inserirElemento(No *estruturaPrincipal[]);
void listarEstruturas(No *estruturaPrincipal[]);
void listarOrdenadoCada(No *estruturaPrincipal[]);
void listarTodosOrdenado(No *estruturaPrincipal[]);
void excluirElemento(No *estruturaPrincipal[]);

#endif 
