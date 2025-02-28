#include<iostream>
#include<stack>
using namespace std;
class Stack{
    //properties
    public:
    int top;
    int *arr;
    int size;

    //behavior
    Stack(int size){
        this->size=size;
        arr = new int[size];
        top = -1;
    }

    int push(int element){
        if((size-top) > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Stack st(5);
    st.push(10);
    st.push(5);
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<" "<<endl;
    if(st.isempty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

}