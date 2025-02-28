#include<bits/stdc++.h>
using namespace std;

int getlength(char name[]){
    int count = 0;
    for(int i=0; name[i]!='\0'; i++){
        count++;
    }
    return count;
}
void reverseString(char name[], int l){
    int i = 0;
    int j = l-1;
    while(i<=j){
        swap(name[i], name[j]);
        i++;
        j--;
    }
    return;
}
int main(){
    char name[20];
    cin>>name;
    int length = getlength(name);
    reverseString(name, length);
    cout<<name;
}