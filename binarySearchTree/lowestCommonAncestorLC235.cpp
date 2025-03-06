#include <iostream>
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

// Function to find the Lowest Common Ancestor (LCA) in a BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }

    // If both p and q are smaller, LCA lies in the left subtree
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // If both p and q are greater, LCA lies in the right subtree
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // If p and q are on different sides or one is root, return root
    return root;
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
    
    // Creating a BST
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Find LCA of nodes with values 5 and 15
    TreeNode* p = root->left->left; // Node with value 5
    TreeNode* q = root->left->right; // Node with value 15

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "LCA not found!" << endl;
    }

    return 0;
}
