/*
*   Program 11.7 : Union Find
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_VERTEX 50   // Max vertex is 255

uint8_t parentNode[MAX_VERTEX];

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