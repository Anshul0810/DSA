// inputs = [2,1,4,3]  ->
// output = [1,-1,3,-1]

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int Solve(int arr[] , int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=n ; i>=1 ; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr); 
    }
    for(int i=0 ; i<n ; i++){
        cout<<ans[i]<<" ";
    }
    
}
int main(){
    int arr[] = {2,1,4,3};
    int n = 4;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    Solve(arr,n);
    
}