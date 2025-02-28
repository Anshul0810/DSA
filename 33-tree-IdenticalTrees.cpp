#include<iostream>
#include<queue>
#include<cmath>
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
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left for: "<<temp->data<<endl;
        int leftNode;
        cin>>leftNode;
        if(leftNode != -1){
            temp->left = new node(leftNode);
            q.push(temp->left);
        }
        cout<<"Enter data for right for: "<<temp->data<<endl;
        int rightNode;
        cin>>rightNode;
        if(rightNode != -1){
            temp->right = new node(rightNode);
            q.push(temp->right);
        }
    }
}
bool identical(node* &root1 , node* &root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    bool left = identical(root1->left , root2->left);
    bool right = identical(root1->right , root2->right);    
    bool value = (root1->data == root2->data);
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
    
}
int main(){
    node* root1 = NULL;
    node* root2 =NULL;
    cout<<"Enter data for first tree: ";
    buildFromLevelOrderTraversal(root1);
    cout<<"Enter data for second tree: ";
    buildFromLevelOrderTraversal(root2);
    if(identical(root1,root2)){
        cout<<"Trees are identical"<<endl;
    }
    else{
        cout<<"Trees are not identical"<<endl;
    }
}    