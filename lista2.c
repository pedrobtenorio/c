#include <stdio.h>
#include <stdlib.h>

typedef struct no lista;

struct no
{
    int item;
    lista *prox;
};


 lista* remover (lista *p, int i)
{
   lista *atras= NULL;
   lista *atual= p;
   while ( atual!=NULL && atual->item !=i )
   {
       atras=atual;
       atual=atual->prox;
   }
   if(atual==NULL)
   {
       return p;
   }
   if(atras==NULL)
   {
       p=atual->prox;
   }
   else
   {
       atras->prox=atual->prox;
   }
   free(atual);
   return p;
   
    
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

lista * criar (int x, lista *p)
{
    
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



int procurar(lista *p, int num)
{
    if(p)
    {
        
        lista *aux = p;
	    while (aux != NULL) 
        {
		    if(aux->item==num)
            {
            return num;
            }
            aux = aux->prox;
	    }
    }
    else
        return 0;

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

lista* inserir_ordenado(lista *p, int num)
{
    

    if(p==NULL)
    {
        p=criar(num, p);
        return p;
    }

    else if(p->prox==NULL)
    {
        if(p->item>num)
        {
            lista *novono=inserir_comeco(p, num);
            return novono;
        }
        else
        {
            lista *novono=inserirFinal(p, num);
            return novono;
        }

    }
    lista *atras;
    lista *frente;
    
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
        p=inserirFinal(p, num);
        
    }
    imprimir(p);
    printf("insira o numero que você quer colocar no começo\n");
    scanf("%d", &num);
    p=inserir_comeco(p, num);
    imprimir(p);
    printf("lista ordenada\n");
    ordenar(p);
    imprimir(p);
    printf("escolha o item que voce quer remover\n");
    scanf("%d", &num);
    remover(p, num);
    imprimir(p);
    
}

