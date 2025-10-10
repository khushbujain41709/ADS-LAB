#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class circularLinkedList{
    public:
    Node* head;
    circularLinkedList(){
        head = NULL;
    }
    void InsertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return;
    }
    void createLinkedList(int size){
        for(int i = 0; i<size; i++){
            cout<<"Enter the value of "<<i+1<<" node : ";
            int x;
            cin>>x;
            InsertAtEnd(x);
        }
    }
    void display(int size){
        Node* temp = head;
        for(int i = 0; i<size; i++){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        return;
    }
};
int main(){
    circularLinkedList cll;
    cll.createLinkedList(3);
    cll.display(3);
}