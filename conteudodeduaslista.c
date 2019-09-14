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
   
   p = (lista *) malloc (sizeof (lista));
   p->item = x;
   p->prox = NULL;
   return p;
}

lista *inserirFinal(lista *cabeca, int num)
    {
        lista *novoNo = (lista *) malloc(sizeof(lista));
        novoNo=criar(num, novoNo);
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
int comparar(lista *a,lista  *b)
{
    lista *aux=a;
    int contador=0;
    while (b!=NULL)
    {
        aux=a;
        while (aux!= NULL)
        {
            if(aux->item==b->item)
            {
                contador+=1;
                aux=aux->prox;
                break;
            }
            else
            {
                 aux=aux->prox;
            }
            
        }
        b=b->prox;
    }
    
    return contador;
    
}


int main()
{
    lista *a = NULL; 
    lista *b = NULL;
    int n, i, num;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a=inserirFinal(a, num);    
    }
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &num);
        b=inserirFinal(b, num);   
    }
    int res;
    res=comparar(a , b);
    if(res==n)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;

}