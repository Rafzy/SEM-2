#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int arr[MAX];

int curr = -1;

void insert(int n){
    if(curr >= 4){
        printf("Stack is full\n");
    }
    else{
        curr++;
        arr[curr] = n;
    }
}

void pop(){
    if(curr <= -1){
        printf("Stack is empty\n");
    }
    else{
        curr--;
    }
}

void printall(){
    for(int i = 0; i <= curr; i++){
        printf("%d\n", arr[i]);
    }
}

int main(void){
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    printall();
    printf("\n\n");
    pop();
    printall();
    
}