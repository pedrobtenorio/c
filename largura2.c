#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct lista_adj no;
typedef struct grafo grafo;
typedef struct fila fila;

#define tammax 300

struct fila
{
    int items[tammax];
    int comeco;
    int final;
};

struct lista_adj
{
    int vertice;
    no* prox;
};

struct grafo
{
    int numv;
    no** adj;
    int *visitado;
};


fila* createQueue() {
    fila* q = malloc(sizeof(fila));
    q->comeco = -1;
    q->final = -1;
    return q;
}
int isEmpty(fila* q) {
    if(q->final == -1) 
        return 1;
    else 
        return 0;
}
void enqueue(fila* q, int value){
    if(q->final == tammax-1)
        printf("\nQueue is Full!!");
    else {
        if(q->comeco == -1)
            q->comeco = 0;
        q->final++;
        q->items[q->final] = value;
    }
}
int dequeue(fila* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->comeco];
        q->comeco++;
        if(q->comeco > q->final){
            printf("Resetting queue");
            q->comeco = q->final = -1;
        }
    }
    return item;
}
void printQueue(fila *q) {
    int i = q->comeco;
    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->comeco; i < q->final + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }    
}

no* createNode(int v)
{
    no* newNode = malloc(sizeof(no));
    newNode->vertice = v;
    newNode->prox = NULL;
    return newNode;
}
 
grafo* createGraph(int vertices)
{
    grafo* graph = malloc(sizeof(grafo));
    graph->numv = vertices;
 
    graph->adj = malloc(vertices * sizeof(no*));
    graph->visitado = malloc(vertices * sizeof(int));
    
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adj[i] = NULL;
        graph->visitado[i] = 0;
    }
 
    return graph;
}

void addEdge(grafo* graph, int src, int dest)
{
    // Add edge from src to dest
    no* newNode = createNode(dest);
    newNode->prox = graph->adj[src];
    graph->adj[src] = newNode;
 
   
}

void bfs(grafo* graph, int inicio) {
    struct queue* q = createQueue();
    
    graph->visitado[inicio] = 1;
    enqueue(q, inicio);
    
    while(!isEmpty(q)){
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("visitado %d\n", currentVertex);
    
       no* temp = graph->adj[currentVertex];
    
       while(temp) {
            int adjVertex = temp->vertice;
            if(graph->visitado[adjVertex] == 0){
                graph->visitado[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->prox;
       }
    }
}


int main()
{
    grafo* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
 
    bfs(graph, 0);
 
    return 0;
}