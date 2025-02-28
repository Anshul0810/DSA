#include<iostream>
#include<map>
using namespace std;
// class node{
//     public:
//     int data;
//     node* next;
//     node(int d){
//         this->data=d;
//         this->next=NULL;
//     }
//     ~node(){
//         int val = this->data;
//         if(this->next == NULL){
//             delete next;
//             next = NULL;
//         }
//         cout<<"memory is free for node with data: "<<val<<endl;
//     }
// };
// void nodetoinsert(node* &tail,int d){
//     node* temp = new node(d);
//     tail->next = temp;
//     temp->next = NULL;
//     tail = temp;
// }
// void print(node* &head){
//     node* temp = head;
//     while(temp != 0){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }cout<<endl;
// }
// bool iscircular(node* &tail){
//     node* temp = tail->next;
//     cout<<"innnn"<<endl;
//     if(tail == NULL){
//         return true;
//     }
//     while(temp != NULL && temp != tail){
//         temp = temp->next;
//     }
//     if(temp == NULL){
//         return false;
//     }
//     else{
//         return true;
//     }
// }
// bool detectloop(node* &head){
//     if(head == NULL){
//         return false;
//     }
//     map<node*,bool> visited;
//     node* temp = head;
//     while(temp != NULL){
//         if(visited[temp] == true){
//             cout<<"starting element of loop: "<<temp->data<<endl;
//             return true;
//         }
//         visited[temp] = true;
//         temp = temp->next;
//     }
//     return false;
// }
// node* floydcycledetection(node* &head){
//     if(head == NULL){
//         return 0;
//     }
//     node* slow = head;
//     node* fast = head->next;
//     while(fast != NULL){
//         fast = fast->next;
//         if(fast != NULL){
//             fast = fast->next;
//         }
//         slow = slow->next; 
//         if(fast == slow){
//             return slow;
//         }
//     }
//     return 0;
// }
// node* getstartingnode(node* head){
//     cout<<"in"<<endl;
//     node* temp = floydcycledetection(head);
//     node* slow = head;
//     while(temp != slow){
//         temp = temp->next;
//         slow = slow->next;
//     }
//     return slow;
// }
// int main(){
//     node* node1 = new node(3);
//     node* head = node1;
//     node* tail = node1;
//     nodetoinsert(tail,5);
//     nodetoinsert(tail,7);
//     nodetoinsert(tail,9);
//     cout<<"head data: "<<head->data<<endl;
//     cout<<"tail data: "<<tail->data<<endl;
//     //print(head);
//     tail->next = head->next;
    
//     if(floydcycledetection(head)) {
//         cout<<"loop is present"<<endl;
//     }
//     else{
//         cout<<"loop is absent"<<endl;
//     } 
//     cout<<"run kr de bhai"<<endl;
//     node* temp = getstartingnode(head);
//     cout<<"starting node is: "<<temp->data<<endl;
//     /*if(iscircular(head)){
//         cout<<"linked list is circular"<<endl;
//     }
//     else{
//         cout<<"not circular"<<endl;
//     }*/
// }

int main(){
    int *ptr = 0;
    int a = 10;
    *ptr = a;
    cout<<"Value of *ptr is: "<<*ptr<<endl;
}