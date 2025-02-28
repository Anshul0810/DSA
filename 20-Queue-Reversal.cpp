#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reversal(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int num = s.top();
        s.pop();
        q.push(num);
    }
    return;
}
int main(){
   queue<int> q;
   q.push(5);
   q.push(8);
   q.push(10);
   q.push(12);
   q.push(15);
   reversal(q);
   while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
   }

}