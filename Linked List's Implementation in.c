// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data ;
    struct node* next;
};


void insertPos(struct node** head, int data , int pos){
    if(head == NULL)return;
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    if(pos == 0){
        newNode->next = *head;
        *head = newNode;
    }
    else{
        struct node* current = *head;
        for(int i = 0; i< pos - 1; i++)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void reverseL(struct node** head){
    struct node *current = *head, *prev = NULL, *next = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    
}
void revPrint(struct node* head){
    if(head == NULL)return;
    revPrint(head->next);
    printf("%d ->", head->data);
}
void printL(struct node* head){
    if(head == NULL){
        puts("NULL\n");
        return;}
    printf("%d ->",head->data);
    printL(head->next);
}

int main() {
    
    struct node * head = NULL;

    insertPos(&head, 60,0);insertPos(&head, 70,1);insertPos(&head, 600,2);insertPos(&head, 680,0);insertPos(&head, 4080,0);insertPos(&head, 770,0);insertPos(&head, 960,0);
    printL(head);
    revPrint(head);puts("NULL\n");
    reverseL(&head);
    printL(head);
   
    return 0;
}
