//Peak element in a mountain array
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int s, int e, int key){
    
    while(s<=e){

        int mid = s + (e-s)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}

int getPivot(int arr[], int size){

    int s = 0, e = size-1;
    while(s<e){

        int mid = s + (e-s)/2;
        int pivot = arr[mid];
        if(pivot <= arr[mid+1] && pivot < arr[mid-1]){
            return mid;
        }
        if(pivot > arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return -1;
}
int main(){
    int arr[7] = {7, 9, 1, 2, 3, 5, 8};
    cout<<"Enter element you want to search i rotated sorted array: ";
    int key;
    cin>>key;
    int pivotElement = getPivot(arr, 7);
    cout<<"Pivot element is : "<<pivotElement<<endl;
    if(key >= arr[pivotElement] && key <= arr[6]){
        int index = binarySearch(arr, pivotElement, 6, key);
        cout<<"Index or searched element is: "<<index<<endl;
    }
    else{
        int index = binarySearch(arr, 0, pivotElement-1, key);
        cout<<"Index or searched element is: "<<index<<endl;
    }
}