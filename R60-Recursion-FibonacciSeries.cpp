#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int smaller = fibonacci(n-2);
    int bigger = fibonacci(n-1);
    int finalAns = smaller + bigger;

    cout<<"Smaller: "<<smaller<<" "<<"Bigger: "<<bigger<<" "<<"FinalAns: "<<finalAns<<" "<<"n: "<<n<<endl;

    return finalAns;
}

int main(){
    int n;
    cout<<"Enter which no. you want: ";
    cin>>n;
    int ans = fibonacci(n);
    cout<<ans;
}