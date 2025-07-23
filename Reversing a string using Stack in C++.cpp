#include<iostream>
#include<stack>

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
