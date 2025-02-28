#include<iostream>
using namespace std;

void print(int arr[], int size){
    cout<<"Size is: "<<size<<" Array is: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
bool searchInArray(int arr[], int size, int key){

    //base case
    print(arr, size);
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    else{
        searchInArray(arr+1, size-1, key);
    }
}

int main(){
    int arr[6] = {2, 5, 7, 9, 25, 25};
    int size = 6;
    int key = 7;
    if(searchInArray(arr, size, key)){
        cout<<"Found!!!"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}