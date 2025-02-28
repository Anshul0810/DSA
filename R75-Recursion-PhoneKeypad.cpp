#include<bits/stdc++.h>
using namespace std;

void solve(string number, string output, int index, string mapping[], vector<string> &ans){

    if(index >= number.length()){
        ans.push_back(output);
        return;
    }

    int num = number[index] - '0';
    string value = mapping[num];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(number, output, index+1, mapping, ans);
        output.pop_back();
    }

}

int main(){
    string number = "23";
    string output = "";
    vector<string> ans;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(number, output, index, mapping, ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}