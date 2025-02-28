#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstKElementOfQueue(queue<int> &q , int k){
    stack<int> s;
    queue<int> qp;
    for(int i=0; i<k; i++){
        int ch = q.front();
        s.push(ch);
        q.pop(); 
    }
    while(!s.empty()){
        int num = s.top();
        q.push(num);
        s.pop();
    }
    for(int i = 0; i < (q.size() - k); i++){
        int ch = q.front();
        q.pop();
        q.push(ch);
    }
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(8);
    int k=4;
    reverseFirstKElementOfQueue(q,k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}