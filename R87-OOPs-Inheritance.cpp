#include<iostream>
using namespace std;

class Human{

    public:
    int age;
    int height;
    int weight;

    public:
    void setWeight(int w){
        this->weight = w;
    }

    void setAge(int age){
        this->age = age;
    }
};

class Male: public Human{
    public:
    string color;

    public:
    void sleep(){
        cout<<"Male is Sleeping"<<endl;
    }
};

int main(){
    Male Ram;
    cout<<Ram.age<<endl;
    cout<<Ram.weight<<endl;
    cout<<Ram.height;

    cout<<Ram.color<<endl;
    Ram.sleep();
}