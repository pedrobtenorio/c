#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

#define tammax 300
  
struct fila
{ 
    int comeco, fim, tam; 
    int array[tammax]; 
}; 
  
typedef struct fila fila;

fila* criarfila() 
{ 
    fila* nova_fila = (fila*) malloc(sizeof(fila)); 
    nova_fila->comeco =  0;
    nova_fila->tam = 0; 
    nova_fila->fim = tammax - 1;    
    return nova_fila; 
} 
  
 
int isFull(fila* f) 
{  return (f->tam == tammax);  } 
  

int isEmpty(fila* f) 
{  return (f->tam == 0); } 
  

void enfileirar(fila* f, int item) 
{ 

    f->fim = (f->fim + 1)%tammax; 
    f->array[f->fim] = item; 
    f->tam = f->tam + 1; 
    
} 
  
int desenfireilar(fila* f) 
{ 
    
    int item = f->array[f->comeco]; 
    f->comeco = (f->comeco + 1)%tammax; 
    f->tam = f->tam - 1; 
    return item; 
} 
void troca(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

void bubble_sort(fila* v, int n)
{
    int i, j;
    for(i=n-1; i>=0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            if(v->array[j]<v->array[j+1])
            {
                troca(&v->array[j], &v->array[j+1]);
            }
        }
        
    }
}

 

  
int main() 
{ 
    int casos;
    scanf("%d", &casos);
    while (casos--)
    {
        fila* f = criarfila(); 
        fila* ordenada = criarfila();
        int n, i, item;
        scanf("%d", &n);
        for ( i = 0; i < n; i++)
        {
            scanf("%d", &item);
            enfileirar(f, item);
            enfileirar(ordenada, item);
        }
        bubble_sort(ordenada, n);
        int cont=0;
        for ( i = 0; i < n; i++)
        {
            if(f->array[i]==ordenada->array[i])
            {
                cont++;
            }
        }
        printf("%d", cont);
  
    }
    
    
  
    return 0; 
} 
