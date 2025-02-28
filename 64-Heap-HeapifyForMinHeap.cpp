#include<iostream>
using namespace std;

void heapify(int arr[], int size, int i){

    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < size && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, size, smallest);
    }
}

int main(){
    int arr[7] = {5, 3, 8, 2, 4, 6, 10};
    int n = 7;
    for(int i = (n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }

    cout<<"Output: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}