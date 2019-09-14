#include <stdio.h>
#include <stdlib.h>

typedef struct no lista;

struct no
{
    int item;
    lista *prox;
};

lista* criar(void)
{
    return NULL;
}

void insere (int x, lista *p)
{
   lista *nova;
   nova = malloc (sizeof (lista));
   nova->item = x;
   nova->prox = p->prox;
   p->prox = nova;
}

/* void remove (lista *p)
{
   lista *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}*/

void imprimir(lista *p)
{

    printf("Mostrando a lista:\n"); 
    if(p)
    {
        do
        {
            printf("%d\n", p->item);
            p=p->prox;
        }
        while(p);
    }
    else
printf("Lista vazia.");
}
int main()
{
    lista *p = (lista*) malloc(sizeof(lista*));
    lista *pNode1 = NULL;
    lista *pNode2 = NULL;
    lista *pNode3 = NULL;
    pNode1 = (lista*) malloc(sizeof(lista*));
    pNode1->item = 10;
     
    pNode2 = (lista*) malloc(sizeof(lista*));
    pNode2->item = 20;
     
    pNode3 = (lista*) malloc(sizeof(lista*));
    pNode3->item = 30;
     

    pNode1->prox = pNode2;
    pNode2->prox = pNode3;  
    pNode3->prox = NULL;
    if(pNode1)  
    imprimir(pNode1);

}

