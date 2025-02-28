#include<iostream>
using namespace std;

int main(){

    int num = 5;
    int *p = &num;
    cout<<"Value of num: "<<num<<endl;
    //*p is dereference value
    cout<<"Value of num: "<<*p<<endl;
    cout<<"Address of pointer: "<<&p<<endl;
    cout<<"Address of num: "<<&num<<endl;
    cout<<"Address of num: "<<p<<endl;
    cout<<"Increament of num value: "<<*p++<<endl;

    //creating a copy of pointer
    int *q = p;
    cout<<"Address of num: "<<p<<" - "<<q<<endl;
    cout<<"value of num: "<<*p<<" - "<<*q<<endl;

    //point the pointer in 2 steps
    int n = 5;
    int *ptr = 0;
    ptr = &n;

    //changing in the value of number with the help of pointer
    int i = 5;
    int *y = &i;
    cout<<"Before: "<<i<<endl;
    (*y)++;
    cout<<"After: "<<i<<endl;


    // Important concept
    int l = 7;
    int *d = &l;
    cout<<"Before: "<<l<<endl;
    *d = *d + 1;
    cout<<"After: "<<l<<endl;
    cout<<"Address of d (Before): "<<d<<endl;
    d = d + 1;
    cout<<"Address of d (After): "<<d<<endl;
    cout<<"after after: "<<l<<endl;

    // int num = 5;
    // int *ptr = &num;

    // cout<<"Address of ptr: "<<&ptr<<endl;
    // cout<<"Value at ptr: "<<*ptr<<endl;
    // cout<<"Address of num: "<<&num<<endl;
    // cout<<endl;
    // num = num + 1;
    // cout<<"Address of ptr: "<<&ptr<<endl;
    // cout<<"Value at ptr: "<<*ptr<<endl;
    // cout<<"Address of num: "<<&num<<endl;
    // cout<<endl;
    // *ptr = *ptr + 1;
    // cout<<"Address of ptr: "<<&ptr<<endl;
    // cout<<"Value at ptr: "<<*ptr<<endl;
    // cout<<"Address of num: "<<&num<<endl;
    // cout<<endl;
    // ptr = ptr + 1;
    // cout<<"Address of ptr: "<<&ptr<<endl;
    // cout<<"Value at ptr: "<<*ptr<<endl;
    // cout<<"Address of num: "<<&num<<endl;


    // Pointer In Array
    int arr[10] = {5, 9, 15, 6};
    cout<<"Address of the first memory block: "<<arr<<endl;
    cout<<"Address of the first memory block: "<<&arr<<endl;
    cout<<"Address of the first memory block: "<<&arr[0]<<endl;
    cout<<"Value of the first memory block: "<<*arr<<endl;
    cout<<"add of the first memory block by 1: "<<*arr + 1<<endl;
    cout<<"Value of the second memory block: "<<*(arr+1)<<endl;

    int temp[10];
    int *pt = &temp[0];
    cout<<"Size of temp: "<<sizeof(temp)<<endl;
    cout<<"First: "<<sizeof(*temp)<<endl;
    cout<<"Second: "<<sizeof(&temp)<<endl;
    cout<<"Size of ptr: "<<sizeof(pt)<<endl;
    cout<<"Size of first memory block: "<<sizeof(*pt)<<endl;
    cout<<"Size of temp: "<<sizeof(&pt)<<endl;
} 