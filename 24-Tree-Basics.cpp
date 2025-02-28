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
    node* root = NULL;
    root = buildTree(root);
    cout<<"printing level order traversal ouput"<<endl;
    levelOrderTraversal(root);

}

