#include<bits/stdc++.h>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPallindrome(string s, int length){

    int i = 0, j = length-1;
    while(i <= j){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '1' && s[i] <= '9')){
            if(toLowerCase(s[i]) != toLowerCase(s[j])){
                return 0;
            }
        }
        else{
            i++;
            j--;
        }
    }
    return 1;
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    if(checkPallindrome(s, s.length())){
        cout<<"Pallindrome"<<endl;
    }
    else
        cout<<"Not a pallindrome"<<endl;
}