#include<iostream>
#include<stack>
using namespace std;
int ValidParenthesis(string &str){
    stack<char> s;
    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];

        if(ch == '{' || ch =='[' || ch == '('){
            s.push(ch);
        }
        else{
            if(!s.empty()){

                char top = s.top();
                if((ch == '}' && top == '{') || (ch == ']' && top == '[') || (ch == ')' && top == '(')){
                    s.pop();
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    string str = "{}{()}[]";
    int ans = ValidParenthesis(str);
    if(ans == 0){
        cout<<"InValid Parenthesis"<<endl;
    }    
    else{
        cout<<"Valid Parenthesis"<<endl;
    }
}