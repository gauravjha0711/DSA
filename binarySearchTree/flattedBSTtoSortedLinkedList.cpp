#include <iostream>
using namespace std;

// Definition of Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert function for BST
Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Helper function for in-order traversal to flatten BST
void in(Node* root, Node*& prev) {
    if (root == NULL) {
        return;
    }
    in(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    in(root->right, prev);
}

// Function to flatten BST into a right-skewed linked list
Node* flatten(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return root;
    }
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    in(root, prev);
    prev->left = prev->right = NULL;
    root = dummy->right;
    delete dummy;
    return root;
}

// Main function
int main() {
    Node* root = NULL;
    
    // Insert values into BST
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = insertBST(root, val);
    }

    // Flatten the BST
    Node* ans = flatten(root);
    
    // Print flattened BST
    while (ans != NULL) {
        cout << ans->data << " ";
        ans = ans->right;
    }

    return 0;
}
