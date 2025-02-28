#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printSum(int arr[][3], int i, int j){

    for(int j=0; j<3; j++){
        int sum = 0;
        for(int i=0; i<3; i++){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
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
    cout<<"Printing sum col wise: "<<endl;
    printSum(arr, 3, 3);
}