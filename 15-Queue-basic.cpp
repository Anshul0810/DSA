#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(5);
    cout<<"Front Element is: "<<q.front()<<endl;
    q.push(8);
    q.push(10);
    q.pop();
    cout<<"Size is: "<<q.size()<<endl;
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

}