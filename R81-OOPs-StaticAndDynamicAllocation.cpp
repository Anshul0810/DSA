#include<iostream>
using namespace std;

class Hero{

    int health;
    char level;

    public:
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }
};

int main(){

    //Static Allocation
    Hero perman;

    perman.setHealth(95);
    perman.setLevel('A-');

    cout<<"Perman health is: "<<perman.getHealth()<<endl;
    cout<<"Perman level is: "<<perman.getLevel()<<endl;



    //Dynamic Allocation
    Hero *michan = new Hero;

    michan->setHealth(100);
    michan->setLevel('A');

    cout<<"Michan health is: "<<(*michan).getHealth()<<endl;
    cout<<"Michan level is: "<<(*michan).getLevel()<<endl;

    cout<<"Michan health is: "<<michan->getHealth()<<endl;
    cout<<"Michan level is: "<<michan->getLevel()<<endl;


}