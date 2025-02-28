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

int getLength(Node* &head){

    int length = 0;
    Node* temp = head;

    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node* &head, int data){

    Node* temp = new Node(data);
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int data){

    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* nodeToInsert = new Node(data);  
    Node* temp = head; 

    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }  

    //Inserting at last node
    if(temp->next == NULL){
        insertAtTail(head, tail, data);
        return;
    } 

    //Inserting in Middle
    temp->next->prev = nodeToInsert;
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert; 
}

void deleteNode(Node* &head, Node* tail, int position){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* pre = NULL;

    int cnt = 1;
    while(cnt < position){
        pre = curr;
        curr = curr->next;
        cnt++;
    }
    if(curr->next == NULL){
        tail = pre;
        pre->next = NULL;
        tail = pre;
        delete curr;
        return;
    }
    curr->next->prev = pre;
    pre->next = curr->next;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}

int main(){
    Node *node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);

    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, -10);

    insertAtPosition(head, tail, 7, 50);

    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    deleteNode(head, tail, 7);

    print(head);
    
    cout<<"Length: "<<getLength(head)<<endl;


    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
}