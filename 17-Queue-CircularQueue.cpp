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
        qfront = -1;
        rear = -1;
    }

    void push(int element){
        if((qfront == 0 && rear == size-1) || (rear == (qfront-1)%(size-1))){
            cout<<"Queue is full"<<endl;
        }
        else if(qfront == -1){
            qfront = rear = 0;
            arr[rear] = element;
        }
        else if((qfront != 0) && (rear == (size-1))){
            rear = 0;
            arr[rear] = element;
        }
        else{
            rear++;
            arr[rear] = element;
        }
    }

    int pop(){
        if((qfront == rear == -1) || (qfront > rear)){
            cout<<"Queue UnderFlow"<<endl;  
            return -1;
        } 
        else if(qfront == rear){
            qfront = rear = -1;
        }
        else if(qfront == (size-1)){
            qfront = 0;
        }
        else{
            qfront++;
        }
    }

    bool isempty(){
        if((qfront == rear == -1) || (qfront == rear)){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Queue q(5);
    q.push(5);
    q.push(4);
    q.pop();
    if(q.isempty()){
        cout<<"yess"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

}