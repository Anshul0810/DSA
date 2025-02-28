#include<iostream>
using namespace std;
int main(){
    cout<<"Enter a number";
    int n;
    cin>>n;
    int p=2;
    if(n==p){
        cout<<"Given Number is prime Number"<<endl;
    }
    int flag = 1;
    while(p<n){
        if((n%p) == 0){
            flag = 0;
            break;
        }
        else{
            p++;
        }
    }
    if(flag == 0){
        cout<<"Given number is not a prime number"<<endl;
    }
    else{
        cout<<"Given number is prime number"<<endl;
    }
}