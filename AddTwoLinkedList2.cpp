/*
    BETTER CODE THAN FIRST-----
*/
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
void print(node* &head){
    node* temp = head;
    while(temp != 0){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
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
void nodetoinsert(node* &head,node* &tail,int d){
    node* temp = new node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
node* mainadd(node* &first , node* &second){
    int carry = 0;
    node* anshead = NULL;
    node* anstail = NULL;
    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
        }
        int val2 = 0;
        if(second != NULL){
            val2 = second->data;
        }
        int sum = carry + val1 + val2;
        int digit = sum%10;
        nodetoinsert(anshead,anstail,digit);
        carry =  (sum/10);
        if(first != NULL){
            first = first->next;
        }
        if(second != NULL){
            second = second->next;
        }
    }
    return anshead;
}
node* add(node* &first , node* &second){
    node* first1 = reverse(first);
    node* second1 = reverse(second);
    //cout<<"first head"<<first1->data<<endl;
    node* ans = mainadd(first1,second1);
    node* ans1 = reverse(ans);
    return ans1;
}
int main(){
    node* node1 = new node(7);
    node* node2 = new node(6);
    node* head1 = node1;
    node* tail1 = node1;
    node* head2 = node2;
    node* tail2 = node2;
    nodetoinsert(head1,tail1,5);
    nodetoinsert(head1,tail1,4);
    nodetoinsert(head2,tail2,9);
    nodetoinsert(head2,tail2,8);
    cout<<"initial"<<endl;
    print(head1);
    print(head2);
    node* ans = add(head1,head2);
    cout<<"addtion of two linked list is"<<endl;
    print(ans);

}    
