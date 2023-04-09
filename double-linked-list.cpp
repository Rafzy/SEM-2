#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *next, *prev;
} *head = NULL, *tail = NULL;

typedef struct node node;

node *createnode(int n)
{
    node *newnode = (node *)malloc(sizeof(node));
    
}