#include<iostream>
#include<queue>
using namespace std;

int main(){

    int arr[5] = {7, 10, 4, 20, 15};
    int size = 5;
    int k = 4;

    priority_queue<int> maxHeap;

    for(int i=0; i<k; i++){
        maxHeap.push(arr[i]);
    }

    for(int i=k; i<size; i++){
        if(arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    int ans = maxHeap.top();
    cout<<ans;
}