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

int findLength(Node* head){

    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node* middleOfLinkedList(Node* head){

    int length = findLength(head);
    for(int i=0; i<(length/2); i++){
        head = head->next;
    }
    return head;
}

int main(){
    
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    print(head);
    Node* temp = middleOfLinkedList(head);
    cout<<"Middle element of linked list is: "<<temp->data<<endl;
}