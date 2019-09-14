#include <stdio.h>
#include <stdlib.h>

typedef struct no lista;

struct no
{
    int item;
    lista *prox;
};

lista * criar (int x, lista *p)
{
    p = malloc (sizeof (lista));
    p->item = x;
    p->prox = NULL;
    return p;
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
            if(aux->item==num)
            {
                return cabeca;
            }
            aux = aux->prox;
        }
        aux->prox = novoNo;
    }
    return cabeca;
}

lista *inserir_comeco(lista *cabeca, int num)
{
    lista *novoNo = malloc(sizeof(lista));
    novoNo=criar(num, novoNo);
    novoNo->prox=cabeca;
    return novoNo;
}
void imprimir(lista *p)
{

    if(p)
    {
        printf("Mostrando a lista:\n"); 
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

lista *inter(lista *a, lista *b)
{   
    lista *intersec=NULL;

    while (a!=NULL && b!=NULL)
    {
        if(a->item<b->item)
        {
            a=a->prox;
        }
        else if(a->item==b->item)
        {
            intersec=inserirFinal(intersec, a->item);
            a=a->prox;
            b=b->prox;
        }
        else
        {
            b=b->prox;
        }
        
    }

    return intersec;
    

}

void trocar(lista *a, lista *b)
{
	int temp = a->item;
    a->item = b->item; 
    b->item = temp;
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



int main()
{
    lista *a=NULL;
    lista *b=NULL;
    lista *c=NULL;
    int i, num;
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &num);
        a=inserirFinal(a, num);
    }
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &num);
        b=inserirFinal(b, num);
    }
    ordenar(a);
    ordenar(b);
    c= inter(a, b);
    ordenar(c);
    imprimir(c);

}