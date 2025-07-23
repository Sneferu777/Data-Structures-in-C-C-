#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void EnQueue(int x){
    if(rear == SIZE -1){
        puts("Queue Overflow!");return;
    }
    
    if(front == -1)front = 0;
    queue[++rear] = x;
}
void DeQueue(){
    if(front == rear){
        puts("Queue Underflow!");return;
    }
    front++;
}
void DisplayQueue(){
    if(front == rear){
        puts("Queue Underflow : (empty)");return;
    }
    for(int i = 0; i <= rear; i++)
        printf("%d ->", queue[i]);
    puts("NULL");
}

int main() {
    DeQueue();
    EnQueue(1);EnQueue(4);EnQueue(14);EnQueue(551);EnQueue(99);
    DisplayQueue();

    return 0;
}
