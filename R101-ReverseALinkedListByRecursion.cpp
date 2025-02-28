#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int data){

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void recursionCall(Node* &head, Node* curr, Node* prev){

    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    recursionCall(head, forward, curr);
    curr->next = prev;
}

void reverse(Node* &head){

    Node* prev = NULL;                  
    Node* curr = head;
    recursionCall(head, curr, prev); 
}

Node* recursionCall2(Node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* chotaHead = recursionCall2(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

int main(){
    
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtTail(tail, 5);
    insertAtTail(tail, 7);
    insertAtTail(tail, 9);
    print(head);
    Node* result = recursionCall2(head);
    print(result);
}

/*
Iterative Sol
T.C. -> O(n)
S.C. -> O(1)  
*/