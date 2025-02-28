#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c=1;
    // cout<<endl;
    for(int i=1; i<=n; i++){

        for(int p=1; p<=n-i+1; p++){

            cout<<p;

        }

        for(int j=1; j<i; j++){

            cout<<"*";
            
        }

        for(int q=1; q<i; q++){

            cout<<"*";

        }

        for(int p=5; p>i; p--){

            cout<<p;

        }

        cout<<endl;

    }

    cout<<endl;
}