//link-https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbm1qSHR2RVdKZW5zNmNnZHU4NkxrbDVqRm4wZ3xBQ3Jtc0trODdlZHVJVHFaeUZadG16NjdmS21WbkVzS2M1NmZjOTJKcGltcVBtcndYQ2VUOWE2T19RcUllOWJWaUZTMG9xS2ZNeFgtZENXUDFUUjRpY0E5ZWUtSS0zZFplTVNRam1JSHNibGg1ZXdadDdCY0RKNA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Ffirst-negative-integer-in-every-window-of-size-k3345%2F1&v=_gJ3to4RyeQ
#include<iostream>
#include<queue>
using namespace std;
string printFirstNegativeInteger( int A[], int N, int K) {
                                                 
       deque<int> dq;
       string ans;
       
       for(int i =0 ; i<K ; i++){
           if(A[i] < 0){
               dq.push_back(i);
           }
       }
       if(!dq.empty()){
           ans.push_back(A[dq.front()]);
       }
       else{
           ans.push_back(0);
       }
        
        for(int i=K; i<N; i++){
            
            //removal
            if(!dq.empty() && i-dq.front() >= K){
                dq.pop_front();
            }
            
            //addition
            if(A[i] < 0){
                dq.push_back(i);
            }
            
            if(!dq.empty()){
                 ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }      
        }
        return ans;
 }
int main(){
    
    int arr[5] = {-8,2,3,-6,10};
    string ans = printFirstNegativeInteger(arr,5,2);
    cout<<ans<<endl;
}


