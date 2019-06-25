#include <stdio.h>
#include <stdlib.h>

typedef struct no lista;

struct no
{
    int item;
    lista *prox;
};


 void remover (lista *p)
{
   lista *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
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
lista * insere (int x, lista *p)
{
   
   p = malloc (sizeof (lista));
   p->item = x;
   p->prox = NULL;
}

lista *inserirFinal(lista *cabeca, int num){
    lista *novoNo = malloc(sizeof(lista));
    novoNo=insere(num, novoNo);
    if (cabeca == NULL){
        return novoNo;
    } else {
        lista *aux = cabeca;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novoNo;
    }

    return cabeca;
}
lista *inserir_comeco(lista *cabeca, int num)
{
    lista *novoNo = malloc(sizeof(lista));
    novoNo=insere(num, novoNo);
    novoNo->prox=cabeca;
    return novoNo;

}

int main()
{
    lista *p =  NULL;
    int n, num, i;
    printf("insira o tamanho da lista\n");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("insira o numero\n");
        scanf("%d", &num);
        p=inserir_comeco(p, num);
        
    }
    imprimir(p);
    remover(p);
    int a;
    scanf("%d", &a);
    imprimir(p);
   

}

