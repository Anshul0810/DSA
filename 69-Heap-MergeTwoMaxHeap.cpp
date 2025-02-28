//sahi nhi bana h ye
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < size && arr[largest] < arr[left]){
        largest = left; 
    }
    if(right < size && arr[largest] < arr[right]){
        largest = right; 
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr, size, largest);
    }
}

int main(){
    int arr1[6] = {-1, 20, 10, 4, 7, 3};
    int arr2[6] = {-1, 15, 11, 12, 5, 4};
    int size = 5;

    int arr[10];
    arr[0] = -1;

    for(int i=1; i<=size; i++){
        arr[i] = arr1[i];
    }

    for(int i=1; i<=size; i++){
        arr[i+size] = arr2[i];
    }

    for(int i=1; i<=10; i++){
        heapify(arr, 10, i);
    }

}