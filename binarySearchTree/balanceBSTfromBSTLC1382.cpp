#include <bits/stdc++.h>
using namespace std;

// Definition for a Binary Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal and store elements in a vector
void inorder(TreeNode* root, vector<int> &inAns) {
    if (!root) return;
    inorder(root->left, inAns);
    inAns.push_back(root->val);
    inorder(root->right, inAns);
}

// Function to build a balanced BST from a sorted array
TreeNode* build(vector<int> &inAns, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(inAns[mid]);
    root->left = build(inAns, start, mid - 1);
    root->right = build(inAns, mid + 1, end);
    return root;
}

// Function to balance a BST
TreeNode* balanceBST(TreeNode* root) {
    vector<int> inAns;
    inorder(root, inAns);
    return build(inAns, 0, inAns.size() - 1);
}

// Function to insert a node in a BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Function to print inorder traversal (to verify if BST is balanced)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    
    // Creating an unbalanced BST
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder Traversal of Unbalanced BST: ";
    printInorder(root);
    cout << endl;

    // Balancing the BST
    root = balanceBST(root);

    cout << "Inorder Traversal of Balanced BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
