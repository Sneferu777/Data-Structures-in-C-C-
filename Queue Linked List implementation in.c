// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data ; 
    struct node * next;
};
void CreateQueue(struct node** head, int data){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(*head == NULL) *head = newNode;
    else{
        struct node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}
void displayQ(struct node* head){
    while(head != NULL){
        printf("%d ->", head->data);
        head = head->next;
    }
    puts("NULL");
}


int main() {
    struct node * head = NULL;
    CreateQueue(&head,10);CreateQueue(&head,100);CreateQueue(&head,1000);
    displayQ(head);

    return 0;
}
