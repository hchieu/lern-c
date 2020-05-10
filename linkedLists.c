#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void* nodeData;
    struct node* link;
}NODE;

NODE* createNode(void* itemPtr)
{
    NODE* nodePtr;
    nodePtr = (NODE*)malloc(sizeof(NODE));
    nodePtr->nodeData = itemPtr;
    nodePtr->link = NULL;
    return nodePtr;
}

int main(void)
{
    int* newData;
    int* nodeData;
    NODE* node;
    newData = (int*)malloc(sizeof(int));
    *newData = 10;

    node = createNode(newData);
    nodeData = (int*)node->nodeData;
    printf("Data from node 1: %d\n", *nodeData);

    newData = (int*)malloc(sizeof(int));
    *newData = 20;
    node->link = createNode(newData);
    nodeData = (int*)node->link->nodeData;
    printf("Data from node 2: %d\n", *nodeData);

    newData = (int*)malloc(sizeof(int));
    *newData = 30;
    node->link = createNode(newData);
    nodeData = (int*)node->link->nodeData;
    printf("Data from node 3: %d\n", *nodeData);

    return 0;
}