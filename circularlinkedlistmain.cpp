#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        int val = this->data;
        if(this->next == NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with data: "<<val<<endl;
    }
};
void nodetoinsert(node* &tail,int element,int d){
    if(tail == NULL){
        node* node1 = new node(d);
        tail = node1;
        node1->next = node1;
    }
    else{
        node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        node* temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }  
}    
void print(node* tail){
    node* temp = tail;
    do{
        cout<<tail->data<< " ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}   
void deletenode(node* tail,int d){
    node* pre = tail;
    node* curr = pre->next;
    while(curr->data != d){
        pre = curr;
        curr = curr->next;
    }
    pre->next = curr->next;
    if(tail == curr){
        tail = curr->next;
    }

    //if only one node is present
    /*if(curr == pre){
        tail == NULL;
    }*/
    curr->next = NULL;
    delete curr;
} 
int iscircular(node* &tail){
    node* temp = tail->next;
    if(tail == NULL){
        return 1;
    }
    while(temp != NULL && temp != tail){
        temp = temp->next;
    }
    if(temp == NULL){
        return 0;
    }
    else{
        return 1;
    }
}
bool detectloop(node* &head){
    if(head == NULL){
        return false;
    }
    map<node*,bool> visited;
    node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main(){
    //node* node1 = new node(3);
    node* tail = NULL;
    node* head = NULL;
    //node* head = node1;
    //nodetoinsert(tail,3,3);
    nodetoinsert(tail,3,5); 
    nodetoinsert(tail,5,7);
    nodetoinsert(tail,7,9);
    print(tail);
    cout<<"head: "<<tail->data<<endl;
    if(detectloop(tail)) {
        cout<<"loop is present"<<endl;
    }
    else{
        cout<<"loop is absent"<<endl;
    }
    /*int ans = iscircular(tail);
    /*if(ans == 1){
        cout<<"yess circular"<<endl;
    }
    else{
        cout<<"not a circular LL"<<endl;
    }*/
}   