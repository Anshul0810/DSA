#include<bits/stdc++.h>
using namespace std;

// void print(int arr[]){
    
//     for(auto i: arr){
//         cout<<i<<" ";

//     }

// }
int firstOccurence(int arr[], int s, int e, int key){

  
    if(s<=e){
        int mid = (s+e)/2;
    
        if((key == arr[mid]) && (key < arr[mid+1] || mid == s-1)){
            return mid;
        }
        if(key < arr[mid]){
            return firstOccurence(arr, s, mid-1, key);
        }
        else{
            return firstOccurence(arr, mid+1, e, key);
        }
    }    
    return -1;
    // else{
    //     return -1;
    // }
}

int main(){
    int arr[8] = {0, 0, 1, 1, 2, 2, 2, 2};
    int size = 8;
    int key = 2;
    int first = firstOccurence(arr, 0, size-1, key);
    cout<<"First index of "<<key<<" is: "<<first<<endl;
}