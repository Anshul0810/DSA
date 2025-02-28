#include<iostream>
#include<string>
using namespace std;

void sayDigit(int n){
    if(n == 0){
        return;
    }
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    sayDigit(n/10);
    int digit = n % 10;
    cout<<arr[digit]<<" ";
}
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    sayDigit(n);
}
