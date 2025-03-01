#include <bits/stdc++.h> 
#include<iostream>
#include<queue>
using namespace std;
class Deque
{
    int *arr;
    int size;
    int front;
    int rear; 
public:
    // Initialize your data structure.
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear!= size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;

    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            rear = front = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == size-1){
            front = 0;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if(rear == front){
            rear = front = -1;
        }
        else if(rear =0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }

    }
};
int main(){
    Deque q(3);
    q.pushRear(5);
    q.pushRear(10);
    if(q.isEmpty()){
        cout<<"Deque is empty"<<endl;
    }
    else{
        cout<<"Deque is not empty"<<endl;
    }
    q.pushFront(18);
    cout<<"Front: "<<q.getFront()<<endl;
    cout<<"Rear: "<<q.getRear()<<endl;

    if(q.isFull()){
        cout<<"Deque is full"<<endl;
    }
    else{
        cout<<"Deque is not full"<<endl;
    }

}