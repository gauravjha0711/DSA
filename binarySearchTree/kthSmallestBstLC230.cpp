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

// Modified kthSmallest function with proper recursion
int kthSmallest(TreeNode* root, int &k) {
    if (root == NULL) {
        return -1;
    }

    // First, search in the left subtree
    int left = kthSmallest(root->left, k);
    // If left returned a value, it means we found the kth smallest in the left subtree
    if (left != -1) {
        return left;
    }

    // Decrease k after visiting the root
    k--;

    // If k is 0, it means we found the kth smallest element
    if (k == 0) {
        return root->val;
    }

    // Otherwise, continue the search in the right subtree
    return kthSmallest(root->right, k);
}

// Function to insert a node in the BST
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
void inorderPrint(TreeNode* root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    TreeNode* root = NULL;
    
    // Creating a BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);

    cout << "Inorder Traversal: ";
    inorderPrint(root);
    cout << endl;

    // Find kth smallest element
    int k = 3;
    cout << "The " << k << "rd smallest element is: " << kthSmallest(root, k) << endl;

    return 0;
}
