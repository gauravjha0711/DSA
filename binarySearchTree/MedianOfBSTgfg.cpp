#include <bits/stdc++.h>
using namespace std;

// Definition for a Binary Search Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal and store elements in a vector
void inorder(Node* root, vector<int> &ans) {
    if (!root) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

// Function to find the median of a BST
float findMedian(Node *root) {
    vector<int> ans;
    inorder(root, ans);
    int n = ans.size();
    
    if (n % 2 != 0) {
        return float(ans[n / 2]);  // Odd case
    } else {
        return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;  // Even case (floating-point division)
    }
}

// Function to insert a node in BST
class BST {
public:
    Node* insert(Node* root, int key) {
        if (!root) return new Node(key);
        if (key < root->data) root->left = insert(root->left, key);
        else root->right = insert(root->right, key);
        return root;
    }
};

// Main function to test the code
int main() {
    BST tree;
    Node* root = NULL;
    
    // Creating BST: [6, 3, 8, 1, 4, 7, 9]
    root = tree.insert(root, 6);
    root = tree.insert(root, 3);
    root = tree.insert(root, 8);
    root = tree.insert(root, 1);
    root = tree.insert(root, 4);
    root = tree.insert(root, 7);
    root = tree.insert(root, 9);

    cout << "Median of BST: " << findMedian(root) << endl;

    return 0;
}
