#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_max 255


struct pilha{
    int tam_atual;
    char items[tam_max];
};

typedef struct pilha pilha;

pilha* criarpilha()
{
    pilha* nova_pilha= malloc(sizeof(pilha));
    nova_pilha->tam_atual=0;
    return nova_pilha;
}

//add item a pilha
void push(pilha* p, char item)
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
    pilha *a, *b;
    a=criarpilha();
    b=criarpilha();
    char s[tam_max];
    int n, aux, i, check;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        scanf("%[^\n]s", s);
        getchar();
        aux=strlen(s);
        if(aux==1 && s[0]!=')' && s[0]!='(' && s[0]!=']' && s[0]!='[')
        {
            goto vazio;
        }
        for ( i = 0; i < aux; i++)
        {
            if(s[i]=='(')
            {
                push(a, s[i]);
            }
            else if(s[i]==')')
            {
                check=pop(a);
                if(check==-1)
                {
                    goto nbalanceado;
                }
               
            }
            else if(s[i]=='[')
            {
                push(b, s[i]);
            }
            else if(s[i]==']')
            {
                check=pop(b);
                if(check==-1)
                {
                    goto nbalanceado;
                }
               
            }
            
        }
        if(checar_vazia(a) && checar_vazia(b))
        {
            vazio:
            printf("Yes\n");
        }
        else
        {
            nbalanceado:
            printf("No\n");
        }
        
        while(!checar_vazia(a))
        {
            pop(a);
        }
        while(!checar_vazia(b))
        {
            pop(b);
        }
        
    }

    return 0;
}