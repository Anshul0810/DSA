#include<iostream>
#include<queue>
using namespace std;
class Queue{
    public:
    int *arr;
    int size;
    int qfront;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void push(int element){
        if(rear<size){
            arr[rear] = element;
            rear++;
        }
        else{
            cout<<"Queue OverFlow"<<endl;
        }
        
    }

    int pop(){
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return qfront;
        }
    }

    int front(){
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    bool isempty(){
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }


};
int main(){
    Queue q(5);
    q.push(1);
    cout<<"Front is: "<<q.front()<<endl;
    q.push(2);
    q.pop();
    if(q.isempty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue if not empty"<<endl;
    }
}