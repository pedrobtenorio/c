#include <stdio.h>
#include <stdlib.h>

#define tam_max 255


struct pilha{
    int tam_atual;
    int items[tam_max];
};

typedef struct pilha pilha;

pilha* criarpilha()
{
    pilha* nova_pilha= malloc(sizeof(pilha));
    nova_pilha->tam_atual=0;
    return nova_pilha;
}

//add item a pilha
void push(pilha* p, int item)
{
    if(p->tam_atual==tam_max)
    {
        printf("stack overflow");
    }
    else
    {
        p->items[p->tam_atual++] = item;
    }
    
}

int checar_vazia(pilha *p)
{
    if(p->tam_atual==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

//remover item do topo
int pop(pilha *p)
{
    if(checar_vazia(p))
    {
        printf("stack underflow");

        return -1;
    }
    else
    {
        return p->items[--p->tam_atual];
    }

}

//olhar o topo 
int peek(pilha *p)
{
    if(checar_vazia(p))
    {
        printf("stack underflow");

        return -1;
    }
    else
    {
        return p->items[p->tam_atual-1];
    }
}

int main()
{
    pilha *p;
    p=criarpilha();

    push(p, 10); 
    push(p, 20); 
    push(p, 30); 
  
    while(!checar_vazia(p))
    {
        printf("%d popped from stack\n", pop(p)); 
    }

    return 0;
}