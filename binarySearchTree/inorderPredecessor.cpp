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
int inorderPredecessor(Node* root, Node* p){
    Node* pre = NULL;
    Node* curr = root;
    while(curr){
        if(curr->data < p->data){
            pre = curr;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return pre->data;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(20);
    cout<<inorderPredecessor(root, root->left->right)<<endl;
    return 0;
}