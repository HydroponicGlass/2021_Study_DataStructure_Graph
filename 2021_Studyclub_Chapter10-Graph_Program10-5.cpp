/*
*   Program 10.3 : BFS Using matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX_VERTEX    50    // MAX 255
#define VERTEX_NUM  5

typedef struct 
{
    uint8_t n; // vertex num
    uint8_t matrix[MAX_VERTEX+1][MAX_VERTEX+1];
    uint8_t visited[MAX_VERTEX+1];
} graph_st;

queue<uint8_t>q;

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

void DoBFS(graph_st *graph, uint8_t startVertex)
{
    uint8_t loop;

    graph->visited[startVertex] = 1;
    q.push(startVertex);

    while(!q.empty())
    {
        uint8_t vertex = q.front();
        q.pop();

        printf("%d ", vertex);
        for(loop = 0; loop <= graph->n; loop++)
        {
            if(graph->visited[loop] != 1 && graph->matrix[vertex][loop] == 1)
            {
                q.push(loop);
                graph->visited[loop] = 1;
            }
        }
    }
}

int main()
{
    uint8_t loop;
    graph_st *graph;
    graph = (graph_st *)malloc(sizeof(graph_st));

    InitGraph(graph);
    for(loop = 0; loop < VERTEX_NUM; loop++)
    {
        InsertVertex(graph);
    }
    InsertEdge(graph, 0, 2);
    InsertEdge(graph, 2, 1);
    InsertEdge(graph, 2, 3);
    InsertEdge(graph, 0, 4);
    InsertEdge(graph, 4, 5);
    InsertEdge(graph, 1, 5);

    printf("BFS : ");
    DoBFS(graph, 0);
    
    free(graph);
}