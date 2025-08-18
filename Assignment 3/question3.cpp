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
// question 3 
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<"("<<temp->character<<" ASCII : "<<(int) temp->character<<")"<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int size = 4;
    Node* ll = createLinkedList(size);
    display(ll);
}