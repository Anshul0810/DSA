#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){

    for(int i=1; i<size; i++){
        bool swapped = false;
        for(int j=0; j<size-i; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
                swapped = true;
        }
        if(swapped == false){
            break;
        }
    }
}
int main(){
    int arr[7] = {10, 1, 7, 6, 14, 9, 5};
    int size = 7;
    bubbleSort(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

// Use case: work excellently when the size of array is small
// Worst case complexity: O(n^2)
// Best case complexity: O(n)
// Space Complexity: O(1)