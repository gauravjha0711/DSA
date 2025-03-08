#include<iostream>
#include<limits.h>
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
class NodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool isBST;
    NodeData(){
        size = 0;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        isBST = true;
    }
};
NodeData* largestBST(Node* root, int &ans){
    if(root==NULL){
        NodeData* temp = new NodeData();
        return temp;
    }
    NodeData* left = largestBST(root->left, ans);
    NodeData* right = largestBST(root->right, ans);
    NodeData* current = new NodeData();
    current->size = left->size + right->size + 1;
    current->minVal = min(root->data, left->minVal);
    current->maxVal = max(root->data, right->maxVal);
    if(left->isBST && right->isBST && root->data > left->maxVal && root->data < right->minVal){
        current->isBST = true;
        ans = max(ans, current->size);
    }
    else{
        current->isBST = false;
    }
    return current;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    int ans = 0;
    largestBST(root, ans);
    cout<<ans<<endl;
    return 0;
}