#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateBy90Degrees(int arr[][4], int rows, int cols){

    int row = rows;
    int col = cols;
    for(int i=0; i<row; i++){
        for(int j=0; j<=i; j++){
            swap(arr[i][j], arr[j][i]);
        }  
    } 
    int startCol = 0;
    int endCol = col-1;
    while(startCol <= endCol){
        for(int i=0; i<row; i++){
            swap(arr[i][startCol], arr[i][endCol]);
        }
        startCol++;
        endCol--;
    } 
     
}

int main(){
    int arr[4][4];

    cout<<"Enter elements: "<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Prining array: "<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<"Printing after rotate: "<<endl;
    rotateBy90Degrees(arr, 4, 4);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
}