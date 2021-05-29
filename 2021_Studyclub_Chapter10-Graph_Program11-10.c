/*
*   Program 11.10 : Dijkstra
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_VERTEX 50   // Max vertex is 255
#define INF 255

typedef struct
{
    uint8_t vertexNum;
    uint8_t weight[MAX_VERTEX][MAX_VERTEX];
} graph_st;

uint8_t vertexDistance[MAX_VERTEX];
uint8_t vertexSelected[MAX_VERTEX];

uint8_t GetMinDistance(uint8_t vertexNum)
{
    uint8_t loop;
    uint8_t min = INF;
    uint8_t currVertex;
    for(loop = 0; loop < vertexNum; loop++)
    {
        if(vertexSelected[loop] != 1 && vertexDistance[loop] < min)
        {
            currVertex = loop;
            min = vertexDistance[loop];
        }
    }
    // for(int i = 0; i<vertexNum;i++) printf("%d ", vertexDistance[i]);
    return currVertex;
}

void Print(uint8_t vertexNum)
{
    uint8_t loop;
    
    printf("distance : ");
    for(loop = 0; loop < vertexNum; loop++)
    {
        printf("%d ", vertexDistance[loop]);
    }
    printf("selected : ");
    for(loop = 0; loop < vertexNum; loop++)
    {
        printf("%d ", vertexSelected[loop]);
    }
    printf("\n");
}

void Dijkstra(graph_st* graph, uint8_t start)
{
    uint8_t loop, firstLoop, secondLoop;
    uint8_t currVertex;

    /* distance initialization  */
    for(loop = 0; loop < graph->vertexNum; loop++)
    {
        vertexDistance[loop] = INF;
    }
    vertexDistance[start] = 0;

    for(firstLoop = 0; firstLoop < graph->vertexNum; firstLoop++)
    {   
        Print(graph->vertexNum);
        currVertex = GetMinDistance(graph->vertexNum);
        vertexSelected[currVertex] = 1;
        for(secondLoop = 0; secondLoop < graph->vertexNum; secondLoop++)
        {
            if(vertexSelected[secondLoop] != 1 && vertexDistance[currVertex] + graph->weight[currVertex][secondLoop] < vertexDistance[secondLoop])
            {
                vertexDistance[secondLoop] = vertexDistance[currVertex] + graph->weight[currVertex][secondLoop];
            }
        }
    }
}

int main()
{
        graph_st graph = {7,{
        {0, 7, INF, INF, 3, 10, INF},
        {7, 0, 4, 10, 2, 6, INF},
        {INF, 4, 0, 2, INF, INF, INF},
        {INF, 10, 2, 0, 11, 9, 4},
        {3, 2, INF, 11, 0, INF, 5},
        {10, 6, INF, 9, INF, 0, INF},
        {INF, INF, INF, 4, 5, INF, 0}
    }};

    Dijkstra(&graph, 0);
}