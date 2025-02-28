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
    
    stack<node*> s;
    node* curr = root;
    while(curr != NULL || (!s.empty())){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}
void preorder(node* root){
    cout<<"I'm in"<<endl;
    node* curr = root;
    stack<node*> s;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            cout<<curr->data<<" ";
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}
void postorder(node* root){
    cout<<"I'm in"<<endl;
    node* curr = root;
    stack<node*> s;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        curr = curr->right;
        if(curr == NULL){
            curr = s.top();
        }
        cout<<curr->data<<" ";
        s.pop();
        curr = s.top();
    }
}
int main(){
    node* root = NULL;
    root = buildtree(root);
    //3 2 7 -1 -1 6 -1 -1 5 3 -1 -1 -1
    cout<<"Inorder traversal is: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal is: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal is: ";
    postorder(root);
}