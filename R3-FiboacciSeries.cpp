#include<iostream>
using namespace std;
int main(){
    int n = 10;
    int a = 0;
    int b = 1;
    int sum = 0;
    for(int i = 0; i<n; i++){
        cout<<sum<<" ";
        sum = a+b;
        a=b;
        b=sum;
    }
}