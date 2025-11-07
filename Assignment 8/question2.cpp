#include<iostream>
#include<climits>
using namespace std;
// Level of Tree = 1 + max(levelOfTree(root->left) , levelOfTree(root->right))
class Node{
    public :
    int value;
    Node* left;
    Node* right;
    Node(int val){
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void display(Node* root){
    if(root == NULL) return ;
    cout<<root->value<<" ";
    display(root->left);
    display(root->right);
}
int level(Node* root){
    if(root == NULL) return 0;
    return (1 + max(level(root->left) , level(root->right)));
}
int main(){
    cout<<"Name : Khushbu Jain"<<endl;
    cout<<"Roll Number : 23115047"<<endl;
    cout<<"Performed on : 3rd November 2025"<<endl;
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    display(a);
    cout<<"Height of tree : "<<level(a) - 1<<endl;
    
    return 0;
}