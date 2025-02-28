#include<iostream>
#include<bits/stdc++.h>
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

bool floydCycle(Node* head){

    Node* slow = head;
    Node* fast = head;
    while((fast != NULL) && (fast->next != NULL)){
        
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return true;
        }

    }
    return false;
}

int main(){
    
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    // tail->next = head->next;
    if(floydCycle(head)){
        cout<<"Cycle is Present"<<endl;
    }
    else{
        cout<<"Cycle is not Present"<<endl;
    }
}
