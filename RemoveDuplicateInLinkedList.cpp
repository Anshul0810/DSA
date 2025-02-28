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
node* removeduplicate(node* &head){
    node* temp = head;
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
                node* curr = temp->next->next;
                node* nodetodelete = temp->next;
                delete(nodetodelete);
                temp->next = curr;
        }    
        else{
            temp = temp->next;
        }
    }
    return head;
}
int main(){
    node* node1 = new node(3);
    node* head = node1;
    node* tail = node1;
    nodetoinsert(tail,5);
    nodetoinsert(tail,7);
    nodetoinsert(tail,5);
    nodetoinsert(tail,7);
    nodetoinsert(tail,7);
    
    nodetoinsert(tail,9);
    print(head);
    //cout<<"head: "<<head->data<<endl;
    removeduplicate(head);
    print(head);
}    