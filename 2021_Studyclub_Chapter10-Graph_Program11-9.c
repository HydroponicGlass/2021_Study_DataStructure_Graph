/*
*   Program 11.9 : MST using PRIM
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

uint8_t vertexSelected[MAX_VERTEX];
uint8_t vertexDistance[MAX_VERTEX];

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

void DoPrim(graph_st* graph, uint8_t start)
{
    uint8_t loop, firstLoop, secondLoop;
    uint8_t currVertex, nextVertex;

    /*  distance initialization  */
    for(loop = 0; loop <graph->vertexNum; loop++)
    {
        vertexDistance[loop] = INF;
    }
    vertexDistance[start] = 0;

    for(firstLoop = 0; firstLoop < graph->vertexNum; firstLoop++)
    {
        currVertex = GetMinDistance(graph->vertexNum);
        if(vertexDistance[currVertex] == INF) return;
        vertexSelected[currVertex] = 1;
        printf("vertex : %d \n", currVertex);
        for(secondLoop = 0; secondLoop < graph->vertexNum; secondLoop++)
        {
            if(vertexSelected[secondLoop] != 1 && graph->weight[currVertex][secondLoop] < vertexDistance[secondLoop])
            {
                vertexDistance[secondLoop] = graph->weight[currVertex][secondLoop];
            }
        }
    }
}

int main()
{
    graph_st graph = {7,{
        {0, 29, INF, INF, INF, 10, INF},
        {29, 0, 16, INF, INF, INF, 15},
        {INF, 16, 0, 12, INF, INF, INF},
        {INF, INF, 12, 0, 22, INF, 18},
        {INF, INF, INF, 22, 0, 27, 25},
        {10, INF, INF, INF, 27, 0, INF},
        {INF, 15, INF, 18, 25, INF, 0}
    }};
    DoPrim(&graph, 0);
}