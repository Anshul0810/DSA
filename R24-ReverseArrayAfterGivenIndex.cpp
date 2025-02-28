#include<iostream>
using namespace std;

void reverse(int arr[], int size, int key){

    int i = key+1;
    int j = size-1;
    while(i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int key = 2;
    reverse(arr, 5, key);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}