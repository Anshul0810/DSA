#include<iostream>
using namespace std;

int sumOfArray(int arr[], int size){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    int sum = arr[0];
    sum = sum + sumOfArray(arr + 1, size-1);
    return sum;
}

int main(){
    int arr[6] = {2, 5, 7, 9, 25, 25};
    int size = 6;
    int ans = sumOfArray(arr, size);
    cout<<"Sum of array is: "<<ans<<endl;
}