/*
*   Program 10.6 : BFS using list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX_VERTEX    50    // MAX 255
#define VERTEX_NUM  5

typedef struct node_st
{
    uint8_t vertex;
    struct node_st *link;
} node_st;

typedef struct 
{
    uint8_t n; // vertex num
    uint8_t visited[MAX_VERTEX+1];
    node_st *list[MAX_VERTEX+1];
} graph_st;

queue<uint8_t>q;

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

void DoBFS(graph_st *graph, uint8_t startVertex)
{
    node_st *node = graph->list[startVertex];

    q.push(startVertex);
    graph->visited[startVertex] = 1;

    while(!q.empty())
    {
        node = graph->list[q.front()];
        printf("%d ", q.front());
        q.pop();

        while(node != NULL)
        {
            if(graph->visited[node->vertex] != 1)
            {
                q.push(node->vertex);
                graph->visited[node->vertex] = 1;
            }
            node = node->link;
        }
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