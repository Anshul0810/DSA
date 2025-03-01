#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int > > &ans){

    if(index >= nums.size()){
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(nums, output, index+1, ans);

    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
}

vector<vector<int> > subset(vector<int> &nums){
    vector<vector<int> > ans; 
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3};
    

    for (int i = 0; i < 3; i++) { 
        for ( 
            auto it = ans[i].begin(); 
            it != ans[i].end(); it++) 
            cout << *it << " "; 
        cout << endl; 
    }

}