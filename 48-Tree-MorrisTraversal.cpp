//T.C. -> O(n)
//S.C. -> O(1)
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
void morrisTraversal(node* root){
    if(root == NULL){
        return;
    }
    node* curr;
    node* pre; 
}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    morrisTraversal(root);
}

