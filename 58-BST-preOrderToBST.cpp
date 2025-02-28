//Time Complexity -> O(n)
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
node* build(vector<int> &pre, int  min, int max, int &i){

    if(i >= pre.size()){
        return NULL;
    }
    if(pre[i] < min || pre[i] > max){
        return NULL;
    }

    node* root = new node(pre[i++]);
    root->left = build(pre, min, root->data, i);
    root->right = build(pre, root->data, max, i);
    return root;
}
node* preOrderToBST(vector<int> &pre){
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;
    return build(pre, min, max, i);
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
    vector<int> v;
    for(int i=0; i<5; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    node* temp = preOrderToBST(v);
    levelOrderTraversal(temp);

}