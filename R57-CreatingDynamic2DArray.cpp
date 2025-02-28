#include<iostream>
using namespace std;

int main(){
    int row;
    int col;
    cout<<"Enter no. row: ";
    cin>>row;
    cout<<"Enter no. col: ";
    cin>>col;
    
    //Creating 2D array
    int **arr = new int*[row];
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    //taking input
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    //printing 2D array
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
    }cout<<endl;
}
