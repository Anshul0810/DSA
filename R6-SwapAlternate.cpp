#include<iostream>
using namespace std;
void swap1(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1 < size){
            swap(arr[i],arr[i+1]);
        }
        
    }
    for(int p=0; p<size; p++){
        cout<<arr[p]<<" ";
    }
}
int main(){
    int arr[7] = {4,3,9,7,1,15, 19};
    int size = sizeof(arr)/sizeof(int);
    cout<<"Size of array: "<<size;
    cout<<"\n";
    swap1(arr,size);
}