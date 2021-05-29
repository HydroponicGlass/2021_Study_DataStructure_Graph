/*
*   Program 11.13 : Topology Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stack>

using namespace std;

#define MAX_VERTEX    50    // MAX 255

stack<uint8_t>s;
uint8_t degree[MAX_VERTEX];

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
        //printf("Current Vertex num is %d \n", graph->n);
    }
}

void InsertEdge(graph_st *graph, uint8_t u, uint8_t v)
{
    node_st *node;

    if((u > graph->n) || (v > graph->n))
    {
        //printf("[Error] Check Edge num \n");
    }
    else
    {
        node = (node_st*)malloc(sizeof(node_st));
        node->vertex = v;
        node->link = graph->list[u];
        graph->list[u] = node;
    }
}

void DoTopologySort(graph_st* graph)
{
    uint8_t loop;

    /* degree initialization    */
    for(loop = 0; loop < graph->n; loop++)
    {
        node_st* node = graph->list[loop];
        while(node != NULL)
        {
            degree[node->vertex]++;
            node = node->link;
        }
    }
    /*  for test
    for(loop = 0; loop < graph->n; loop++)
    {
        printf("%d ", degree[loop]);
    }
    */

    for(loop = 0; loop < graph->n; loop++)
    {
        if(degree[loop] == 0) s.push(loop);
    }

    while(!s.empty())
    {
        uint8_t currVertex;
        node_st* node;

        currVertex = s.top();
        node = graph->list[currVertex];
        printf("%d ", currVertex);
        s.pop();

        while(node != NULL)
        {
            degree[node->vertex]--;
            if(degree[node->vertex] == 0) s.push(node->vertex);
            node = node->link;
        }
    }
}

int main()
{
    uint8_t vertexNum = 6;
    uint8_t loop;
    graph_st *graph;
    graph = (graph_st *)malloc(sizeof(graph_st));

    InitGraph(graph);
    for(loop = 0; loop < vertexNum; loop++)
    {
        InsertVertex(graph);
    }
    InsertEdge(graph, 0, 2);
    InsertEdge(graph, 0, 3);
    InsertEdge(graph, 1, 3);
    InsertEdge(graph, 1, 4);
    InsertEdge(graph, 2, 3);
    InsertEdge(graph, 2, 5);
    InsertEdge(graph, 3, 5);
    InsertEdge(graph, 4, 5);
    
    DoTopologySort(graph);
    free(graph);
}