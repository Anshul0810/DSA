#include<iostream>
using namespace std;

class Hero{

    public:
    char level;
    int health;

};

int main(){
    Hero h1;
    h1.health = 100;
    h1.level = 'A';
    cout<<"level: "<<h1.level<<endl;
    cout<<"haelth: "<<h1.health<<endl;
}