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
node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left: "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right: "<<endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root){

    stack<node*> s;
    queue<node*> q;

    q.push(root);
    while(!q.empty()){

        root = q.front();
        q.pop();
        s.push(root);

        if(root->right){
            q.push(root->right);
        }
        if(root->left){
            q.push(root->left);
        }
    }
    while(!s.empty()){
        root = s.top();
        cout<<root->data<<" ";
        s.pop();
    } 
}
int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"printing level order traversal ouput"<<endl;
    levelOrderTraversal(root);

}

