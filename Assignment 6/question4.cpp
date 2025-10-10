#include<iostream>
#include<climits>
using namespace std;
// sum of nodes =  root->value + LeftSubTree + RightSubTree
// size of tree =  1 + LeftSubTree + RightSubTree , since every node is counted as 1 node.
// max value of node in a tree = max(root->value , max(maxInTree(root->left), maxInTree(root->right)))
// Level of Tree = 1 + max(levelOfTree(root->left) , levelOfTree(root->right))
class Node{  // This is a TreeNode
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
int levelOfTree(Node* root){
    if(root == NULL) return 0;
    return (1 + max(levelOfTree(root->left) , levelOfTree(root->right)));
}
int main(){
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
    cout<<endl;
    cout<<levelOfTree(a)<<endl;
    return 0;
}