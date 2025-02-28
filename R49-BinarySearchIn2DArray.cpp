#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[][3], int rows, int cols, int target){


    int start = 0;
    int end = (rows*cols)-1;
    int mid = start + (end-start)/2;
    while(start <= end){
        int element = arr[mid/cols][mid%cols];
        if(element == target){
            return 1;
        }
        if(element > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    } 
    return 0;    
}

int main(){
    int row = 3;
    int col = 3;
    int arr[3][3];

    cout<<"Enter elements: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    int target;
    cout<<"Enter target: ";
    cin>>target;

    cout<<"Prining array: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 

    if(binarySearch(arr, row, col, target)){
        cout<<"Found!!!"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}