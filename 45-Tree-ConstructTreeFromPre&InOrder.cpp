//running in online compiler
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
int findPosition(int in[], int element,int n){
    for(int i=0; i<n ;i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}
node* constructTree(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n){
    if(preOrderIndex >= n || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    int element = pre[preOrderIndex];
    preOrderIndex++;
    node* temp = new node(element);
    if(inOrderStart == inOrderEnd){
        return temp;
    }
    int position = findPosition(in,element,n);

    temp->left = constructTree(in, pre, preOrderIndex, inOrderStart, position-1, n);
    temp->right = constructTree(in, pre, preOrderIndex, position+1, inOrderEnd, n);

    return temp;
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    int n = 6;
    int preOrderIndex = 0;
    node* root = constructTree(in, pre, preOrderIndex, 0, n-1, n);
    inorder(root);
}