#include<iostream>
#include<climits>
#include<vector>
using namespace std;
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
Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->value){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}
void kthSmallest(Node* root, int& k, int& ans){
    if(root == NULL || k <= 0){
        return;
    }
    kthSmallest(root->left, k, ans);
    k--;
    if(k == 0){
        ans = root->value;
        return;
    }
    kthSmallest(root->right, k, ans);
}

void kthLargest(Node* root, int& k, int& ans){
    if(root == NULL || k <= 0){
        return;
    }
    kthLargest(root->right, k, ans);
    k--;
    if(k == 0){
        ans = root->value;
        return;
    }
    kthLargest(root->left, k, ans);
}
int main(){
    cout<<"Name : Khushbu Jain"<<endl;
    cout<<"Roll Number : 23115047"<<endl;
    cout<<"Performed on : 3rd November 2025"<<endl;
    int size = 0;
    cout<<"Enter size of array : ";
    cin>>size;
    vector<int> v(size);
    Node* root = NULL;
    for(int i = 0; i<size; i++){
        cin>>v[i];
        root = insert(root, v[i]);
    }
    display(root);
    cout<<endl;

    int k = 3;
    int small = 0;
    int large = 0;

    kthSmallest(root, k, small);
    k = 3; // imp - reset value of k
    kthLargest(root, k, large);

    cout<<"Kth Smallest: "<<small<<endl;
    cout<<"Kth Largest: "<<large<<endl;
    
    return 0;
}