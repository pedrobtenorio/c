
#include <stdio.h>
#include <stdlib.h>

typedef struct no lista;

struct no
{
    int item;
    lista *prox;
};

void imprimir(lista *p)
{

    if(p)
    {
         
        lista *aux = p;
	    while (aux != NULL) 
        {
		    printf("%d ", aux->item);
		    aux = aux->prox;
	    }
    }
    else
printf("Lista vazia.");
printf("\n");
}
lista * criar (int x, lista *p)
{
    p = malloc (sizeof (lista));
    p->item = x;
    p->prox = NULL;
    return p;
}
void inverter(lista** q) 
{ 
    lista* anterio=NULL; 
    lista* atual=*q; 
    lista* proximo= NULL; 
    while (atual != NULL) 
    { 
        proximo= atual->prox;
        atual->prox= anterio;    
        anterio= atual; 
        atual= proximo;
    } 
    *q = anterio; 
} 

lista *inserirFinal(lista *cabeca, int num)
{
    lista *novoNo = malloc(sizeof(lista));
    novoNo=criar(num, novoNo);
    //lista vazia
    if (cabeca == NULL)
    {
        return novoNo;
    } 
    else 
    {
        lista *aux = cabeca;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novoNo;
    }
    return cabeca;
}

int main() {
    lista *p =  NULL;
    int num;
    while(scanf("%d", &num)!=EOF)
    {
        p=inserirFinal(p, num);
    }
    inverter(&p);
    imprimir(p);
    
	return 0;
}