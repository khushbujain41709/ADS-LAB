// Implementation of stack using linked list
#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val = data;
        next = NULL;
    }
};
class stack{
    public:
    node* head;
    stack(){
        head = NULL;
    }
    void push(int val){
        node* neww = new node(val);
        if(head == NULL){
            node* neww = new node(val);
            head = neww;
            return;
        }
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = neww;
        return;
    }
    void pop(){
        if(head == NULL){
            cout<<"UnderFlow"<<endl;
            return;
        }
        node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        return;
    }
    void display(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.display();
}