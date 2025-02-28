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
void solve(node* root , int k , int &count , vector<int> path){

    if(root == NULL){
        return; 
    }
    path.push_back(root->data);

    solve(root->left , k , count , path);
    solve(root->right , k , count , path);

    int size = path.size();
    int sum = 0;
    for(int i=size-1 ; i>=0 ; i--){
        sum = sum + path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();
}
int kSumPath(node* root , int k){
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}
node* kthAncestor(node* root , int n , int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n){
        return root;
    }
    node* leftAns = kthAncestor(root->left,n,k);
    node* rightAns = kthAncestor(root->right,n,k);

    if(leftAns != NULL && rightAns == NULL){
        return;
        k--;
    }


}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    cout<<"Enter node";
    int n;
    cin>>n;
    cout<<"Ancestor";
    int k;
    cin>>k;
    int ans = kthAncestor(root,n,k);
    cout<<"Kth ancestor is: ";
    cout<<ans;

}

