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
node* solve(node* &first , node* &second){
    node* curr1 = first;
    node* curr2 = second;
    node* temp1 = curr1->next;
    while((temp1 != NULL) && (curr2 != NULL)){
        if((curr1->data <= curr2->data) && (curr2->data <= temp1->data)){
            curr1->next = curr2;       
            node* temp2 = curr2->next;
            curr2->next = temp1;
            curr1 = curr2;
            curr2 = temp2;
        }
        else{
            curr1 = temp1;
            temp1 = temp1->next;
        }
        
            if(temp1 == NULL){
                curr1->next = curr2;
                return first;
            }
    }
    return first;
}
node* merge(node* &head1 , node* &head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data < head2->data){
        return solve(head1,head2);
    }
    else{
        return solve(head2,head1);
    }
}
int main(){
    node* node1 = new node(2);
    node* node2 = new node(1);
    node* head1 = node1;
    node* tail1 = node1;
    node* head2 = node2;
    node* tail2 = node2;
    nodetoinsert(tail1,3);
    nodetoinsert(tail1,5);
    nodetoinsert(tail2,4);
    nodetoinsert(tail2,5);
    cout<<"initial Linked Lists: "<<endl;
    print(head1);
    print(head2);
    node* ans = merge(head1,head2);
    cout<<"final Linked List: "<<endl;
    print(ans);
}    
