#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
 
#define tammax 300
 
typedef struct heap heap;
 
struct heap
{
    int tam;
    int items[tammax];
};
 
heap * criar()
{
    heap *nova= malloc(sizeof(heap));
    nova->tam=0;
   return nova;
}


void troca(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

int checar_vazia(heap *p)
{
    if(p->tam<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}





int pegar_pai(int i)
{
    return i/2;
}

int esquerda(int i)
{
    return i * 2;
}

int direita(int i)
{
    return (i*2)+1;
}

int itemdaheap(heap * rip, int i)
{
    return rip->items[i];
}

void max_heapify(heap *rip, int i)
{
    int maior;
    int indiceesquerda = esquerda(i);
    int indicedireita = direita(i);
    if (indiceesquerda <= rip->tam && rip->items[indiceesquerda] > rip->items[i]) 
    {
        maior = indiceesquerda;
    } 
    else 
    {
        maior = i;
    }
    if (indicedireita <= rip->tam && rip->items[indicedireita] > rip->items[maior]) 
    {
        maior = indicedireita;
    }
    if (rip->items[i] != rip->items[maior]) 
    {
        troca(&rip->items[i], &rip->items[maior]);
        max_heapify(rip, maior);
    }
}

void construirheap(heap* rip)
{  
    int i;
    for ( i = rip->tam/2; i >= 1; i--)
    {
        max_heapify(rip, i);
    }
   
}
 
 void pritarheap(int n, heap * rip)
{
    int i;
    int num, flag=0;
    printf("Estado Atual da Heap: ");
    for ( i = 1; i <= n-1; i++)
    {
        flag=1;
        num=rip->items[i];
        printf("%d | ", num);
    }
    
    num=rip->items[i];
    printf("%d", num);
    printf("\n");
    if(flag)
        printf("Maior elemento neste passo: %d\n", rip->items[1]);
    else
    {
        return;
    }
    
}

void heapsort(heap * rip)
{
    int i;
    construirheap(rip);
    for ( i = rip->tam; i > 1; i--)
    {
       
        pritarheap(rip->tam, rip);
        troca(&rip->items[1], &rip->items[i]);
        rip->tam--;
        max_heapify(rip, 1);
        
       
    }
   
}




void enfileirar(heap *rip, int item)
{
    if(rip->tam>=tammax)
    {
        printf("overflow\n");
    }
    else
    {
        rip->items[++rip->tam]=item;
        int indice=rip->tam;
        int indicedopai=pegar_pai(rip->tam);
        while (indicedopai >=1 && rip->items[indice]>rip->items[indicedopai])
        {
            troca(&rip->items[indice], &rip->items[indicedopai]);
            indice=indicedopai;
            indicedopai=pegar_pai(indice);
        }
        

    }
    
}

int desenfileirar(heap * rip)
{
    if(checar_vazia(rip))
    {
        printf("underflow\n");
        return -1000;
    }
    else
    {
        int item=rip->items[1];
        rip->items[1]=rip->items[rip->tam];
        rip->tam--;

        max_heapify(rip, 1);

        return item;

    }
    
}
 
int main()
{
    printf("digite o tamanho da lista\n");
    int tam, d;
    scanf("%d", &tam);
    int* array;
    array=malloc(sizeof(int)*tam+1);
    int n=1, i;
    heap *rip=criar();
    for ( i = 1; i <= tam; i++)
    {
        scanf("%d", &d);
        array[i]=d;
    }
    

    printf("Estado inicial:");
    for ( i = 1; i <tam+1; i++)
    {
        printf(" %d |", array[i]);
        enfileirar(rip, array[i]);
    }
    printf(" %d", array[i]);
    enfileirar(rip, array[i]);
    

    printf("\n");

    heapsort(rip);
    printf("Resultado Final:");
    for ( i = 1; i < tam+1; i++)
    {
       printf(" %d |", rip->items[i]);
    }
    printf(" %d", rip->items[i]);
    printf("\n");

   
}

