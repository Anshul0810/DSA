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

node* flattenBSTToASortedList(node* root){

    vector<int> inorderVal;
    inorder(root, inorderVal);

    int j = inorderVal.size()-1;

    node* newNode = new node(inorderVal[0]);
    node* curr = newNode;

    for(int i=1; i<j; i++){
        node* temp = new node(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //last step
    curr->right = NULL;
    curr->left = NULL;
    
    return newNode;
} 

int main(){
    node* root = NULL;
    cout<<"Enter Element of BST: ";
    takeInput(root);
    node* temp = flattenBSTToASortedList(root);
    cout<<temp->right->right->right->data;
}