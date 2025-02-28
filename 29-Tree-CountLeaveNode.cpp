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
void countLeaveNode(node* &root,int &cnt){
    if(root == NULL){
        return;
    }
    countLeaveNode(root->left,cnt);
    if(root->left==NULL && root->right == NULL){
        cnt++;
    }
    countLeaveNode(root->right,cnt);
}
int leavenode(node* &root){
    int cnt = 0;
    countLeaveNode(root,cnt);
    return cnt;
}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    int cnt = 0;
    int ans = leavenode(root);
    cout<<"Leave node is:  "<<ans<<endl;
}