#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){

    for(int i=1; i<size; i++){
        int temp = arr[i];

        int j=i-1;
        for(; j>=0; j--){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
            }  
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}
int main(){
     int arr[7] = {10, 1, 7, 6, 14, 9, 5};
    int size = 7;
    insertionSort(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

// Use case: Adaptable algo
// Worst case complexity: O(n^2)
// Best case complexity: O(n)
// Space Complexity: O(1)