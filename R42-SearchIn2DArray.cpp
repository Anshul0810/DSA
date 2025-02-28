#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3][4];

    cout<<"Enter elements: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Prining array: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 

    cout<<"Enter the element to be search: ";
    int target;
    cin>>target;
    int flag = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(target == arr[i][j]){
                flag = 1;
            }
        }
    }
    if(flag == 0){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found!!!!"<<endl;
    }

}