#include<bits/stdc++.h>
using namespace std;

bool checkSortedAndRotated(int arr[], int size){

    int count = 0;
    for(int i=1; i<size; i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }
    if(arr[size-1] > arr[0]){
        count++;
    }
    if(count < 2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int arr[7] = {6, 7, 1, 2, 3, 4, 5};
    int size = 7;
    if(checkSortedAndRotated(arr, size)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}