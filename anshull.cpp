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
node* middle(node* &head){
    node* slow = head;
    node* fast = head->next;
    while((fast != NULL) && (fast->next != NULL)){
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
node* reverse(node* &head){
    node* curr = head;
    node* pre = NULL;
    node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
    }
    return pre;
}
bool check(node* &head1 , node* &head2){
    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
int main(){
    int flag = 1;
    node* node1 = new node(1);
    node* head = node1;
    node* tail = node1;
    nodetoinsert(tail,2);
    nodetoinsert(tail,3);
    nodetoinsert(tail,2);
    nodetoinsert(tail,1);
    nodetoinsert(tail,11);
    cout<<"initial: ";
    print(head);
    node* ans = middle(head);
    node* temp = ans->next;
    ans->next = reverse(temp);
    cout<<"final: ";
    print(head);
    node* head1 = head;
    node* head2 = ans->next;
    if(check(head1,head2)){
        cout<<"GIVIN LINKED LIST IS PALLINDROME"<<endl;
    }
    else{
        cout<<"GIVIN LINKED LIST IS NOT PALLINDROME"<<endl;
    }
}    
