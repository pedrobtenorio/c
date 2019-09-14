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
  

struct lista_adj {
  int item;
  lista_adj *prox;
};


struct grafo
{
  lista_adj * vertices[300];
  int visitado[300];
};

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

lista_adj* criar_lista_adj(int item)
{
lista_adj *new_lista_adj = (lista_adj*) malloc(sizeof(lista_adj));
new_lista_adj->item = item;
new_lista_adj->prox = NULL;
return new_lista_adj;
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
        if (!graph->visitado[lista_adj->item]) 
        {
            printf("%d->", lista_adj->item);
            graph->visitado[lista_adj->item] = 1;
            enfileirar(queue, lista_adj->item);
        }
        printf("\n");
        lista_adj = lista_adj->prox;
    }
}

}



int main()
{
  grafo *undirected_graph = criar_grafo();
  int qvertices, qarestas, qcasos, o, d;
  scanf("%d%d%d", &qvertices, &qarestas, &qcasos);
  while(qarestas--) 
  {
      scanf("%d%d", &o, &d);
      add_ponta(undirected_graph, o, d);
  }
  while (qcasos--)
  {
     scanf("%d%d", &o, &d);
     printf("%d %d\n", o, d);
     bfs(undirected_graph, o);
  }
  
  
}
