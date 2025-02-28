#include<iostream>
using namespace std;
void heapify(int arr[], int size, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= size && arr[largest] < arr[left]){
        largest = left; 
    }
    if(right <= size && arr[largest] < arr[right]){
        largest = right; 
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n){

    int size = n;
    while(size > 1){

        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }  
}
 
int main(){

    int arr[6] = {-1, 55, 53, 54, 52, 50};
    int n = 5;

    heapSort(arr, n);

    cout<<endl;
    cout<<"I'm in"<<endl;

    cout<<"Printing : ";

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
}