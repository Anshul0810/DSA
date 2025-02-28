#include<iostream>
#include<stack>
using namespace std;
void InsertAtBottom(stack<int> &s , int size , int num){
    if(s.empty()){
        s.push(num);
        return;
    }  

    int ch = s.top();
    s.pop();
    InsertAtBottom(s,size,num);
    s.push(ch); 
}
void Reverse(stack<int> &s , int size){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    Reverse(s,size);
    InsertAtBottom(s,size,num);
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(8);
    s.push(9);
    s.push(12);
    s.push(15);
    Reverse(s,s.size());
    while(s.size() != 0){
        cout<<s.top()<<endl;
        s.pop();   
    }
}