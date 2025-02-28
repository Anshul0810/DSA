//Peak element in a mountain array
#include<bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int size){

    int s = 0, e = size-1;
    while(s<e){

        int mid = s + (e-s)/2;
        int pivot = arr[mid];
        if(pivot <= arr[mid+1] && pivot < arr[mid-1]){
            return mid;
        }
        if(pivot > arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return -1;
}
int main(){
    int even[7] = {7, 9, 1, 2, 3, 5, 8};

    int evenIndex = getPivot(even, 7);
    cout<<"pivot element at: "<<evenIndex<<endl;


}