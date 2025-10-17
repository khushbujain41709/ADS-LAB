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
bool FindPath(Node* root, vector<int>& path, int key){
    if(root == NULL){
        return false;
    }
    // if node is not null then append it in vector
    path.push_back(root->value);
    if(root->value == key){
        return true;
    }
    if(FindPath(root->left, path, key) || FindPath(root->right, path, key)){
        return true;
    }
    // backtracking - remove the current node
    path.pop_back();
    return false;
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
    int key;
    cout<<"Enter the key to find : ";
    cin>>key;
    vector<int> path;
    bool flag = FindPath(a, path, key);
    if(flag == true){
        cout<<"Key exists in the binary tree. It's path is given as : ";
        for(int i = 0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"Key doesnot exist in the binary tree"<<endl;
    }
    return 0;
}