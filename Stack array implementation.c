// Online C compiler to run C program online
#include <stdio.h>
// stack with arrays
int stack[100];
int top = -1;
void push(int x){
    if(top >= 99){
        puts("Stack overflow.");return;
    }
    stack[++top] = x;
    printf("Pushed %d \n",x);
    }
    

void pop(){
    if(top < 0){
        puts("Stack underflow.");return;
    }else{
        printf("Popped value : %d",stack[top--]);
    }
}
void display(){
    if(top == -1){
        printf("Stack is empty.");return;
    }
    for(int i = top; i >= 0 ; i--){
        puts("------");
        printf("| %d |\n",stack[i]);
    }
    puts("------");
}
void topf(){
    if(top > -1)
        printf("Top = %d", stack[top]);
}
int main() {
    pop();
    push(3);push(5);push(4532);push(94933);push(42324);push(99);push(1);push(355);
    topf();
    display();

    return 0;
}
