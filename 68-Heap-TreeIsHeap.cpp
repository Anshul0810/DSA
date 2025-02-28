//kya hamara binary tree heap h kya?
#include<iostream>
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

int countedNode(node* root){
    if(root == NULL){
        return 0;
    }

    int ans = countedNode(root->left) + countedNode(root->right) + 1;
    return ans;
}

bool isCBT(node* root, int index, int nodeCount){

    if(root == NULL){
        return true;
    }

    if(index >= nodeCount){
        return false;
    }
    else{
        bool left = isCBT(root->left, 2*index+1, nodeCount);
        bool right = isCBT(root->right, 2*index+2, nodeCount);
        if(left && right){
            return true;
        }
        else{
            return false;
        }
    }
}

bool isMaxHeap(node* root){

    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->right == NULL){
        if(root->data > root->right->data){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        if(left && right && ((root->data > root->left->data) && (root->data > root->right->data))){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    int nodeCount = countedNode(root);
    int index = 0;
    if(isCBT(root, index, nodeCount) == true && isMaxHeap(root) == true){
        cout<<"Given tree is maxHeap"<<endl;
    }
    else{
        cout<<"Given tree is not a maxHeap"<<endl;
    }
}