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
    int distancy[MAX];
} GRAPH;

NODE *createNode(int item)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

ADJ_LIST *create_adj_list(int item)
{
    ADJ_LIST *new = (ADJ_LIST *)malloc(sizeof(ADJ_LIST));
    new->front = (NODE *)malloc(sizeof(NODE));
    new->front->item = item;
    new->front->next = NULL;
    return new;
}

QUEUE *create_queue()
{
    QUEUE *new = (QUEUE *)malloc(sizeof(QUEUE));
    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    return new;
}

GRAPH *create_graph()
{
    GRAPH *new = (GRAPH *)malloc(sizeof(GRAPH));
    int i;
    for (i = 1; i < MAX - 1; i++)
    {
        new->vertices[i] = NULL;
        new->visited[i] = 0;
        new->distancy[i] = 0;
    }
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
    if (graph->vertices[v1] == NULL)
    {
        graph->vertices[v1] = create_adj_list(v2);
    }
    else
    {
        NODE *new = createNode(v2);
        NODE *new2 = graph->vertices[v1]->front;
        new->next = graph->vertices[v1]->front;
        graph->vertices[v1]->front = new;
        // graph->distancy[v1]++;
    }
}

int bfs(GRAPH *graph, int origem, int destino)
{
    QUEUE *queue = create_queue();

    int dequeued, count = 0;
    NODE *node = graph->vertices[origem]->front;
    graph->visited[origem] = 1;
    enqueue(queue, origem);
    while (!is_empty(queue))
    {
        dequeued = dequeue(queue);
        if (graph->vertices[dequeued] == NULL)
        {
            continue;
        }
        node = graph->vertices[dequeued]->front;
        while (node != NULL)
        {
            if (graph->visited[node->item] == 0)
            {
                enqueue(queue, node->item);
                graph->visited[node->item] = 1;
                graph->distancy[node->item] = graph->distancy[dequeued] + 1;
            }
            node = node->next;
        }
    }
    return graph->distancy[destino];
}

void printGraph(GRAPH *graph)
{
    int i;
    NODE *aux;
    for (i = 1; i <= MAX - 1; i++)
    {
        if (graph->vertices[i] == NULL)
        {
            continue;
        }
        aux = graph->vertices[i]->front;
        printf("Vertex: %d: ", i);
        while (aux != NULL)
        {
            printf("%d => ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

void add_undirected(GRAPH *graph, int v1, int v2)
{
    add_edge(graph, v1, v2);
    add_edge(graph, v2, v1);
}

int main()
{

    int caso_teste, n, m, x, y, i, j, k;

    scanf("%d", &caso_teste);
    int ok;
    for (i = 0; i < caso_teste; i++)
    {
        GRAPH *graph = create_graph();
        scanf("%d%d", &n, &m);
        for (j = 0; j < m; j++)
        {
            scanf("%d%d", &x, &y);
            add_undirected(graph, x, y);
        }
        // printf("\n");
        ok = bfs(graph, 1, n);

        if (ok >= 1)
        {
            printf("%d\n", ok);
        }
        else
        {
            printf("-1\n");
        }
        // printf("ok = %d\n",ok);
        // printGraph(graph);
    }

}
