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

void insertAtHead(Node* &head, int data){

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head){

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reverse(Node* &head){

    

}

int main(){
    
    Node *node1 = new Node(10);
    Node *head = node1;

    insertAtHead(head, 20);
    insertAtHead(head, 30);
    print(head);
    cout<<"head1: "<<head->data<<endl;;
    reverse(head);
    cout<<endl;
    print(head);
    cout<<"head2: "<<head->data<<endl;
}