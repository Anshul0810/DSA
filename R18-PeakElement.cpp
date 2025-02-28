//Peak element in a mountain array
#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int size){

    int s = 0, e = size-1;
    

    while(s<=e){

        int mid = s + (e-s)/2;
        int peak = arr[mid];
        if(peak >= arr[mid+1] && peak >= arr[mid-1]){
            return mid;
        }
        if(peak < arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        
    }
    return -1;
}
int main(){
    int even[7] = {0, 2, 3, 4, 5, 2, 1};

    int evenIndex = peakElement(even, 7);
    cout<<"Index of peak element is: "<<evenIndex<<endl;
}