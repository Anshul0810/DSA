// take a array choose 2 minimum element and add them and
// push the result in array in place of two smallest element
// do the same thing until 1 element left and then add all

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4] = {4, 3, 2, 6};

    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<4; i++){
        minHeap.push(arr[i]);
    }
    int ans = 0;
    while(minHeap.size() > 1){
         
        int temp1 = minHeap.top();
        minHeap.pop();
        int temp2 = minHeap.top();
        minHeap.pop();
        int ans1 = temp1 + temp2;
        ans = ans + ans1;
        minHeap.push(ans1);
    }

    int finalAns = ans;
    cout<<finalAns;
}