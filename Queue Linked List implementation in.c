#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct queue{
    node * front;
    node* rear;
}queue;

queue* initQ(){
    queue* q = malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}
void enq(queue* q, int value){
    node* tmp = malloc(sizeof(node));
    tmp->data = value;
    tmp->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = tmp;
        return;
    }
    q->rear->next = tmp;
    q->rear = tmp;
    
}
int dq(queue* q ){
    if(q->front == NULL){
        puts("Queue underflow.");return -1;
    }
    node* tmp = q->front;
    int value = tmp->data;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(tmp);
    return value;
}

int main(){
     queue * q = NULL;
     q = initQ();
     enq(q,10);enq(q,20);enq(q,133);enq(q,50);
     int value = dq(q);
     printf("Dequeued value is  : %d", value);
     value = dq(q);
     printf("Dequeued value is  : %d", value);
    return 0;
}
