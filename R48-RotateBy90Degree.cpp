#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateBy90Degrees(int arr[][3], int row, int col){

    int startRow = 0;
    int startCol = 0;
    int endRow = 2;
    int endCol = 2;

    while(startCol <= endCol){
        for(int i=endRow; i>=startRow; i--){
            cout<<arr[i][startCol]<<" ";
        }
        cout<<endl;
        startCol++;
    }   
}

int main(){
    int row = 3;
    int col = 3;
    int arr[row][col];

    cout<<"Enter elements: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Prining array: "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    rotateBy90Degrees(arr, row, col);
}