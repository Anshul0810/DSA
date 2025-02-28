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

void reverse(Node* &head, Node* &tail){

    if(head == NULL || head->next == NULL){
        return;
    }
    Node* prev = NULL;                  
    Node* curr = head;
    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
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
    reverse(head, tail);
    print(head);
}

/*
Iterative Sol
T.C. -> O(n)
S.C. -> O(1)  



*/