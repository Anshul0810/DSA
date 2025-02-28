#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int arr[1000];
    fill_n(arr,1000,-24);
    for(int i=0; i<1000; i++){
        cout<<arr[i]<<" ";
    }
}