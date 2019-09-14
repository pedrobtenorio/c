#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no lista;

struct no
{
    char item;
    int frequencia;
    lista *prox;
};
void imprimir(lista *p)
{

    if(p)
    {
        //printf("Mostrando a lista:\n"); 
        lista *aux = p;
	    while (aux != NULL) 
        {
		    printf("%c %d\n", aux->item, aux->frequencia);
		    aux = aux->prox;
	    }
    }
    else
printf("Lista vazia.");
printf("\n");
}

lista * criar (int x, lista *p, char z)
{
    
    p->item = z;
    p->frequencia=x;
    p->prox = NULL;
    return p;
}

lista *inserir_comeco(lista *cabeca, int num, char letra)
{
    lista *novoNo = malloc(sizeof(lista));
    novoNo=criar(num, novoNo, letra);
    novoNo->prox=cabeca;
    return novoNo;
}

void troca(char *a, char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

void bubble_sort(char *v, int n)
{
    int i, j;
    for(i=n-1; i>=0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            if(v[j]>v[j+1])
            {
                troca(&v[j], &v[j+1]);
            }
        }
        
    }
}


int main()
{
    char *frase;
    lista *q=NULL;
    frase=malloc(sizeof(char)*100);
    int i, cont;
    scanf("%[^\n]", frase);
    int n=strlen(frase);
    getchar();
    bubble_sort(frase, n);
    i=0;
    int j;
    while (i<n)
    {
        cont=1;
        for ( j = i+1; j<=n; j++)
        {
            if(frase[i]==frase[j])
            {
                cont++;
                
            }
            else
            {
                q=inserir_comeco(q, cont, frase[i]);
                i=j;
                break;
                
            }
            
        }
        
    }
    
    imprimir(q);

}