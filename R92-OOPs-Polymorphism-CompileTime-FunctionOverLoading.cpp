#include<iostream>
using namespace std;

class Animal{
    public:
    void func(){
        cout<<"Speaking"<<endl;
    }
};

class Dog: public Animal{
    public:
    void func(){
        cout<<"Barking"<<endl;
    }
};

int main(){
    Dog Gs;
    Gs.func();      //print barking because func(function name) function is present
                    //in Dog class if not present then call the function from parent class
                      
}