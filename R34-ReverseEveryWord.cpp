#include<bits/stdc++.h>
using namespace std;

void reverseEveryWordOfString(string &s){

    int i = 0, j=1;
    while(i <= s.length()){
        for(; j<s.length(); j++){
            if(s[j] == ' '){
                break;
            }
        }
        int index = j;
        j--;

        while(i <= j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        i = index + 1;
        j = i;
    }
}

int main(){
    string s = "hello this is anshul ans I am a goood guy";
    cout<<"Before reversing: "<<s;
    reverseEveryWordOfString(s);
    cout<<"After reversing: "<<s;
}