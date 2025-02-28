#include<bits/stdc++.h>
using namespace std;

void removeSubstring(string &s, string p){

    while(s.length() != 0 && s.find(p) < s.length()){
        s.erase(s.find(p), p.length());
    }
}
int main(){
    string s = "daabcbaabcbc";
    string p = "abc";
    removeSubstring(s, p);
    cout<<s;
}