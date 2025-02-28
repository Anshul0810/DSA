#include<iostream>
#include<queue>
#include<stack>
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
void buildFromLevelOrderTraversal(node* &root){
    queue<node*> q;
    cout<<"Enter data for root node: ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left: "<<temp->data<<endl;
        int leftNode;
        cin>>leftNode;
        
        if(leftNode != -1){
            temp->left = new node(leftNode);
            q.push(temp->left);
        }
        cout<<"Enter data for right: "<<temp->data<<endl;
        int rightNode;
        cin>>rightNode;
        if(rightNode != -1){
            temp->right = new node(rightNode);
            q.push(temp->right);
        }
    }
}
node* lowestCommonAncestor(node* root , int n1 , int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    node* leftAns = lowestCommonAncestor(root->left , n1 , n2);
    node* rightAns = lowestCommonAncestor(root->right , n1 ,n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else{
        return NULL;
    }
}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    cout<<endl;
    int n2;
    cout<<"Enter First Node: ";
    int n1;
    cin>>n1;
    cout<<"Enter Second Node: ";
    cin>>n2;
    node* ans = lowestCommonAncestor(root,n1,n2);
    cout<<"Lowest Common Ancestor is: "<<ans->data;
}

