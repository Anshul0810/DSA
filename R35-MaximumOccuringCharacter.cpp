#include<bits/stdc++.h>
using namespace std;

char countMaxOccuringCharacter(string s){

    int arr[26] = {0};
    for(int i=0; i<s.length(); i++){

        int number = 0;
        if(s[i] >= 'a' && s[i] <= 'z'){
            number = s[i] - 'a';
        }
        else{
            number = s[i] - 'A';
        }
        arr[number]++;
    }

    int maxIs = arr[0], index = 0;
    for(int i=1; i<26; i++){
        if(arr[i] > maxIs){
            maxIs = arr[i];
            index = i;
        }
    }
    return index + 'a';
}

int main(){
    string s = "System";
    char ans = countMaxOccuringCharacter(s);
    cout<<"answer is: "<<ans<<endl; 
}