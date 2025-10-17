#include<bits/stdc++.h>
using namespace std;
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
void FindBranches(Node* root, vector<int>& branch){
    if(root == NULL){
        return;
    }
    // if node is not null then append it in vector
    branch.push_back(root->value);
    // if we encounter a leaf node then we simply print that branch
    if(root->left == NULL && root->right == NULL){
        for(int i = 0; i<branch.size(); i++){
            cout<<branch[i]<<" ";
        }
        cout<<endl;
    }
    else{
        FindBranches(root->left, branch);
        FindBranches(root->right, branch);
    }
    // backtracking - remove the current node
    branch.pop_back();
}
void display(Node* root){
    if(root == NULL) return ;
    cout<<root->value<<" ";
    display(root->left);
    display(root->right);
}
int main(){
    cout<<"Name : Khushbu Jain"<<endl;
    cout<<"Roll Number : 23115047"<<endl;
    cout<<"Performed on : 13th October 2025"<<endl;
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
    cout<<"Displaying binary tree : "<<endl;
    display(a);
    cout<<endl;
    cout<<"Branches of the Binary Tree : "<<endl;
    vector<int> branches;
    FindBranches(a, branches);
    return 0;
    /*
    Name : Khushbu Jain
    Roll Number : 23115047
    Performed on : 13th October 2025
    Displaying binary tree :
    1 2 4 5 3 6 7
    Branches of the Binary Tree :
    1 2 4
    1 2 5
    1 3 6
    1 3 7
    */
}