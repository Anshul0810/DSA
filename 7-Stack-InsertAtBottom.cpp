#include<iostream>
#include<stack>
using namespace std; 
void InsertAtBottom(stack<int> &s , int num , int size){
    if(s.empty()){
        s.push(num);
        return;
    }  

    int ch = s.top();
    s.pop();
    InsertAtBottom(s,num,size);
    s.push(ch); 
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(8);
    s.push(9);
    s.push(12);
    s.push(15);
    InsertAtBottom(s,3,s.size());
    while(s.size() != 0){
        cout<<s.top()<<endl;
        s.pop();   
    }
}