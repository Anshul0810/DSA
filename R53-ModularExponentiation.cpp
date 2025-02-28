#include<bits/stdc++.h>
using namespace std;

int result(int n, int x, int m){

    int finalResult = 1;
    int power = n/2;
    for(int i=0; i<power; i++){
        finalResult = finalResult * x;
    }
    finalResult = finalResult * finalResult;
    if(n%2 != 0){
        finalResult = finalResult * finalResult;
    }
    finalResult = finalResult % m;
    return finalResult;
}

int main(){
    int x, n, m;
    cout<<"x: ";
    cin>>x;
    cout<<"n: ";
    cin>>n;
    cout<<"m: ";
    cin>>m;
    int ans = result(x, n, m);
    cout<<"Answer is: "<<ans<<endl;
}