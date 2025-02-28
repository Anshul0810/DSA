#include<iostream>
#include<array>
#include<bits/stdc++.h>
using namespace std;
void allDuplicate(int arr[], int size){

    vector<int> temp = {0,0,0,0,0,0,0,0};
    for(int i=0; i<size; i++){
        int tmp = arr[i];
        temp[tmp]++;
    }
    int siz = temp.size();
    for(int i=0; i<siz; i++){
        if(temp[i] == 2){
            cout<<i<<" ";
        }
    }
}
int main(){
    cout<<"zinda h na"<<endl;
    int arr[8] = {4, 3, 2, 7, 8, 2, 3, 1};
    int size = 8;
    allDuplicate(arr,size);
}