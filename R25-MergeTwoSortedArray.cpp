#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int size1, int size2, int resultarray[]){

    int i = 0;
    int j = 0;
    int index = 0;
    while(i < size1 && j < size2){
        
        if(arr1[i] < arr2[j]){
            resultarray[index++] = arr1[i++];
        }
        else{
            resultarray[index++] = arr2[j++];
        }
    }
    while(i<size1){
        resultarray[index++] = arr1[i++];
    }
    while(j<size2){
        resultarray[index++] = arr2[j++];
    }

}
int main(){
    int arr1[5] = {1, 2, 3, 4, 6};
    int arr2[3] = {3, 5, 7};
    int size1 = 5;
    int size2 = 3;

    int resultarray[size1+size2];
    merge(arr1, arr2, size1, size2, resultarray);

    for(int i=0; i<8; i++){
        cout<<resultarray[i]<<" ";
    }
}