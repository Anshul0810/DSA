#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        } 
        cout<<"Memory free for node with data: "<<value<<endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtTail(Node* &head, Node* &tail, int data){

    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void recursionCall(Node* &head, Node* &curr, Node* &pre){
    
    if(curr == NULL){
        head = pre;
        return;
    }
    Node* forward = curr->next;
    recursionCall(head, forward, curr);
    curr->next = pre;
    curr->prev = forward;
}

void reverse(Node* &head){

    Node* pre = NULL;
    Node* curr = head;
    recursionCall(head, curr, pre); 
}

int main(){
    Node *node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);

    print(head);

    reverse(head);
    print(head);


}