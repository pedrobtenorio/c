#include <stdio.h>
#include <stdlib.h>

#define tam_max 300

typedef struct no lista;

typedef struct pilha pilha;

struct no
{
    int item;
    lista *prox;
};

lista * criar (int x, lista *p)
{
    
    p->item = x;
    p->prox = NULL;
    return p;

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

void imprimir(lista *p)
{

    if(p)
    {
        lista *aux = p;
	    while (aux != NULL) 
        {
            if(aux->prox==NULL)
            {
                printf("%d", aux->item);
                aux = aux->prox;
            }
            else{
                
		        printf("%d ", aux->item);
		        aux = aux->prox;
            }
	    }
        
    }
    else
printf("Lista vazia.");
printf("\n");
}


struct pilha{
    int tam_atual;
    lista * items[tam_max];
};


pilha* criarpilha()
{
    pilha* nova_pilha= malloc(sizeof(pilha));
    nova_pilha->tam_atual=0;
    return nova_pilha;
}

//add item a pilha
void push(pilha* p, lista* l)
{
    if(p->tam_atual==tam_max)
    {
        printf("stack overflow");
    }
    else
    {
        p->items[p->tam_atual] = l;
        p->tam_atual++;
       
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
void pop(pilha *p)
{
    if(checar_vazia(p))
    {
        printf("EMPTY STACK\n");
 
    }
    else
    {
        imprimir(p->items[--p->tam_atual]);
       
    }

}


int main()
{
    pilha *p;
    p=criarpilha();
    char comando[5];
    while (scanf("%s", comando)!=EOF)
    {
        getchar();

        int * array;
        array=malloc(sizeof(int)* tam_max);
        int array_current_size;
        lista *l=NULL;
        char symb;
        if(comando[1]=='U')
        {
            array_current_size = 0;
            do {
                scanf("%d%c", &array[array_current_size++], &symb);
                l=inserirFinal(l,array[--array_current_size]);
            } while (symb != '\n');
            push(p, l);
        }
        else if(comando[1]=='O')
        {
            pop(p);
        }
    }
    

    

    return 0;
}