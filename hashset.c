#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node no;
typedef struct hashtable table;
struct node
{
    int chave, elemento;
    no *prox;
};

struct hashtable{
    int tam;
    no **tabela;
};


table* criartabela(int n)
{
   table *hashtable = NULL;
	int i;

	if( n < 1 ) return NULL;


	if( ( hashtable = malloc( sizeof( table ) ) ) == NULL ) {
		return NULL;
	}


	if( ( hashtable->tabela = malloc( sizeof( no * ) * n ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < n; i++ ) {
		hashtable->tabela[i] = NULL;
	}

	hashtable->tam = n;

	return hashtable;	
    
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