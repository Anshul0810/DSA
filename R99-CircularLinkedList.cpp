
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memmory is free for node with data: "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* nodeToInsert = new Node(data);
        Node* temp = tail;
        while(temp->data != element){
            temp = temp->next;
        }
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}

void print(Node* tail){
    if(tail == NULL){
        cout<<"Tail id empty"<<endl;
        return;
    }
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int element){
    if(tail == NULL){
        cout<<"List is empty please check again: "<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != element){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        //1 node left 
        if(curr == prev){
            tail = NULL;
        }
        //2 node left
        else if(tail == curr){
            tail = prev;
        }
        
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 3, 5);
    // print(tail);

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    // insertNode(tail, 7, 8);
    // print(tail);

    deleteNode(tail, 5);
    print(tail);



}