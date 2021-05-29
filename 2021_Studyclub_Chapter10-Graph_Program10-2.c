/*
*   Program 10.2 : Undirected graph using list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_VERTEX    50    // MAX 255
#define VERTEX_NUM  4

typedef struct node_st
{
    uint8_t vertex;
    struct node_st *link;
} node_st;

typedef struct 
{
    uint8_t n; // vertex num
    node_st *list[MAX_VERTEX+1];
} graph_st;

void InitGraph(graph_st *graph)
{
    uint8_t loop;
    graph->n = 0;
    for(loop = 0; loop <= MAX_VERTEX; loop++)
    {
        graph->list[loop] = NULL;
    }
}

void InsertVertex(graph_st *graph)
{
    if((graph->n + 1) > MAX_VERTEX)
    {
        printf("[Error] Grpah Overflow \n");
    }
    else
    {
        graph->n += 1;
        printf("Current Vertex num is %d \n", graph->n);
    }
}

void InsertEdge(graph_st *graph, uint8_t u, uint8_t v)
{
    node_st *node;

    if((u > graph->n) || (v > graph->n))
    {
        printf("[Error] Check Edge num \n");
    }
    else
    {
        node = (node_st*)malloc(sizeof(node_st));
        node->vertex = v;
        node->link = graph->list[u];
        graph->list[u] = node;
    }
}

void PrintGraph(graph_st *graph)
{
    uint8_t loop;
    for(loop = 0; loop <= graph->n; loop++)
    {
        printf("List of %d vertex : ", loop);
        node_st *node = graph->list[loop];
        while(node != NULL)
        {
            printf("%d ", node->vertex);
            node = node->link;
        }
        printf("\n");
    }
}
int main()
{
    uint8_t vertexNum = VERTEX_NUM;
    uint8_t loop;
    graph_st *graph;
    graph = (graph_st *)malloc(sizeof(graph_st));

    InitGraph(graph);
    for(loop = 0; loop < vertexNum; loop++)
    {
        InsertVertex(graph);
    }
    InsertEdge(graph, 0, 1);
    InsertEdge(graph, 1, 0);
    InsertEdge(graph, 0, 2);
    InsertEdge(graph, 2, 0);
    InsertEdge(graph, 0, 3);
    InsertEdge(graph, 3, 0);
    InsertEdge(graph, 1, 2);
    InsertEdge(graph, 2, 1);
    InsertEdge(graph, 2, 3);
    InsertEdge(graph, 3, 2);
    PrintGraph(graph);
    free(graph);
}