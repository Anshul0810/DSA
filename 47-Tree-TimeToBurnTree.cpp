#include<iostream>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
#include<map>
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
//create mapping
//return target node
node* createParentMapping(node* root, map<node*, node*> &nodeToParent, int target){
    if(root == NULL){
        return NULL;
    }
    node* result = NULL;

    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp->data == target){
            result = temp;
        }
        if(temp->left){
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return result;
}

int burnTree(node* root, map<node*, node*> &nodeToParent){

    map<node*, bool> visited;
    queue<node*> q;

    int ans = 0;

    q.push(root);
    visited[root] = true;

    while(!q.empty()){

        bool flag = 0;
        int size = q.size();
        for(int i=0; i<size; i++){

            node* temp = q.front(); 
            q.pop();

            if(temp->left && !visited[temp->left]){
                flag = 1;
                q.push(temp->left);
                visited[temp->left] = 1;
            }

            if(temp->right && !visited[temp->right]){
                flag = 1;
                q.push(temp->right);
                visited[temp->right] = 1;
            }

            if(nodeToParent[temp] && !visited[nodeToParent[temp]]){
                flag = 1;
                q.push(nodeToParent[temp]);
                visited[nodeToParent[temp]] = 1;
            }

        }
        if(flag == 1){
            ans++;
        }     
    }
    return ans;
}

int solve(node* root, int target){
    map<node*,node*> nodeToParent;
    node* targetNode = createParentMapping(root,nodeToParent,target);
    int ans = burnTree(targetNode,nodeToParent);
    return ans;
}
int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    cout<<"Enter target node: ";
    int t;
    cin>>t;
    int ans = solve(root,t);
    cout<<"Time is: "<<ans; 
}

