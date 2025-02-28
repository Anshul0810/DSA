#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &s, int count , int size){
    cout<<"Size: "<<size<<endl;
    if(count == size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    solve(s,count+1,size);

    s.push(num);
}
void deletemiddleelement(stack<int> &s , int size){
    cout<<"Size: "<<size<<endl;
    int count = 0;
    solve(s ,count,size);
}
int main(){
    stack<int> st;
    st.push(5);
    st.push(8);
    st.push(10);
    st.push(15);
    st.push(20);
    deletemiddleelement(st,st.size());

    // cout<<st.top()<<endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // st.pop();

    while(st.size() != 0){
        cout<<st.top()<<endl;
        st.pop();   
    }

}

