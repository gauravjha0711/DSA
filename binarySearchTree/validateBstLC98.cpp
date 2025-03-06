#include <iostream>
#include <climits> // For LLONG_MIN and LLONG_MAX
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function to validate BST using range-based recursion
bool solve(TreeNode* root, long long int lb, long long int ub) {
    if (root == NULL) {
        return true;
    }
    
    if (root->val > lb && root->val < ub) {
        bool left = solve(root->left, lb, root->val);
        bool right = solve(root->right, root->val, ub);
        return left && right;
    }
    
    return false;
}

// Function to check if a binary tree is a valid BST
bool isValidBST(TreeNode* root) {
    return solve(root, LLONG_MIN, LLONG_MAX);
}

// Function to insert a node in BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to print inorder traversal (for testing)
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    
    // Creating a valid BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Check if the tree is a valid BST
    if (isValidBST(root)) {
        cout << "The tree is a Valid BST." << endl;
    } else {
        cout << "The tree is NOT a Valid BST." << endl;
    }

    return 0;
}
