#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no lista;

struct no
{
    char item;
    int indice;
    lista *prox;
};

void deletarlista(lista** q) 
{ 
   lista* current = *q; 
   lista* next; 
  
   while (current != NULL)  
   { 
       next = current->prox; 
       free(current); 
       current = next; 
   } 
    
   *q = NULL; 
} 

lista * criar (char x, lista *p, int i)
{
  
    p->item = x;
    p->prox = NULL;
    p->indice=i;
    return p;
}

lista *inserirFinal(lista *cabeca, char num, int indice)
{
    lista *novoNo = malloc(sizeof(lista));
    novoNo=criar(num, novoNo, indice);
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

void imprimir(lista *p)
{

    if(p)
    {
        printf("Mostrando a lista:\n"); 
        lista *aux = p;
	    while (aux != NULL) 
        {
		    printf("num:%d indice:%d \n", aux->item, aux->indice);
		    aux = aux->prox;
	    }
    }
    else
printf("Lista vazia.");
printf("\n");
}



void procurarsequencia(lista *p, int *comeco, int *fim)
{
       
        int auxcomeco, auxfim, n=0;
        int flag=0, tam=0, local=0;
	    while (p != NULL) 
        {
		    if(flag==0 && p->item=='0')
            {
                auxcomeco=p->indice;
                p = p->prox;
                flag=1;

            }
            else if((p->item=='1' || p->prox==NULL)&& flag==1)
            {
                auxfim=p->indice;
                n=auxfim-auxcomeco;
                if(n>tam)
                {
                    *comeco=auxcomeco;
                    *fim=auxfim;
                    tam=n;
                    
                }
                p = p->prox;
                flag=0;

            }
            else
            {
                p = p->prox;

            }
            
            
	    }
}
long long int tam(long long int i) 
{
 int casa=1;
 while (i/=10) casa++;
 return casa;
}

int main()
{
    lista *p=NULL;
    long long int  n, i, aux;
    char num[100];
    scanf("%[^\n]s", num);
    while (strcmp(num, "0")!=0)
    {
        getchar();
        n=strlen(num);
        int comeco=0, fim=0;
        for ( i = 0; i < n; i++)
        {
                
            p=inserirFinal(p, num[i], i);
                
        }
        procurarsequencia(p, &comeco, &fim);
        printf("%d %d\n", comeco, fim-1);
        scanf("%[^\n]s", num);
        deletarlista(&p);

    }
}