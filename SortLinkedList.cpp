#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        int val = this->data;
        if(this->next == NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with data: "<<val<<endl;
    }
};
void nodetoinsert(node* &tail,int d){
    node* temp = new node(d);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void print(node* &head){
    node* temp = head;
    while(temp != 0){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}
int length(node* &head){
    int len = 0;
    node* temp = head;
    while(temp != NULL){ 
        len++;
        temp = temp->next;
    }
    return len;
}
node* sort(node* &head , int len){
    node* curr = head;
    node* pre = head;
    node* forward = NULL;
    //cout<<"in"<<endl;
    while(curr != NULL){
        if(curr->next->data < curr->data){
            //cout<<"in the loop"<<endl;
            forward = curr->next;
            curr->next = forward->next;
            forward->next = curr;
            pre->next = forward;
            curr = curr->next;
        }
        else{
            curr = curr->next;
        }
    }
    //cout<<"curr data: "<<curr->data<<endl;
    return head;
}
int main(){
    node* node1 = new node(3);
    node* head = node1;
    node* tail = node1;
    nodetoinsert(tail,7);
    nodetoinsert(tail,9);
    nodetoinsert(tail,5);
    /*nodetoinsert(tail,5);
    nodetoinsert(tail,7);
    nodetoinsert(tail,7);
    nodetoinsert(tail,9);*/
    print(head);
    int ans = length(head);
    cout<<"lenght: "<<ans<<endl;
    node* op = sort(head,ans);
    cout<<"op data: "<<op->data<<endl;
    print(op);
}


