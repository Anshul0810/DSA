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

    Hero perman;

    perman.setHealth(100);
    perman.setLevel('A');
    
    cout<<"Perman health is: "<<perman.getHealth()<<endl;
    cout<<"Perman level is: "<<perman.getLevel()<<endl;

}