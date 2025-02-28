//Runing in online compiler
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
int height(node* &root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left , right)+1;
    return ans;
}
pair<bool , int> isBalancedFast(node* &root){
    if(root == NULL){
        pair<bool , int> p = make_pair(true,0);
        return p; 
    }
    pair<bool , int> left = isBalancedFast(root->left);
    pair<bool , int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool , int> ans;
    ans.second = max(left.second , right.second)+1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;

}
bool isBalanced(node* &root){

    isBalancedFast(root).first;
}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    if(isBalanced(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }
}    