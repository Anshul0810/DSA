#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(int arr1[],int size1, int arr2[], int size2){

    vector<int> ans;
    for(int i=0; i<size1; i++){
        int temp = arr1[i];
        for(int j=0; j<size2; j++){
            if(temp == arr2[j]){
                ans.push_back(arr2[j]);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}
int main(){
    int arr1[6] = {1, 2, 2, 2, 3, 4};
    int arr2[5] = {2, 2, 3, 3, 4};
    int size1 = 6;
    int size2 = 5;
    vector<int> ans = intersection(arr1,size1,arr2,size2);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}