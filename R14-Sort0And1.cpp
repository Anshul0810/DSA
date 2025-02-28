#include<bits/stdc++.h>
using namespace std;

void sortIt(int arr[], int size){
    
    int i=0, j=size-1;
    while(i<j){
        while(arr[i] == 0 && i<j){
            i++;
        }
        while(arr[j] == 1 && i<j){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}
int main(){
    int arr[7] = {1, 1, 0, 1, 0, 0, 1};
    int size = 7;
    sortIt(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}