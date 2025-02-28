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

void inorder(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

node* inorderToBST(vector<int> &in, int min, int max){

    if(min>max){
        return NULL;
    }

    int  mid = (min+max)/2;
    node* newNode = new node(in[mid]);

    newNode->left = inorderToBST(in, min, mid-1);
    newNode->right = inorderToBST(in, mid+1, max);
    return newNode;
}

vector<int> mergeArray(vector<int> v1, vector<int> v2){
    vector<int> ans(v1.size()+v2.size());

    int i = 0 , j = 0;
    int k = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            ans[k++] = v1[i];
            i++;
        }
        else{
            ans[k++] = v2[j];
            j++;
        }
    }

    while(i<v1.size()){
        ans[k++] = v1[i];
        i++;
    }
    while(j<v2.size()){
        ans[k++] = v2[j];
        j++;
    }
    return ans;
}

node* mergeTwoBST(node* root1, node* root2){

    vector<int> v1;
    inorder(root1, v1);
    vector<int> v2;
    inorder(root2, v2);

    // cout<<"First: ";
    // for(int i=0; i<v1.size(); i++){
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;

    // cout<<"second: ";
    // for(int i=0; i<v2.size(); i++){
    //     cout<<v2[i]<<" ";
    // }
    // cout<<endl;

    vector<int> mergedArray = mergeArray(v1,v2);

    // cout<<"Third: ";
    // for(int i=0; i<mergedArray.size(); i++){
    //     cout<<mergedArray[i]<<" ";
    // }
    // cout<<endl;
    int min = 0;
    int max = mergedArray.size()-1;
    return inorderToBST(mergedArray, min, max);
}
int main(){
    node* root1 = NULL;
    node* root2 = NULL;
    cout<<"Enter Element of BST: ";
    takeInput(root1);
    cout<<"Enter element of second BST: ";
    takeInput(root2);
    node* temp = mergeTwoBST(root1,root2);
    levelOrderTraversal(temp);
}