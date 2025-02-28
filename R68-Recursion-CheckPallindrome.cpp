#include<bits/stdc++.h>
using namespace std;

bool checkPallindrom(string s, int i, int j){

    if(i == j){
        return true;
    }
    if(s[i] != s[j]){
        return false;
    }
    if(s[i] == s[j]){
        i++;
        j--;
    }
    checkPallindrom(s, i, j);
}

int main(){
    string s = "booB";
    int i = 0, j = s.length()-1;
    if(checkPallindrom(s, i, j)){
        cout<<"Pallindrome"<<endl;
    }
    else{
        cout<<"Not a Pallindrome"<<endl;
    }
}