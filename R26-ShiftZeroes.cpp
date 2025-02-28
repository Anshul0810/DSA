#include<iostream>
using namespace std;

void merge(int arr[], int size){

    int i = 1;
    int j = 0;
    while(i < size){
        if(arr[i] != 0 && arr[j] == 0){
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if(arr[i] ==0 && arr[j] != 0){
            i++;
            j++;
        }
        else{
            i++;
        }
    }

}
int main(){
    int arr[7] = {1, 0, 4, 0 ,0 , 3, 0};
    int size = 7;
    merge(arr, size);

    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
}