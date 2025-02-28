#include<iostream>
using namespace std;

class Monkey{
    public:
    int leg;
    int age;
};

class Human{
    public:
    int speak;
};

class Chimpanzee: public Monkey{

};

class Dog: public Monkey, public Human{

};

int main(){

    Chimpanzee C1;
    cout<<C1.leg<<endl;
    //cout<<C1.speak<<endl;    -> error 404

    Dog GermanSpeaperd;
    cout<<GermanSpeaperd.speak<<endl;
    cout<<GermanSpeaperd.age<<endl;

}