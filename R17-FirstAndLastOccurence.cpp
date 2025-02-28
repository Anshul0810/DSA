#include<iostream>
using namespace std;

int first(int arr[], int size, int key){

    int s = 0, e = size-1;
    pair<int, int> finalAns;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(key == arr[mid]){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}
int last(int arr[], int size, int key){

    int s = 0, e = size-1;
    pair<int, int> finalAns;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(key == arr[mid]){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[8] = {0, 0, 1, 1, 2, 2, 2, 2};
    int ans = first(arr, 8, 2);
    cout<<"First occurence is: "<<ans<<endl;
    int ans1 = last(arr, 8, 2);
    cout<<"last occurence is: "<<ans1;
}