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
lista* trocar(lista *a, lista *b)
{
    lista* temp;
	temp=b->prox;
    b->prox=a;
    a->prox=temp;
    return b;
    
}
int ordenar(lista **p, int cont)
{
	lista** ord; 
    int i, j, trocado; 
  
    for (i = 0; i <= cont; i++) { 
  
        ord = p; 
        trocado = 0; 
  
        for (j = 0; j < cont - i - 1; j++) { 
  
            lista* p1 = *ord; 
            lista* p2 = p1->prox; 
  
            if (p1->item > p2->item) { 
  
                *ord = trocar(p1, p2); 
                trocado = 1; 
            } 
  
            ord = &(*ord)->prox; 
            
        } 
  
       
        if (trocado == 0) 

            break; 
    } 
	
}



int main() {
    lista *p =  NULL;
    int num, cont=0;
    while(scanf("%d", &num)!=EOF)
    {
        cont++;
        p=inserir_comeco(p, num);
    }
    ordenar(&p, cont);
    imprimir(p);
    
	return 0;
}