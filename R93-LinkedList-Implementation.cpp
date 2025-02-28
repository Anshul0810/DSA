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

int main(){
    /*Node node2(10);
    cout<<"Node1 data: "<<node2.data;*/
    
    Node *node1 = new Node(10);
    cout<<"Node1 data: "<<node1->data<<endl;
    cout<<"Address of Node1: "<<node1->next<<endl;
}