#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
pair<bool, int> binaryTreeIsHeap(Node* root){
    if(root==NULL){
        return {true, 0}; 
    }
    pair<bool, int> left = binaryTreeIsHeap(root->left);
    pair<bool, int> right = binaryTreeIsHeap(root->right);
    if(left.first==false || right.first==false){
        return {false, 0};
    }
    if(root->data>left.second && root->data>right.second){
        return {true, root->data};
    }
    return {false, 0};
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    pair<bool, int> ans = binaryTreeIsHeap(root);
    if(ans.first){
        cout<<"The binary tree is a heap"<<endl;
    }
    else{
        cout<<"The binary tree is not a heap"<<endl;
    }
    return 0;
}