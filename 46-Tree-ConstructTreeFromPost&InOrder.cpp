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
node* constructTree(int in[], int post[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int n){
    if(postOrderIndex < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    int element = post[postOrderIndex];
    postOrderIndex--;
    node* temp = new node(element);
    
    int position = findPosition(in,element,n);
    
    temp->right = constructTree(in, post, postOrderIndex, position+1, inOrderEnd, n);
    temp->left = constructTree(in, post, postOrderIndex, inOrderStart, position-1, n);

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
    int in[] = {4,8,2,5,1,6,3,7};
    int post[] = {8,4,5,2,6,7,3,1};
    int n = 8;
    int postOrderIndex = n-1;
    node* root = constructTree(in, post, postOrderIndex, 0, n-1, n);
    inorder(root);
}