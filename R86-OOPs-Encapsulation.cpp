#include<iostream>
using namespace std;

class Student{
    private:
    int age;
    int height;

    public:
    int getAge(){
        return this->age;
    }
};

int main(){
    Student Anshul;
    cout<<Anshul.getAge()<<endl;
}