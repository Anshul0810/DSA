#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int size, int k){
    int ans[size];
    for(int i=0; i<size; i++){
        ans[(i+k)%size] = arr[i];
    }
    cout<<endl;
    cout<<ans[2]<<endl;
    arr = ans;
}

int main(){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int k = 2;
    rotateArray(arr, size, k);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
}