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

void inorder(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

int twoSumInBST(node* root, int target){

    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0;
    int j = inorderVal.size()-1;

    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target){
            return 1;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
} 

int main(){
    node* root = NULL;
    cout<<"Enter Element of BST: ";
    takeInput(root);
    cout<<"Enter first element: ";
    int i;
    cin>>i;
    int ans = twoSumInBST(root, i);
    if(ans == 1){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
        
}