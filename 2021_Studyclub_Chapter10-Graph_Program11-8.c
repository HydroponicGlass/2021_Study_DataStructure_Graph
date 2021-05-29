/*
*   Program 11.8 : MST using kruskal
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_VERTEX 50   // Max vertex is 255
#define INF 255

typedef struct
{
    uint8_t start;
    uint8_t end;
    uint8_t weight;
} edge_st;

typedef struct 
{
    uint8_t edgeNum;
    edge_st edge[MAX_VERTEX * 2];
} grpah_st;

int8_t parentNode[MAX_VERTEX];

void InitParentNode()
{
    memset(parentNode, -1, sizeof(parentNode));
}

uint8_t SetFind(uint8_t a)
{
    uint8_t curr = a;
    while(parentNode[curr] != -1)
    {
        curr = parentNode[curr];
    }
    return curr;
}

void SetUnion(uint8_t a, uint8_t b)
{
    uint8_t root1 = SetFind(a);
    uint8_t root2 = SetFind(b);

    if(root1 != root2)
    {
        parentNode[root1] = root2;
    }
}

void InitGraph(grpah_st *graph)
{
    uint8_t loop;
    for(loop = 0; loop < MAX_VERTEX * 2; loop++)
    {
        graph->edge[loop].start = 0;
        graph->edge[loop].end = 0;
        graph->edge[loop].weight = INF;
    }
}

void InsertEdge(grpah_st *graph, uint8_t start, uint8_t end, uint8_t weight)
{
    graph->edge[graph->edgeNum].start = start;
    graph->edge[graph->edgeNum].end = end;
    graph->edge[graph->edgeNum].weight = weight;
    graph->edgeNum++;
}

int compare (const void* a, const void* b)
{
    edge_st* x = (edge_st*)a;
    edge_st* y = (edge_st*)b;
    return  (x->weight - y->weight);
}

void kruskal(grpah_st* graph)
{
    uint8_t loop;
    uint8_t root1, root2;
    
    InitParentNode(graph);
    qsort(graph->edge, graph->edgeNum, sizeof(edge_st), compare);
    for(loop = 0; loop < graph->edgeNum; loop++)
    {
        root1 = SetFind(graph->edge[loop].start);
        root2 = SetFind(graph->edge[loop].end);
        if(root1 != root2)
        {
            printf("(%d, %d) : %d \n", graph->edge[loop].start, graph->edge[loop].end, graph->edge[loop].weight);
            SetUnion(root1, root2);
        }
    }
}

int main()
{
    grpah_st *graph;
    graph = (grpah_st* )malloc(sizeof(grpah_st));
    
    InitGraph(graph);

    InsertEdge(graph, 0, 1, 29);
    InsertEdge(graph, 1, 2, 16);
    InsertEdge(graph, 2, 3, 12);
    InsertEdge(graph, 3, 4, 22);
    InsertEdge(graph, 4, 5, 27);
    InsertEdge(graph, 5, 0, 10);
    InsertEdge(graph, 6, 1, 15);
    InsertEdge(graph, 6, 3, 18);
    InsertEdge(graph, 6, 4, 25);

    kruskal(graph);
    free(graph);

}