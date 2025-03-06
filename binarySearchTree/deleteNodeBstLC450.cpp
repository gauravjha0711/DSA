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

// Function to find the maximum value in the left subtree
int findMax(TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->val;
}

// Function to delete a node from BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == key) {
        // Case 1: Leaf node (No child)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: Only left child
        else if (root->left != NULL && root->right == NULL) {
            TreeNode* child = root->left;
            delete root;
            return child;
        }
        // Case 3: Only right child
        else if (root->left == NULL && root->right != NULL) {
            TreeNode* child = root->right;
            delete root;
            return child;
        }
        // Case 4: Two children (Find max in left subtree)
        else {
            int maximum = findMax(root->left);
            root->val = maximum;
            root->left = deleteNode(root->left, maximum);
            return root;
        }
    } 
    else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } 
    else {
        root->right = deleteNode(root->right, key);
    }
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

// Function to print inorder traversal
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    
    // Insert nodes into BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Delete a node
    root = deleteNode(root, 50);

    cout << "Inorder after deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
