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

void giveInOrder(node* root, vector<int> &inOrder){

    if(root == NULL){
        return;
    }

    giveInOrder(root->left, inOrder);
    inOrder.push_back(root->data);
    giveInOrder(root->right, inOrder); 
}

void fillPreOrder(vector<int> inOrder, priority_queue<int, vector<int>, greater<int> > &minHeap, int sizeOfVector){

    int i = 0;
    while(i <= sizeOfVector){
        minHeap.push(inOrder[i]);
        i++;
    }
    return;
}

void bstToMinHeap(node* root, priority_queue<int, vector<int>, greater<int> > &minHeap){

    vector<int> inOrder;
    giveInOrder(root,inOrder);

    int sizeOfVector = inOrder.size();
    fillPreOrder(inOrder, minHeap, sizeOfVector);
}

int main(){
    node* root = NULL;
    buildFromLevelOrderTraversal(root);
    
    priority_queue<int, vector<int>, greater<int> > minHeap;

    bstToMinHeap(root, minHeap);

    cout<<"Element at top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top: "<<minHeap.top()<<endl;
    minHeap.pop();
}