#include<bits/stdc++.h>
using namespace std;

void reverseString(string &s, int i, int j){

    if(i>j){
        return;
    }
    swap(s[i], s[j]);
    i++;
    j--;
    reverseString(s, i, j);
}

int main(){
    string s = "anshuls";
    cout<<"Before: "<<s<<endl;
    int i=0, j=s.length()-1;
    reverseString(s, i, j);
    cout<<"After: "<<s<<endl;
}