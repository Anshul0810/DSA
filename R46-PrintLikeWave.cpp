#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printInWave(int arr[][3], int i, int j){

    bool num;
    for(int i=0; i<3; i++){
        if(i&1){
            for(int j=2; j>=0; j--){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            for(int j=0; j<3; j++){
                cout<<arr[j][i]<<" ";
            }
        }
        cout<<endl;
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
    printInWave(arr, 3, 3);
}