#include<iostream>
#include<queue>
using namespace std;
int main(){
    deque<int> d;
    d.push_front(15);
    d.push_back(18);

    cout<<"Front element: "<<d.front()<<endl;
    cout<<"End element: "<<d.back()<<endl;

    d.pop_front();

    cout<<"Front element: "<<d.front()<<endl;
    cout<<"End element: "<<d.back()<<endl;

    if(d.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
}