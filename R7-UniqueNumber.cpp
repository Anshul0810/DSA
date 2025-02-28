#include<iostream>
using namespace std;
int unique(int arr[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum = sum^arr[i];
    }
    return sum;
}
int main(){
    int arr[9] = {1, 3, 1, 3, 6, 6, 7, 10, 7};
    int size = sizeof(arr)/sizeof(int);
    int ans = unique(arr, size);
    cout<<ans;
}