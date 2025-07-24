#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct queue{
    struct node* front;
    struct node* rear;
};

// create an empty Q
void initQ(struct queue *q){
    q->front = q->rear = NULL;
}
//EnQueue at rear
void EnQ(struct queue * q, int data){
    struct node * newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(q->rear == NULL) //Queue is empty
        q->rear = q->front = newNode;
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int DQ(struct queue * q){
    if(q->front == NULL){
        puts("Queue is empty!");return -1;
    }
    int value = q->front->data;
    struct node* tmp = q->front;
    q->front = q->front->next;
    free(tmp);
    return value;
    
}
int main(){
    int val;
    struct queue* q ;
    initQ(q);
    EnQ(q,3);EnQ(q,4);EnQ(q,6);EnQ(q,88);
    val = DQ(q);
    printf("Value DeQueued is : %d", val);
    
return 0;}

    
    
