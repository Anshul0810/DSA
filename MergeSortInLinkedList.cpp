/*
    SORTING BY MERGE SORT
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
node* findmid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* merge(node* left , node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    node* ans = new node(-1);
    node* temp = ans;
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    if(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
node* mergesort(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* mid = findmid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    // call of recursion
    left = mergesort(left);
    right = mergesort(right);

    // merging 
    node* ans = merge(left,right);
    return ans;
}
int main(){
    node* node1 = new node(2);
    node* head = node1;
    node* tail = node1;
    nodetoinsert(tail,8);
    nodetoinsert(tail,5);
    nodetoinsert(tail,6);
    cout<<"initial Linked Lists: "<<endl;
    print(head);
    node* ans = mergesort(head);
    print(ans);
}    
