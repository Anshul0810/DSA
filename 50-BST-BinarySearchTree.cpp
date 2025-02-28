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

void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int presentOrNot(node* root, int target){
    node* temp = root;

    while(temp != NULL){
        if(temp->data == target){
            return true;
        }
        if(target < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
node* minValue(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
node* maxValue(node* root){
    node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
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
node* deleteNode(node* root, int nodeToDelete){
    if(root == NULL){
        return root; 
    }

    if(root->data == nodeToDelete){

        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child
        //leftchild
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        //rightchild
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
        }
    }
    
    if(nodeToDelete < root->data){
        root->left = deleteNode(root->left, nodeToDelete);
        return root;
    }
    else{
        root->right = deleteNode(root->right, nodeToDelete);
        return root;
    }

}
int main(){
    node* root = NULL;
    cout<<"Enter data: ";
    takeInput(root);
    cout<<"Printing a BST: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"inorder traversal: ";
    inOrder(root);
    cout<<endl;
    // cout<<"Enter element you want to search: ";
    // int target;
    // cin>>target;
    // if(presentOrNot(root,target)){
    //     cout<<"Present"<<endl;
    // }
    // else{
    //     cout<<"Not present"<<endl;
    // }
    cout<<"Min value is: "<<minValue(root)->data<<endl;
    cout<<"MAx value is: "<<maxValue(root)->data<<endl;

    root = deleteNode(root, 30);

    cout<<"Printing a BST: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"inorder traversal: ";
    inOrder(root);

}