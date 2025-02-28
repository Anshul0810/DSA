#include<iostream>
using namespace std;

class Hero{
    private:
    int health;
    char level;

    public:
    Hero(int health){
        cout<<"this keyword address: "<<this<<endl;
    }
    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    void print(){
        cout<<level<<endl;
    }

};

int main(){

    //Statically
    Hero Perman(90);
    cout<<"Address of object: "<<&Perman<<endl;

    Hero Michan(100, 'A');
    Michan.print();

}