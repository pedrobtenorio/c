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
        //printf("stack underflow");

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
        //printf("stack underflow");

        return -1;
    }
    else
    {
        return p->items[p->tam_atual-1];
    }
}

int main()
{
    pilha *back, *forward;
    forward=criarpilha();
    back=criarpilha();
    char comando[10];
    int entercont=0;
    while (scanf("%s", comando)!=EOF)
    {
        getchar();
        if(comando[0]=='E' && entercont>0)
        {
            push(back, 1);
            entercont++;
            while (checar_vazia(forward)!=1)
            {
                pop(forward);
            }
            
        }
        else if(comando[0]=='B')
        {
            pop(back);
            push(forward, 1);
        }
        else if(comando[0]=='F')
        {
            pop(forward);
            push(back, 1);
        }
        
        
        
    }
    
    printf("BACK: %d\nFORWARD: %d\n", back->tam_atual, forward->tam_atual);

    return 0;
}