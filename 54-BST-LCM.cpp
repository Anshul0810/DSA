#include<iostream>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBSt(node* root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBSt(root->right,data); 
    }
    else{
        root->left = insertIntoBSt(root->left,data);
    }
    return root;
}
void takeInput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBSt(root,data);
        cin>>data;
    }
}

node* lcm(node* root, int i, int j){
    if(root == NULL){
        return NULL;
    }
    node* temp = root;
    if(i < temp->data && j < temp->data){
        temp = temp->left;
    }
    else if(i > temp->data && j > temp->data){
        temp = temp->right;
    }
    else{
        return root;
    }
}

int main(){
    node* root = NULL;
    cout<<"Enter Element of BST: ";
    takeInput(root);
    cout<<"Enter first element: ";
    int i;
    cin>>i;
    cout<<"Enter second element: ";
    int j;
    cin>>j;
    node* temp = lcm(root, i, j);
    cout<<"lcm is: "<<temp->data<<endl;

}