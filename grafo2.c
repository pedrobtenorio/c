#include <stdio.h> 
#include <stdlib.h> 
  

typedef struct nodalista no;
typedef struct listaadj lista;
typedef struct grafo grafo;

struct nodalista 
{ 
    int dest; 
    struct nodalista* next; 
}; 
  

struct listaadj
{ 
    struct nodalista *head;  
}; 
  

struct grafo 
{ 
    int V; 
    struct listaadj* array; 
}; 
  
no* novo_no(int dest) 
{ 
    no* newNode = 
     (no*) malloc(sizeof(no)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
  
grafo* criar_grafo(int V) 
{ 
    grafo* grafo =  malloc(sizeof(grafo)); 
    grafo->V = V; 
  
    // Create an array of adjacency lists.  Size of  
    // array will be V 
    grafo->array =  (lista*) malloc(V * sizeof(lista)); 
  
    // Initialize each adjacency list as empty by  
    // making head as NULL 
    int i; 
    for (i = 0; i < V; ++i) 
        grafo->array[i].head = NULL; 
  
    return grafo; 
} 
  

void addEdge(grafo* grafo, int inicio, int destino) 
{ 
    
    no* newNode = novo_no(destino); 
    newNode->next = grafo->array[inicio].head; 
    grafo->array[inicio].head = newNode; 
  
    
} 
  

void printgrafo(grafo* grafo) 
{ 
    int v; 
    for (v = 0; v < grafo->V; ++v) 
    { 
        no* aux = grafo->array[v].head; 
        while (aux) 
        { 
            printf("-> %d", aux->dest); 
            aux = aux->next; 
        } 
        printf("\n"); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // create the grafo given in above fugure 
    int V = 5; 
    grafo* grafo = criar_grafo(V); 
    addEdge(grafo, 0, 1); 
    addEdge(grafo, 0, 4); 
    addEdge(grafo, 1, 2); 
    addEdge(grafo, 1, 3); 
    addEdge(grafo, 1, 4); 
    addEdge(grafo, 2, 3); 
    addEdge(grafo, 3, 4); 
  
    // print the adjacency list representation of the above grafo 
    printgrafo(grafo); 
  
    return 0; 
}