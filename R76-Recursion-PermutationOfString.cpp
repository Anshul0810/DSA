#include<bits/stdc++.h>
using namespace std;

void solve(string input, vector<string> &ans, int index){
    if(index >= input.length()){
        ans.push_back(input);
        return;
    }
    
    for(int i=index; i<input.length(); i++){
        swap(input[i], input[index]);
        solve(input, ans, index+1);
        //backtrack
        swap(input[i], input[index]);
    }
    
}

int main(){
    string input = "abc";
    string output = "";
    vector<string> ans;
    int index = 0;
    solve(input, ans, index);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}