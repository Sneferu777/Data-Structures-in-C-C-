// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data ;
    struct node* next;
};
struct Dnode{
    int data ; 
    struct Dnode* prev;
    struct Dnode* next; 
};
void insertDoublyFirst(struct Dnode** head, int data){
    struct Dnode* newNode = malloc(sizeof(struct Dnode));
    newNode->data = data;
    if(*head != NULL){
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
        
    }
    *head = newNode;
}




void printDoublyList(struct Dnode * head){
    
    while(head){
        printf("%d <->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void printDoublyListBack(struct Dnode* head){
    if(head == NULL){
        puts("NULL\n");return;
    }
    while(head->next != NULL){
        head = head->next;
    }
    while(head != NULL){
        printf("%d <->", head->data);
        head = head->prev;
    }
}


int main() {
   
    struct Dnode * head = NULL;
    
    insertDoublyFirst(&head, 60);insertDoublyFirst(&head, 70);insertDoublyFirst(&head, 80);insertDoublyFirst(&head, 90);
    printDoublyList(head);
    printDoublyListBack(head);
    
    return 0;
}
