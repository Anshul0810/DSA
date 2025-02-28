#include<iostream>
#include<queue>
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
int solve(node* root, int &i, int k){
    if(root == NULL){
        return -1;
    }

    int left  = solve(root->left, i, k);
    
    if(left != -1){
        return left;
    }

    i++;
    
    if(i == k){
        return root->data;
    }
    int right = solve(root->right, i, k);
    
}
int main(){
    node* root = NULL;
    cout<<"Enter Element of BST: ";
    takeInput(root);
    int k = 3;
    int i = 0;
    int ans = solve(root, i ,k);
    cout<<"Kth Smallest Element is: "<<ans<<endl;
}