#include<iostream>
#include<stack>

// C implementation we must include <string.h> <stdio.h>
void reverseSTR(char* str){
    char stack[100]; int top = -1;
    size_t len = strlen(str);
    for(int i = 0; i< len; i++)
        stack[++top] = str[i];
    
    for(int i = 0; i < len; i++){
        str[i] = stack[top--];
    }
    puts(str);
}


int main(){
  
    std::string str = "Sneferu";
    std::stack<char> s; 
    std::string stri;
    for(char c : str)
        s.push(c);
    int i = 0;
    while(!s.empty() && i < str.length(){
        str[i] = s.top();i++;
        s.pop();
    }
    std::cout<<"Reversed\t" << str <<std::endl;

    
    


return 0;}
