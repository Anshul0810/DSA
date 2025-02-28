#include<iostream>
#include<stack>
#include<bits/stdc++.h>
#include<list>
using namespace std;
bool knows(int arr[][2] , int a , int b , int n){
    if(arr[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}
int celebrity(int arr[][2],int n){
    stack<int> s;

    for(int i=0 ; i<n ; i++){
        s.push(i);
    }

    while(s.size() > 1){

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(arr,a,b,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans = s.top();

    //row check
    int zeroCount = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[ans][i] == 0){
            zeroCount++;
        }
    }

    if(zeroCount != n){
        return -1;
    }

    //column check
    int colCount = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i][ans] == 1){
            colCount++;
        }
    }

    if(colCount != n-1){
        return -1;
    }

    return ans;
}
int main(){
    int M[2][2] = {{0,1},
                    {1,0}};
    int n = 2;
    int ans = celebrity(M,n);
    cout<<"Celebrity is "<<ans<<endl;                 
}