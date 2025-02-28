#include<iostream>
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
node* buildtree(node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert in left: "<<endl;
    root->left = buildtree(root->left);
    cout<<"enter data to insert in right"<<endl;
    root->right = buildtree(root->right);
    return root;
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root = NULL;
    root = buildtree(root);
    //3 2 7 -1 -1 6 -1 -1 5 3 -1 -1 -1
    cout<<"Inorder traversal is: "<<endl;
    inorder(root);
    cout<<"Preorder traversal is: "<<endl;
    preorder(root);
    cout<<"Postorder traversal is: "<<endl;
    postorder(root);
}