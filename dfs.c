#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int item;
    struct node *next;
} NODE;

typedef struct adj_list
{
    int item;
    struct adj_list *next;
} ADJ_LIST;

typedef struct graph
{
    ADJ_LIST *vertices[MAX];
    int visited[MAX];
} GRAPH;

NODE *create_node(int item)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->item = item;
    new->next = NULL;
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
    new->item = item;
    new->next = NULL;
    return new;
}

void add_edge(GRAPH *graph, int v1, int v2)
{
    ADJ_LIST *vertex = create_adj_list(v2);
    vertex->next = graph->vertices[v1];
    graph->vertices[v1] = vertex;

    //undirected
    vertex = create_adj_list(v1);
    vertex->next = graph->vertices[v2];
    graph->vertices[v2] = vertex;
}

void dfs(GRAPH *graph, int source)
{
    graph->visited[source] = 1;
    printf("%d", source);

    ADJ_LIST *adj_list = graph->vertices[source];

    while (adj_list != NULL)
    {
        if (!graph->vertices[adj_list->item])
        {
            dfs(graph, adj_list->item);
        }
        adj_list = adj_list->next;
    }
    create_node(source);
}

void print_graph(GRAPH *graph)
{

    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("Vertices: %d", i);
        ADJ_LIST *adj = graph->vertices[i];

        while (adj != NULL)
        {
            printf(" %d =>", adj->item);
            adj = adj->next;
        }
        printf("\n");
    }
}

int main()
{
    GRAPH *graph = create_graph();

    add_edge(graph, 1, 2);
    add_edge(graph, 1, 5);
    add_edge(graph, 2, 5);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);

    print_graph(graph);
    dfs(graph, 4);
    printf("\n");

    return 0;
}