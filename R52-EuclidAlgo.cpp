#include<bits/stdc++.h>
using namespace std;

int euclidhcf(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    while(a != b){
        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    } 
    return a;       
}

int main(){
    int a;
    int b;
    cout<<"Enter a value: ";
    cin>>a;
    cout<<"Enter b value: ";
    cin>>b;
    int ans = euclidhcf(a, b);
    cout<<ans;
}