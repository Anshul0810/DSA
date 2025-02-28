#include<iostream>
#include<stack>
using namespace std;
bool CheckRedundant(string &str){
    stack<char> s;
    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];

        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '('){
            s.push(ch);    
        }
        else{
            if(ch == ')'){
                while(s.top() !='('){
                    char top = s.top();
                    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                        return 1;
                    }
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return 0;
}
int main(){
    string str = "((a+b))";
    int ans = CheckRedundant(str);
    if(ans == 1){
        cout<<"No redundant bracket is present"<<endl;
    }
    else{
        cout<<"Redundant bracket is present"<<endl;
    }
}