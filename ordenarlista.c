#include <stdio.h>
#include <string.h>
#include <math.h>
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
lista *inserir_comeco(lista *cabeca, int num)
{
    lista *novoNo = malloc(sizeof(lista));
    novoNo=criar(num, novoNo);
    novoNo->prox=cabeca;
    return novoNo;
}
void ordenar(lista *p)
{
	int troca, i;
	lista *ptr1;
    lista *lptr = NULL;
	if (p == NULL)
	{
		return;
	}
	do
	{
		troca = 0;
		ptr1 = p;
		while(ptr1->prox != lptr)
		{
           
			if (ptr1->item > ptr1->prox->item)
			{
                
				trocar(ptr1 , ptr1->prox);
				troca =1;
			}
			ptr1 = ptr1->prox;
		}
		lptr = ptr1;
	} while (troca);
}

void trocar(lista *a, lista *b)
{
	int temp = a->item;
    a->item = b->item; 
    b->item = temp;
}

int main() {
    lista *p =  NULL;
    int num;
    while(scanf("%d", &num)!=EOF)
    {
        p=inserir_comeco(p, num);
    }
    ordenar(p);
    imprimir(p);
    
	return 0;
}