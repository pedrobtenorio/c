#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 11

typedef struct node no;

struct node
{
    int chave, elemento;
    no *prox;
};

no *tabela[tam];

void criartabela()
{
    int n=tam,  i;
    for ( i = 0; i < n; i++)
    {
        tabela[i]=NULL;
    }
    
}

void inserir(int valor)
{
    
}