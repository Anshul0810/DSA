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

Node* reverseInKGroup(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    Node* prev = NULL;                  
    Node* curr = head;
    Node* forward = NULL;
    int tracker = 0;
    while(tracker < k && curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        tracker++;
    }
    if(forward != NULL){
        head->next = reverseInKGroup(curr, k);
    }
    return prev; 
}

int main(){
    
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 4);
    insertAtTail(tail, 3);
    insertAtTail(tail, 7);
    insertAtTail(tail, 9);
    insertAtTail(tail, 2);
    print(head);
    Node* ans = reverseInKGroup(head, 4);
    print(ans);
}


/*
T.C -> O(n)
S.C -> O(n)
*/