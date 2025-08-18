#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
// class linkedList{
//     public:
//     Node* head;
// };
Node* createLinkedList(int size){
    Node* head = NULL;
    Node* temp = NULL;
    for(int i = 0; i< size; i++){
        cout<<"Enter the value of node "<<i+1<<" : ";
        int value;
        cin>>value;
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}
Node* appendLinkedLists(Node* &head1, Node* &head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node* temp = head1;
    while(temp-> next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int size1, size2;
    cout<<"Enter size of first linked list : ";
    cin>>size1;
    cout<<"Enter size of second linked list : ";
    cin>>size2;
    // linkedList ll;
    // ll.createLinkedList(size1);
    // ll.createLinkedList(size2);
    Node* ll1 = createLinkedList(size1);
    display(ll1);
    Node* ll2 = createLinkedList(size2);
    display(ll2);
    Node* ll3 = appendLinkedLists(ll1, ll2);
    display(ll3);
}