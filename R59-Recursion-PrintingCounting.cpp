#include<iostream>
using namespace std;

void counting(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    counting(n-1);
}
int main(){
    cout<<"Enter no.: ";
    int n;
    cin>>n;
    counting(n);
}