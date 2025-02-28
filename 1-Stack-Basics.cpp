#include<iostream>
#include<stack>
using namespace std;
int main(){

    stack<int> s;
    s.push(2);
    s.push(5);
    s.pop();
    cout<<s.top()<<endl;

    cout<<"Size of Stack: "<<s.size()<<endl;

    if(s.empty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

}
