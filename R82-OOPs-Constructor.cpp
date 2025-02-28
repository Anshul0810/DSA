#include<iostream>
using namespace std;

class Hero{

    public:
    Hero(){
        cout<<"Costructor Called"<<endl;
    } //After writing this the default constructor will die 
};

int main(){

    //Statically
    Hero Perman;

    //Dynamically
    Hero *Michan = new Hero;
}