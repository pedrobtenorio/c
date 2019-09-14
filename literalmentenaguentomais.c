#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct lista_adj lista_adj;
typedef struct grafo grafo;
typedef struct fila fila;

#define tammax 300
  
struct fila
{ 
    int comeco, fim, tam; 
    int array[tammax]; 
};

fila* criarfila();
void enfileirar(fila* f, int item);
int desenfireilar(fila* f);
int comeco(fila* f);
int fim(fila* f);
int isFull(fila* f);
int isEmpty(fila* f);
  

struct lista_adj {
  int item;
  lista_adj *prox;
};


void trocar(lista_adj *a, lista_adj *b);
void ordenar(lista_adj * p);
lista_adj* criar_lista_adj(int item);



struct grafo
{
  lista_adj * vertices[300];
  int visitado[300];
};

grafo* criar_grafo();
void add_ponta(grafo *grafo, int vertice1, int vertice2);
void bfs(grafo *graph, int source);


int main()
{

    int vertices, arestas, casos, origem, destino, aux;
    scanf("%d%d%d", &vertices, &arestas, &casos);
    grafo *graph= criar_grafo();
    aux=arestas;
    while (arestas--)
    {
        scanf("%d%d", &origem, &destino);
        add_ponta(graph, origem, destino);
    }
    int i;
    for ( i = 0; i < aux; i++)
    {
        if(graph->vertices[i]!=NULL)
        {
            ordenar(graph->vertices[i]);
        }
    }
    
    while (casos--)
  {
     scanf("%d%d", &origem, &destino);
     printf("%d %d na bsfs\n", origem, destino);
     bfs(graph, origem);
  }
    

}

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
    if (isFull(f)) 
        return; 
    f->fim = (f->fim + 1)%tammax; 
    f->array[f->fim] = item; 
    f->tam = f->tam + 1; 
    //printf("%d enfileirarado to f\n", item); 
} 
  
int desenfireilar(fila* f) 
{ 
    if (isEmpty(f)) 
        return INT_MIN; 
    int item = f->array[f->comeco]; 
    f->comeco = (f->comeco + 1)%tammax; 
    f->tam = f->tam - 1; 
    return item; 
} 
  
 
int comeco(fila* f) 
{ 
    if (isEmpty(f)) 
        return INT_MIN; 
    return f->array[f->comeco]; 
} 
  

int fim(fila* f) 
{ 
    if (isEmpty(f)) 
        return INT_MIN; 
    return f->array[f->fim]; 
} 

void trocar(lista_adj *a, lista_adj *b)
{
    lista_adj* temp;
	temp=b->prox;
    b->prox=a;
    a->prox=temp;
   
    
}
void ordenar(lista_adj * p)
{
    lista_adj* aux1;
    lista_adj* aux2;
    aux1=p;
    aux2=p->prox;
	while (aux1!=NULL)
    {
       while (aux2!=NULL)
       {
           if(aux1->item>aux2->item)
           {
               trocar(aux1, aux2);
           }
           aux2=aux2->prox;
       }
        aux1=aux1->prox;
        if(aux1!=NULL)
        {
            aux2=aux1->prox;
        }
    }
    
}

lista_adj* criar_lista_adj(int item)
{
lista_adj *new_lista_adj = (lista_adj*) malloc(sizeof(lista_adj));
new_lista_adj->item = item;
new_lista_adj->prox = NULL;
return new_lista_adj;
}

void bfs(grafo *graph, int source)
{
fila *queue = criarfila();
int dequeued;
lista_adj * lista_adj = graph->vertices[source];
graph->visitado[source] = 1;
enfileirar(queue, source);
while (!isEmpty(queue)) 
{
    dequeued = desenfireilar(queue);
    lista_adj = graph->vertices[dequeued];

    while (lista_adj != NULL) 
    {
        int adj=lista_adj->item;
        if (!graph->visitado[adj]) 
        {
            printf("%d->", adj);
            graph->visitado[adj] = 1;
            enfileirar(queue, adj);
        }
        printf("\n");
        lista_adj = lista_adj->prox;
    }
}

}

void add_ponta(grafo *grafo, int vertice1, int vertice2)
{
lista_adj *vertice = criar_lista_adj(vertice2);

vertice->prox = grafo->vertices[vertice1];
grafo->vertices[vertice1] = vertice;
/* Undirected grafo. Edge to the other direction as well.
vertice = criar_lista_adj(vertice1);
vertice->prox = grafo->vertices[vertice2];
grafo->vertices[vertice2] = vertice;
}*/
}

grafo* criar_grafo()
{
  grafo * novo_grafo= malloc(sizeof(grafo));
  int i;
  for (i=1; i<=300-1; i++)
  {
    novo_grafo->vertices[i]=NULL;
    novo_grafo->visitado[i]=0;
  }
  return novo_grafo;
}