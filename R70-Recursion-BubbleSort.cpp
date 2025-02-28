#include<iostream>
using namespace std;

void bubbleSort(int *arr, int size){

    if(size == 1 || size == 0){
        return;
    }
    for(int i=0; i<size-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, --size);
}

int main(){
    int arr[7] = {10, 1, 7, 6, 14, 9, 5};
    int size = 7;
    cout<<"Before: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    bubbleSort(arr, size);
    cout<<endl;
    cout<<"After: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
