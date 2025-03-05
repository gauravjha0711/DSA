#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left, *right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Helper function to convert the tree into a sum tree
int sum(Node* root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int lSum = sum(root->left);
    int rSum = sum(root->right);
    int temp = root->data;
    root->data = lSum + rSum;
    return root->data + temp;
}

// Function to convert the given tree into a sum tree
void toSumTree(Node* node) {
    sum(node);
}

// Utility function to print inorder traversal of the tree
void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    
    cout << "Inorder Traversal before converting to Sum Tree: ";
    inorder(root);
    cout << endl;
    
    // Convert to sum tree
    toSumTree(root);
    
    cout << "Inorder Traversal after converting to Sum Tree: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
