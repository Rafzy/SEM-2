#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node{
    char op;
    int presedence;
    struct node *next;
} *head = NULL, *tail = NULL;

typedef struct node node;

int presedence(char op){
    switch(op){
        case '^':
        return 3;
        break;

        case '*':
        case '/':
        return 2;
        break;

        case '+':
        case '-':
        return 1;
        break;

        default:
        return -1;
        break;
    }
}

node *createnode(char op){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->op = op;
    newnode->presedence = presedence(newnode->op);
    newnode->next = NULL;
    return newnode;
}

void push(char op){
    node *newnode = createnode(op);
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

char pop(){
    char place;
    if(head == NULL){
        return '\0';
    }
    else if(head == tail){
        char place = head->op;
        free(head);
        head = tail = NULL;
        return place;
    }
    else{
        char place = head->op;
        node *ptr = head->next;
        free(head);
        head = ptr;
        return place;
    }
}

int main(void){
    char equation[100];
    char postfix[100];
    printf("Put in the equation:\n");
    scanf("%[^\n]", equation);getchar();
    int length = strlen(equation);
    int i;
    int k = 0;
    for(i = 0; i  < length ; i++){
        if(equation[i] == ' '){
            continue;
        }
        else if(isalpha(equation[i]) != 0){
            postfix[k] = equation[i];
            k++;
        }
        else if(isdigit(equation[i]) != 0){
            postfix[k] = equation[i];
            k++;
        }
        else{
            int pres = presedence(equation[i]);
            if(head == NULL){
                push(equation[i]);
            }
            else if(equation[i] == '('){
                push(equation[i]);
            }
            else if(equation[i] == ')'){
                while(head->op != '('){
                    postfix[k] = pop();
                    k++;
                }
                pop();
            }
            else{
                while(head != NULL){
                    if(head->presedence >= pres){
                        postfix[k] = pop();
                        k++;
                    }
                    else{
                        break;
                    }
                }
                push(equation[i]);
            }
        }
    }
    while(head != NULL){
        postfix[k] = pop();
        k++;
    }
    postfix[k] = '\0';
    printf("Postfix:\n");
    printf("%s\n", postfix);
}