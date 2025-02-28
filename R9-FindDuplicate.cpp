#include<iostream>
using namespace std;

int duplicate(int arr[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum = arr[i]^sum;
        cout<<"i "<<i<<sum<<"\n";
    }
    for(int i=1; i<size; i++){
        sum = sum^i;
        cout<<"i2: "<<sum<<"\n";
    }
    return sum;
}
int main(){
    int arr[7] = {2,5,4,3,2,6,1};
    int size = 7;
    int ans = duplicate(arr,size);
    cout<<"Duplicate element is: "<<ans;
}