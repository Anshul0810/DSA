#include<bits/stdc++.h>
using namespace std;

void addTwoArray(int arr1[], int size1, int arr2[], int size2){

    int i = size1 - 1;
    int j = size2 - 1;
    int carry = 0;
    vector<int> result;
    while(i >= 0 && j >= 0){
        int sum = arr1[i] + arr2[j] + carry;
        int mains = sum % 10;
        result.push_back(mains);
        carry = sum / 10;
        i--;
        j--;
    }
    while(i >= 0){
        int sum = arr1[i] + carry;
        int mains = sum % 10;
        result.push_back(mains);
        carry = sum / 10;
        i--;
    }

    while(j >= 0){
        int sum = arr2[j] + carry;
        int mains = sum % 10;
        result.push_back(mains);
        carry = sum / 10;
        j--;
    }

    for(int i=result.size()-1; i>=0; i--){
        cout<<result[i]<<" ";
    }
}
int main(){
    int arr1[5] = {3, 7, 9, 8, 2};
    int arr2[6] = {5, 3, 8, 6, 9, 7};
    int size1 = 5;
    int size2 = 6;
    addTwoArray(arr1, size1, arr2, size2); 
}