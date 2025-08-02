// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* top = NULL;
void push(struct node** top, int data){
    struct node* newNode = malloc(sizeof(struct node));
    if(!newNode){
        puts("Memory allocation failed.");return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed : %d", data);
}
void pop(struct node** top){
    if(*top ==NULL){
        puts("Stack underflow.\n");return;
    }
    struct node* tmp = *top;
    *top = tmp->next;
    free(tmp);
    printf("Poped : %d\n", (*top)->data);
    
    
    
    
}

int main() {
    struct node* top = NULL;
    pop(&top);
    push(&top,7);push(&top,77);push(&top,97);push(&top,13);push(&top,42);push(&top,76);
    

    return 0;
}
