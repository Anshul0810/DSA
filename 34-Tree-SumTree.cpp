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
pair<bool,int> isSumTree(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTree(root->left);
    pair<bool,int> rightAns = isSumTree(root->right);

    bool left = leftAns.first;
    bool rught = rightAns.first;
    bool condn = root->data == leftAns.second + rightAns.second;

    pair<bool,int> ans;

    if(left && right && condn){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }
    return ans;
}
bool sum(node* root){
    isSumTree(root).first;   
}
int main(){
    node* root = NULL;
    cout<<"Enter data for tree: ";
    buildFromLevelOrderTraversal(root);
    if(sum(root)){
        cout<<"yess"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}    