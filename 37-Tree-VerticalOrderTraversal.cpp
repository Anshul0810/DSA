#include<iostream>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
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
void verticalTraversal(node* root){
    map<int,map<int,vector<int> > > nodes;
    queue< pair <node* , pair<int,int> > > q;
    vector<int> ans;
    
    if(root == NULL){
        return;
    }

    q.push(make_pair(root , make_pair(0,0)));
    
    while(!q.empty()){

        pair<node* , pair<int , int> > temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left , make_pair(hd-1,lvl+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right , make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i: nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    verticalTraversal(root);
}

