#include<bits/stdc++.h>
using namespace std;

void sortIt(int arr[], int size){

    int i = 0, j = size-1;
    while(i<j){
        while((arr[i] == 1 || arr[i] == 0) && i<j){

            i++;
            cout<<"i"<<i<<endl;
        }
        while((arr[j] == 1 || arr[j] == 2) && i<j){
            j--;
            cout<<"j"<<j<<endl;
        }
        if(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
            cout<<"i"<<i<<endl;
            cout<<"j"<<j<<endl;
        }
    }

    int n=0, m=size-1;
    while(n<m){
        while((arr[n] == 1 || arr[n] == 0) && n<m){
            n++;
            cout<<"n"<<n<<endl;
        }
        while((arr[m] == 2) && n<m){
            m--;
            cout<<"m"<<m<<endl;
        }
        if(n<m){
            swap(arr[n],arr[m]);
            n++;
            m--;
            cout<<"n"<<n<<endl;
            cout<<"m"<<m<<endl;
        }
    }
}
int main(){
    int arr[9] = {0,1,2,0,1,2};
    int size = 6;
    sortIt(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}