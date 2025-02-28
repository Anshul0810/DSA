#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printInSpiral(int arr[][3], int row, int col){

    int startRow = 0;
    int startCol = 0;
    int endRow = row-1;
    int endCol = col-1;
    int total = row*col;
    int count = 0;

    while(total > count){
        for(int i=startCol; i<=endCol; i++){
            cout<<arr[startRow][i]<<" ";
            count++;
        }
        startRow++;
        

        for(int i=startRow; i<=endRow; i++){
            cout<<arr[i][endCol]<<" ";
            count++;
        }
        endCol--;
        

        for(int i=endCol; i>=startCol; i--){
            cout<<arr[endRow][i]<<" ";
            count++;
        }
        endRow--;
        

        for(int i=endRow; i>=startRow; i--){
            cout<<arr[i][startCol]<<" ";
            count++;
        }
        startCol++;
        
    }

    
}

int main(){
    int arr[3][3];

    cout<<"Enter elements: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Prining array: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<"Printing Like a wave: "<<endl;
    printInSpiral(arr, 3, 3);
}