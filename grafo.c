#include <stdio.h>
#include <stdlib.h>
typedef struct lista_adj lista_adj;
typedef struct grafo grafo;

#define tammax 200;

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

void add_ponta(grafo *grafo, int vertice1, int vertice2)
{
lista_adj *vertice = create_lista_adj(vertice2);
vertice->prox = grafo->vertices[vertice1];
grafo->vertices[vertice1] = vertice;
//Undirected grafo. Edge to the other direction as well.
vertice = create_lista_adj(vertice1);
vertice->prox = grafo->vertices[vertice2];
grafo->vertices[vertice2] = vertice;
}


lista_adj* criar_lista_adj(int item)
{
lista_adj *new_lista_adj = (lista_adj*) malloc(sizeof(lista_adj));
new_lista_adj->item = item;
new_lista_adj->prox = NULL;
return new_lista_adj;
}

int main()
{
  grafo *undirected_graph = create_graph();
  add_ponta(undirected_graph, 1, 2);
  add_ponta(undirected_graph, 1, 5);
  add_ponta(undirected_graph, 2, 5);
  add_ponta(undirected_graph, 2, 3);
  add_ponta(undirected_graph, 2, 4);
  add_ponta(undirected_graph, 3, 4);
  add_ponta(undirected_graph, 4, 5);
}
