/*
*   Program 11.11 : Flyod
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

uint8_t matrix[MAX_VERTEX][MAX_VERTEX];

void Print(graph_st* graph)
{
    uint8_t firstLoop, secondLoop;
    
    printf("=================\n");
    for(firstLoop = 0; firstLoop < graph->vertexNum; firstLoop++)
    {
        for(secondLoop = 0; secondLoop < graph->vertexNum; secondLoop++)
        {
            printf("%d ", matrix[firstLoop][secondLoop]);
        }   
        printf("\n");
    }

    printf("=================\n");
}

void DoFloyd(graph_st* graph)
{
    uint8_t firstLoop, secondLoop, thirdLoop;
    
    for(firstLoop = 0; firstLoop < graph->vertexNum; firstLoop++)
    {
        for(secondLoop = 0; secondLoop < graph->vertexNum; secondLoop++)
        {
            matrix[firstLoop][secondLoop] = graph->weight[firstLoop][secondLoop];    
        }   
    }

    for(firstLoop = 0; firstLoop < graph->vertexNum; firstLoop++)
    {
        for(secondLoop = 0; secondLoop < graph->vertexNum; secondLoop++)
        {
            for(thirdLoop = 0; thirdLoop < graph->vertexNum; thirdLoop++)
            {
                if(matrix[firstLoop][thirdLoop] + matrix[thirdLoop][secondLoop] < matrix[firstLoop][secondLoop])
                {
                    matrix[firstLoop][secondLoop] = matrix[firstLoop][thirdLoop] + matrix[thirdLoop][secondLoop];
                }
            }  
        }   
    }

    Print(graph);
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

    DoFloyd(&graph);
}