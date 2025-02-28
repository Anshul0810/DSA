#include<iostream>
using namespace std;

void selectionSort(int arr[], int size){

    for(int i=0; i<size-1; i++){
        int minIndex = i;

        for(int j=i; j<size; j++){

            if(arr[j] < arr[minIndex])
                minIndex = j;  
        }     
        swap(arr[minIndex], arr[i]);
    }
}
int main(){
    int arr[5] = {10, 6, 5, 8, 2};
    int size = 5;
    selectionSort(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

// Use case: work excellently when the size of array is small
// Worst case complexity: O(n^2)
// Best case complexity: O(n^2)
// Space Complexity: O(1)
