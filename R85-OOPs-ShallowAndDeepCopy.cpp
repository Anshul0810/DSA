#include<iostream>
using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;
    char*name;

    Hero(){
        cout<<"Simple Constuctor Called"<<endl;
        name = new char[100];
    }

    void setName(char name[]){
        this->name = name;
    }

    void setHealth(int health){
        this->health = health;
    }   

    void setLevel(int level){
        this->level = level;
    }   

    void print(){
        cout<<endl;
        cout<<"[ Name: "<<name<<", ";
        cout<<"Health: "<<health<<", ";
        cout<<"Level: "<<level<<" ]"<<endl<<endl;
    }

};

int main(){

    Hero hero1;
    hero1.setHealth(90);
    hero1.setLevel('B');
    char name[7] = "Anshul";
    hero1.setName(name);
    hero1.print();

    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'Z';
    hero1.print();
    hero2.print();

    hero1.level = 'Z';
    hero1.print();
    hero2.print();


}