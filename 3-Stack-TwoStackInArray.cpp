#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
    int top1;
    int top2;
    int *arr;
    int size;

    Stack(int size){
        this->size=size;
        arr = new int[size];
        top1=-1;
        top2=size;
    }

    void push1(int element){
        if(top2-top1>1){
            top1++;
            arr[top1] = element;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    void push2(int element){
        if(top2-top1>1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
    } 

    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }

    int pop2(){
        if(top2<size){
            int temp = arr[top2];
            top2++;
            return temp;
        }
        else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }
};
int main(){
    Stack st1(3);
    Stack st2(3);
    st1.push1(8);
    st1.push1(9);
    st1.push1(10);
    st2.push2(5);
    st2.push2(45);
    st2.push2(65);
    st2.push2(89);
    //cout<<"lo ans yr: "<<st1.pop1();


}