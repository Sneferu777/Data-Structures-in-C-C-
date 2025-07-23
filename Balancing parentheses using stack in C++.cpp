#include <iostream>
#include <stack>
#include<string.h>

bool balance(const std::string& str){
        std::stack<char> b;
        for(char c : str){
            if(c == '(' || c =='[' || c == '{'){
                b.push(c);
            }
            else if(c == ')' || c == ']' || c == '}'){
                if(b.empty()) return false;
                char top = b.top();
                if((c == ')' && top != '(') ||
                    (c == '[' && top != ']') ||
                    (c == '}' && top != '}')
                    ) return false;
                b.pop();
            }
        }
        return b.empty();
        
    }

int main() {
    
   
    stri = "{hello(())[]";
    
    std::cout<<"balanced? : "<< std::boolalpha<< balance(stri)<<std::endl;
    
    
