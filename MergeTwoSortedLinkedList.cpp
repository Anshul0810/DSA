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
node* Merge(node* &head1 , node* &head2){
    node* temp = new node(-1);
    node* tail = temp;
    node* head = temp;
    while((head1 != NULL) && (head2 != NULL)){
        if(head1->data < head2->data){
            nodetoinsert(tail,head1->data);   
            head1 = head1->next;
        }
        else{
            nodetoinsert(tail,head2->data);
            head2 = head2->next;
        }        
    }
    if(head1 == NULL){
        nodetoinsert(tail,head2->data);
    }  
    else{
        nodetoinsert(tail,head1->data);
    } 
    node* deletenode = head;
    head = head->next;
    delete deletenode;
    return head;
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
    node* ans = Merge(head1,head2);
    cout<<"Final Linked List: "<<endl;
    print(ans);
}    
