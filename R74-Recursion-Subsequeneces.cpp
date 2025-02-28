#include<bits/stdc++.h>
using namespace std;

void solve(string s, vector<string> &ans, int index, string output){

    if(index >= s.size()){
        if(output.size() > 0){
            ans.push_back(output);
        }
        return;
    }
    //exclude
    solve(s, ans, index+1, output);

    //include
    char temp = s[index];
    output.push_back(temp);
    solve(s, ans, index+1, output);
}

int main(){
    string s = "abc";
    vector<string> ans ;
    int index = 0;
    string output = "";
    solve(s, ans, index, output);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}