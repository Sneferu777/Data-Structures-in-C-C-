// DATA STRUCTURES EXERCICES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//SINGLY LINKED LIST
struct node{
    int data;
    struct node* next;
};
//REVERSE A LINKED LIST

void reverseL(struct node** head){
    struct node *prev = NULL, *current = *head, *next = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    };
    *head = prev;
}

//FIND THE Nth NODE FROM THE END 
void nthNodeFromEnd(struct node* head, int N){
    struct node *first, *second;
    first = second = head;
    for(int i = 0; i < N; i++){
        if(!first){
            printf("List is shorter than %d nodes", N);return;
        }
        first = first->next;
    }
    while(first){
        first = first->next; second = second->next;
    }
    printf("THE NODE AT THE %d nt POSITION FORM THE END IS : %d\n",N, second->data);
}

//DOUBLY LINKED LIST 
//REVERSE A DOUBLY LINKED LIST

struct Dnode{
    int data;
    struct Dnode* prev;
    struct Dnode* next;
};

void reverseDoubleL(struct Dnode** head){
    struct Dnode *current = *head, *tmp = NULL;
    while(current){
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        
        //mov to the next node wich is previous after swap
        current = current->prev;
    }
    if(tmp != NULL)
        *head = tmp->prev;
}

int main() {
    

    return 0;
}
