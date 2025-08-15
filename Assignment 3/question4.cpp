#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char character;
    Node* next;
    Node(char character){
        this->character = character;
        next = NULL;
    }
};
Node* createLinkedList(int size){
    Node* head = NULL;
    Node* temp = NULL;
    for(int i = 0; i< size; i++){
        cout<<"Enter character "<<i+1<<" : ";
        char c;
        cin>>c;
        Node* newNode = new Node(c);
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
Node* reverse(Node* head){
    // Initialization
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // prev will be new head
    return prev;
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->character<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int size = 4;
    Node* ll = createLinkedList(size);
    display(ll);
    Node* rev = reverse(ll);
    display(rev);
}