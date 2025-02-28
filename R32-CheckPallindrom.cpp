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

bool pallindrom(char name[], int l){
    int i = 0;
    int j = l-1;
    // bool flag = true;
    while(i<=j){
        if(toLowerCase(name[i]) != toLowerCase(name[j])){
            return 0;
        }
        else{
            i++;
            j--;
        }
    }
    return 1;
}

int getlength(char name[]){
    int count = 0;
    for(int i=0; name[i]!='\0'; i++){
        count++;
    }
    return count;
}

int main(){
    char name[20];
    cin>>name;
    int length = getlength(name);
    if(pallindrom(name, length)){
        cout<<"Given string is Pallindrom"<<endl;
    }
    else{
        cout<<"Given string is not a Pallindrom"<<endl;
    }
}