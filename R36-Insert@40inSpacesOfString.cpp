#include<bits/stdc++.h>
using namespace std;

void inserts(string &s, string &temp){

    int length = s.length();
    for(int i=0; i<length; i++){
        if(s[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(s[i]);
        }
    }
}
int main(){
    string s = "Hey My Name is Anshul Singh";
    string temp = "";
    inserts(s, temp);
    cout<<temp;
}