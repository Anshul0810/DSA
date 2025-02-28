#include<iostream>
using namespace std;

class A{

    public:
    void func(){
        cout<<"First Function"<<endl;
    }
    void func(int a){
        cout<<"Second Function"<<endl;
    }
};

int main(){
    A obj;
    obj.func();
    obj.func(2);
}