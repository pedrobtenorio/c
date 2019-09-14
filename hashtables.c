#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 500

typedef struct node no;
typedef struct hashtable table;
struct node
{
    int chave, elemento;
    no *prox;
};

struct hashtable{
    no *tabela[tam];
};


table* criartabela(int n)
{
    table* nova_tab=malloc(sizeof(table));
    int i;
    for ( i = 0; i < n; i++)
    {
        nova_tab->tabela[i]=NULL;
    }
    return nova_tab;
    
}

void inserir(int valor, int tamanho, table * tab)
{
    no* novo_no=malloc(sizeof(no));
    novo_no->elemento=valor;
    novo_no->prox=NULL;
    int chave=valor%tamanho;
    if(tab->tabela[chave]==NULL)
    {
        tab->tabela[chave]= novo_no;
    }
    else
    {
        no* aux = tab->tabela[chave];
        while (aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        
        aux->prox = novo_no;
    }
    
}

void printrar(int tamanho, table *tab)
{
    int i;
    for ( i = 0; i < tamanho; i++)
    {
        printf("%d -> ", i);
        no* aux;
        aux=tab->tabela[i];
        while (aux!=NULL)
        {
            printf("%d -> ",aux->elemento);
            aux = aux->prox;
        }
        printf("\\\n");

    }
    printf("\n");
    
}

int main()
{
    int casos, valores, aux, tamanhodahax, quantidade;
    table* tabela;
    scanf("%d", &casos);
    while (casos--)
    {
        scanf("%d%d", &tamanhodahax, &quantidade);
        tabela=criartabela(tamanhodahax);
        aux=quantidade;
        while (aux--)
        {
            scanf("%d", &valores);
            inserir(valores, tamanhodahax, tabela);
            
        }
        printrar(tamanhodahax, tabela);
        free(tabela);
        
    }
    
}