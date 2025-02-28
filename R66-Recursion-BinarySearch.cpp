#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key){

    int mid = (s+e)/2;
    if(s>e){
        return false;
    }
    if(arr[mid] == key){
        return true;
    }
    if(key > arr[mid]){
        return binarySearch(arr, mid+1, e, key);
    }
    else{
        return binarySearch(arr, s, mid-1, key);
    }
}

int main(){
    int arr[6] = {2, 5, 7, 9, 25, 25};
    int size = 6;
    int key = 1;
    if(binarySearch(arr, 0, size-1, key)){
        cout<<"Found!!!"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}