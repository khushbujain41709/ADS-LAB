#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    string data;
    Node* next;
    Node* prev;
    Node(string data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
class doublyLinkedList{
    public:
    Node* head;
    Node* tail;
    doublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    // question 3
    void InsertAtTail(string s){
        Node* newNode = new Node(s);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode-> prev = tail;
        tail = newNode;
        return;
    }
    void createLinkedList(int size){
        for(int i = 0; i<size; i++){
            cout<<"Enter the value of "<<i+1<<" node : ";
            string x;
            cin>>x;
            InsertAtTail(x);
        }
    }
    // question 2
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    doublyLinkedList dll;
    dll.createLinkedList(5);
    dll.display();
}