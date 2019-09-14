#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000

typedef struct node
{
    int item;
    struct node *next;
} NODE;

typedef struct queue
{
    NODE *head;
    NODE *tail;
    int size;
} QUEUE;

typedef struct adj_list
{
    NODE *front;
} ADJ_LIST;

typedef struct graph
{
    ADJ_LIST *vertices[MAX];
    int visited[MAX];
} GRAPH;

NODE *createNode(int item)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

QUEUE *create_queue()
{
    QUEUE *new = malloc(sizeof(QUEUE));
    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    return new;
}

GRAPH *create_graph()
{
    GRAPH *new = (GRAPH *)malloc(sizeof(GRAPH));
    int i;
    for (i = 0; i < MAX; i++)
    {
        new->vertices[i] = NULL;
        new->visited[i] = 0;
    }
    return new;
}

ADJ_LIST *create_adj_list(int item)
{
    ADJ_LIST *new = (ADJ_LIST *)malloc(sizeof(ADJ_LIST));
    new->front = (NODE *)malloc(sizeof(NODE));
    new->front->item = item;
    new->front->next = NULL;
    return new;
}

void enqueue(QUEUE *queue, int item)
{
    NODE *newNode = createNode(item);
    if (queue->size == 0)
    {
        queue->head = newNode;
        queue->tail = newNode;
        queue->size++;
        return;
    }
    queue->tail->next = newNode;
    queue->tail = newNode;
    queue->size++;
    return;
}

int dequeue(QUEUE *queue)
{
    if (!queue->size)
    {
        printf("0 elementos\n");
        return 0;
    }
    if (queue->size == 1)
    {
        queue->size--;
        NODE *a = queue->head;
        queue->head = NULL;
        queue->tail = NULL;
        int value = a->item;
        free(a);
        return value;
    }
    NODE *aux = queue->head;
    int value = aux->item;

    queue->head = aux->next;
    queue->size--;
    free(aux);
    return value;
}

int is_empty(QUEUE *queue)
{
    return (queue->size == 0);
}

//directed
void add_edge(GRAPH *graph, int v1, int v2)
{
    if(graph->vertices[v1] == NULL)
    {
        graph->vertices[v1] = create_adj_list(v2);
    }
    else
    {
        NODE *new = createNode(v2);
        NODE *new2 = graph->vertices[v1]->front;
        new->next = graph->vertices[v1]->front;
        graph->vertices[v1]->front = new;
   }
    
}

void bfs(GRAPH *graph, int source)
{
    QUEUE *queue = create_queue();

    int dequeued;
    NODE *node = graph->vertices[source]->front;
    graph->visited[source] = 1;
    enqueue(queue, source);

    while (!is_empty(queue))
    {
        dequeued = dequeue(queue);
        if(graph->vertices[dequeued] == NULL)
        {
            continue;
        }
        node = graph->vertices[dequeued]->front;
        while (node != NULL)
        {
            if (graph->visited[node->item] == 0)
            {
                printf("%d\n", node->item);
                enqueue(queue, node->item);
                graph->visited[node->item] = 1;
            }
            node = node->next;
        }
    }
}




int main()
{
    GRAPH *grafo = create_graph();
    int vertices, i, origem, v1, v2;
    scanf("%d%d", &vertices, &origem);
    printf("%d\n", origem);
    while (scanf("%d%d", &v1, &v2)!=EOF)
    {
        add_edge(grafo, v1, v2);
    }
    
    bfs(grafo, origem);
}