#include<iostream>
using namespace std;
 
void update(int **q){
    // q = q + 1;
    //kuch change hua -> No

    //*q = *q + 1;
    //kuch change hua -> Yes

    **q = **q + 1;
    //kuch change hua -> Yes
}

int main(){
    int i = 5;
    int *p = &i;
    int **q = &p;

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**q<<endl;

    cout<<endl;
    
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*q<<endl;

    cout<<endl;

    cout<<&p<<endl;
    cout<<q<<endl;

    cout<<endl;

    cout<<"Before: "<<i<<endl;
    cout<<"Before: "<<p<<endl;
    cout<<"Before: "<<q<<endl;
    cout<<endl;
    update(q);
    cout<<"After: "<<i<<endl;
    cout<<"After: "<<p<<endl;
    cout<<"After: "<<q<<endl;

}