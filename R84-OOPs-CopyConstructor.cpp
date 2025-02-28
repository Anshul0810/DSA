#include<iostream>
using namespace std;

class Hero{
    private:
    int health;
    char level;

    public:
    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    //ab hum banaenge copy constructor *.*
    Hero(Hero &temp){
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout<<"health: "<<health<<endl;
        cout<<"level: "<<level<<endl; 
    }
};

int main(){
    
    Hero Perman(90, 'B');
    Perman.print();

    Hero Michan(Perman);
    Michan.print();


}