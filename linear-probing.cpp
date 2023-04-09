#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10


struct node{
    char name[30];
    int value;
} *table[MAX];

typedef struct node node;

int hashing(const char name[]){
    int length = strlen(name);
    int total = 0;
    for(int i = 0; i < length ; i++){
          total += name[i];
    }
    return total % MAX;
}

node *createnode(const char name[]){
    node *newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->name, name);
    newnode->value = hashing(newnode->name);
    return newnode;
}

void push(const char name[]){
    node *newnode = createnode(name);
    int curr = newnode->value;
    int count = 0;
    while(table[curr] != NULL){
        curr++;
        count++;
        if(curr >= MAX){
            curr = 0;
        }
        if(count >= MAX){
            printf("%s, Table is full\n", newnode->name);
            return;
        }
    }
    table[curr] = newnode;
}

void printall(){
    for(int i = 0; i < MAX ; i++){
        if(table[i] == NULL){
            continue;
        }
        printf("%s->%d\n", table[i]->name, table[i]->value);
    }
}

int main(void){
    push("rafael");
    push("matthew");
    push("marco");
    push("didi");
    push("kevin");
    push("micko");
    push("william");
    push("akira");
    push("adjie");
    push("mo");
    push("upin");
    printall();
}