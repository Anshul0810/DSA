#include<bits/stdc++.h>
using namespace std;

int countPrime(int n){

    int cnt = 0;
    int prime[n] = {0};

    for(int i=2; i<=n; i++){
        if(prime[i] == 0){
            for(int j=i*i; j<=n; j=j+i){
                prime[j] = 1;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(prime[i] == 0){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n = 100;
    int ans = countPrime(n);
    cout<<"Total number of prime number is: "<<ans<<endl;

}

/* Time Complexity
   => (n/2 + n/3 + n/5 + n/7 + n/11)
   => n(1/2 + 1/3 + 1/5 + 1/7 + 1/11)
   => n(log(log(n)))
*/