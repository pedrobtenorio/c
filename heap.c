#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
 
#define MAXSIZE 100000
 
typedef struct heap heap;
 
struct heap
{
    int size;
    int items[MAXSIZE];
};
 
heap * create_heap()
{
    heap *new= malloc(sizeof(heap));
    new->size=0;
   return new;
}


void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

int isempty(heap *rip)
{
    if(rip->size<=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}





int daddy(int i)
{
    return i/2;
}

int left_child(int i)
{
    return i * 2;
}

int right_child(int i)
{
    return (i*2)+1;
}

int heap_item(heap * rip, int i)
{
    return rip->items[i];
}

void min_heapfy(heap *rip, int i)
{
    int smallest;
    int leftindex = left_child(i);
    int rightindex = right_child(i);
    if (leftindex <= rip->size && rip->items[leftindex] < rip->items[i]) 
    {
        smallest = leftindex;
    } 
    else 
    {
        smallest = i;
    }
    if (rightindex <= rip->size && rip->items[rightindex] < rip->items[smallest]) 
    {
        smallest = rightindex;
    }
    if (rip->items[i] != rip->items[smallest]) 
    {
        swap(&rip->items[i], &rip->items[smallest]);
        min_heapfy(rip, smallest);
    }
}

void build_min_heap(heap* rip)
{  
    int i;
    for ( i = rip->size/2; i >= 1; i--)
    {
        min_heapfy(rip, i);
    }
   
}
 
 void print_heap(int n, heap * rip)
{
    int i;
    int num;
    printf("Heap current state: ");
    
    if(!isempty(rip))
    {
        for ( i = 1; i <= n-1; i++)
        {
            
            num=rip->items[i];
            printf("%d | ", num);
        }
        
        num=rip->items[i];
        printf("%d", num);
        printf("\n");
        printf("Smallest element: %d\n", rip->items[1]);
    }
        
    else
    {
        printf("empty\n");
        return;
    }
    
}

void enqueue(heap *rip, int item)
{
    if(rip->size>=MAXSIZE)
    {
        printf("overflow\n");
    }
    else
    {
        rip->items[++rip->size]=item;
        int index=rip->size;
        int daddy_index=daddy(rip->size);
        build_min_heap(rip);
        

    }
    
}

int dequeue(heap * rip)
{
    if(isempty(rip))
    {
        printf("underflow\n");
        return -1000;
    }
    else
    {
        int item=rip->items[1];
        rip->items[1]=rip->items[rip->size];
        rip->size--;

        min_heapfy(rip, 1);

        return item;

    }
    
}
 
int main()
{
    printf("Insert heap size\n");
    int tam, d;
    scanf("%d", &tam);
    int* array;
    array=malloc(sizeof(int)*tam+1);
    int n=1, i;
    heap *rip=create_heap();
    for ( i = 1; i <= tam; i++)
    {
        scanf("%d", &d);
        array[i]=d;
    }
    

    printf("Initial state:");
    for ( i = 1; i <tam; i++)
    {
        printf(" %d |", array[i]);
        enqueue(rip, array[i]);
    }
    printf(" %d", array[i]);
     printf("\n");
    enqueue(rip, array[i]);
    print_heap(rip->size, rip);
    n=dequeue(rip);
    printf("dequeued :%d\n", n);
    print_heap(rip->size, rip);
    n=dequeue(rip);
     printf("dequeued :%d\n", n);
    print_heap(rip->size, rip);

   
}

