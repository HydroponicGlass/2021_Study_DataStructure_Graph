/*
*   Program 10.1 : Undirected graph using matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_VERTEX    50    // MAX 255

typedef struct 
{
    uint8_t n; // vertex num
    uint8_t matrix[MAX_VERTEX+1][MAX_VERTEX+1];
} graph_st;

void InitGraph(graph_st *graph)
{
    graph->n = 0;
    memset(graph->matrix, 0, sizeof(graph->matrix));
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

void InsertEdge(graph_st *graph, uint8_t start, uint8_t end)
{
    if((start > graph->n) || (end > graph->n))
    {
        printf("[Error] Check Edge num \n");
    }
    else
    {
        graph->matrix[start][end] = 1;
        graph->matrix[end][start] = 1;
    }
}

void PrintGraph(graph_st *graph)
{
    uint8_t loopFirst, loopSecond;

    for(loopFirst = 0; loopFirst < graph->n; loopFirst++)
    {
        for(loopSecond = 0; loopSecond < graph->n; loopSecond++)
        {
            printf("%d ", graph->matrix[loopFirst][loopSecond]);
        }
        printf("\n");
    }
}
int main()
{
    uint8_t vertexNum = 4;
    uint8_t loop;
    graph_st *graph;
    graph = (graph_st *)malloc(sizeof(graph_st));

    InitGraph(graph);
    for(loop = 0; loop < vertexNum; loop++)
    {
        InsertVertex(graph);
    }
    InsertEdge(graph, 0, 1);
    InsertEdge(graph, 0, 2);
    InsertEdge(graph, 0, 3);
    InsertEdge(graph, 1, 2);
    InsertEdge(graph, 2, 3);
    PrintGraph(graph);
    free(graph);
}