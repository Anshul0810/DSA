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

node* inoderToBST(int s, int e, vector<int> &in){
    if(s>e){
        return NULL;
    }

    int  mid = (s+e)/2;
    node* temp = new node(in[mid]);
    temp->left = inoderToBST(s, mid-1, in);
    temp->right = inoderToBST(mid+1, e, in);
    return temp;
}

node* unbalancedBSTToBalancedBST(node* root){

    vector<int> inorderVal;
    inorder(root, inorderVal);

    int s = 0;
    int e = inorderVal.size()-1;
    return inoderToBST(s, e, inorderVal);

} 

void levelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    //end of level 1
    q.push(NULL);

    while(!q.empty()){
        node* node = q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" "; 
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);   
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}
int main(){
    node* root = NULL;
    cout<<"Enter Element of BST: ";
    takeInput(root);
    node* temp = unbalancedBSTToBalancedBST(root);
    levelOrderTraversal(root);
}