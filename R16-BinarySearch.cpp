#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int s = 0, e = size-1;
    
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
int main(){
    int even[7] = {7, 9, 1, 2, 3, 5, 8};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 9);
    cout<<"Index of 8 is: "<<evenIndex<<endl;

    int oddIndex = binarySearch(odd, 5, 11);
    cout<<"Index of 8 is: "<<oddIndex<<endl;
}