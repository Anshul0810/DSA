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
void insertAtTail(node* &tail , node* &curr){
    tail->next = curr;
    tail = curr;
}
node* sortList(node* &head){
    //creation of dummy nodes
    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneHead = new node(-1);
    node* oneTail = oneHead;
    node* twoHead = new node(-1);
    node* twoTail = twoHead;

    node* curr = head;
    //create separate list for 0s,1s,2s :-
    while(curr != NULL){
        int value = curr->data;

        if(value == 0){
            insertAtTail(zeroTail , curr);
        }
        else if(value == 1){
            insertAtTail(oneTail , curr);
        }
        else{
            insertAtTail(twoTail , curr);
        }
        curr = curr->next;
    }

    //merge 
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setup head
    head = zeroHead->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;

}
int main(){
    node* node1 = new node(2);
    node* head = node1;
    node* tail = node1;
    nodetoinsert(tail,0);
    nodetoinsert(tail,2);
    nodetoinsert(tail,1);
    nodetoinsert(tail,0);
    nodetoinsert(tail,2);
    nodetoinsert(tail,1);
    cout<<"initial LL: ";
    print(head);
    sortList(head);
    cout<<"Final LL: ";
    print(head);
}    
