#include <bits/stdc++.h>
using namespace std;

// Definition for a Binary Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a node in BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Helper function for inorder traversal
void inorder(TreeNode* root, vector<int> &ans) {
    if (!root) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// Function to return inorder traversal of the BST
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

// Main function to test the code
int main() {
    TreeNode* root = NULL;

    // Creating BST: [6, 3, 8, 1, 4, 7, 9]
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    // Get inorder traversal
    vector<int> inorder_result = inorderTraversal(root);

    // Print inorder traversal
    cout << "Inorder Traversal: ";
    for (int val : inorder_result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
