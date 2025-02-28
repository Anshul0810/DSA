#include<iostream>
#include<queue>
#include<stack>
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
void traverseLeft(node* root){
    if( (root == NULL)  || (root->left == NULL && root->right == NULL) ){
        return;
    }
    cout<<root->data<<" ";
    if(root->left){
        traverseLeft(root->left);
    }
    else{
        traverseLeft(root->right);
    }      
}
void traverseLeaf(node* root){
    if(root == NULL){
        return;
    }
    traverseLeaf(root->left);
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    traverseLeaf(root->right);
}
void traverseRight(node* root){
    if( (root == NULL)  || (root->left == NULL && root->right == NULL) ){
        return;
    }
    if(root->left){
        traverseRight(root->right);
    }
    else{
        traverseRight(root->left);
    }
    cout<<root->data<<" ";   
}
void boundaryTraversal(node* root){
    if(root == NULL){
        return;
    }
    traverseLeft(root);
    traverseLeaf(root->left);
    traverseLeaf(root->right);
    traverseRight(root->right);
}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    boundaryTraversal(root);
}

