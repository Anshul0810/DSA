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
pair<int, int> predecessorSuccessor(node* root, int key){
    
    //find key
    node* temp = root;
    int pre = -1;
    int succ = -1;

    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pre = temp->data;
            temp = temp->right;
        }
    }

    // prede 
    node* leftTree = temp->left;
    while(leftTree != NULL){
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    //succ
    node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int, int> ans = make_pair(pre, succ);
    return ans;
}
int main(){
    node* root = NULL;
    cout<<"Enter Element of BST: ";
    takeInput(root);
    cout<<"Enter element you want to find predecessor and successor: ";
    int t;
    cin>>t;
    pair<int, int> p = predecessorSuccessor(root,t);
    cout<<"pre is: "<<p.first<<endl;
    cout<<"succ id: "<<p.second;
}