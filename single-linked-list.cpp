#include <stdio.h>
#include <stdlib.h>

struct node{
    int n;
    struct node *next;
} *head = NULL, *tail = NULL;

typedef struct node node;

node *createnode(int n){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->n = n;
    newnode->next = NULL;
    return newnode;
}

void pushHead(int n){
    node *newnode = createnode(n);
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void pushTail(int n){
    node *newnode = createnode(n);
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}

void pushMid(int n){
    if(head == NULL){
        node *newnode = createnode(n);
        head = tail = newnode;
    }
    else if(n < head->n){
        pushHead(n); 
    }
    else if(n > tail->n){
        pushTail(n);
    }
    else{
        node *newnode = createnode(n);
        node *ptr = head;
        while(ptr->next->n < n){
            ptr = ptr->next;
        }
        node *second = ptr->next;
        ptr->next = newnode;
        newnode->next = second;
    }
}

void popHead(){
    if(head == NULL){
        printf("No data\n");
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *ptr = head->next;
        free(head);
        head = ptr;
    }
}

void popTail(){
    if(head == NULL){
        printf("no data\n");
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *ptr = head;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        free(tail);
        tail = ptr;
        tail->next = NULL;
    }
}

void popMid(int n){
    if(head == NULL){
        printf("No data\n");
    }
    else if(head == tail && head->n == n){
        free(head);
        head = tail = NULL;
    }
    else{
        node *ptr = head;
        while(ptr->next->n != n){
            ptr = ptr->next;
        }
        node *second = ptr->next;
        ptr->next = second->next;
        free(second);
    }
}

void printAll(){
    node *ptr = head;
    while(ptr != NULL){
        printf("%d->", ptr->n);
        ptr = ptr->next;
    }
}

int main(void){
    pushMid(4);
    pushMid(1);
    pushMid(3);
    pushMid(2);
    pushMid(5);
    pushMid(0);
    pushHead(12);
    pushTail(6);
    printAll();
    printf("\n\n");
    popHead();
    printAll();
    printf("\n\n");
    popTail();
    printAll();
    printf("\n\n");
    popMid(2);
    printAll();
}