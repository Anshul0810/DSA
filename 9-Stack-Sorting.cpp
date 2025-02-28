#include<iostream>
#include<stack>
using namespace std;
void InsertAtRightPosition(stack<int> &s , int num){
    if((!s.empty() && s.top()<num) || (s.empty())){
        s.push(num);
        return;
    }
    int integer = s.top();
    s.pop();
    InsertAtRightPosition(s,num); 
    s.push(integer);    
}
void Sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    Sort(s);
    InsertAtRightPosition(s,num);
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(7);
    s.push(1);
    Sort(s);
    while(s.size() != 0){
        cout<<s.top()<<endl;
        s.pop();
    }
}