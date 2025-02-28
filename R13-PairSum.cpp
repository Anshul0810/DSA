#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > pairSum(int arr[], int size, int sum){

    vector<vector<int> > ans;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] + arr[j] == size){
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    return ans;
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int sum = 5;
    vector<vector<int> > ans =  pairSum(arr, size, sum);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)
        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}