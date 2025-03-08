#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find inorder successor in BST
int inOrderSuccessor(Node* root, Node* x) {
    Node* succ = NULL;
    Node* curr = root;
    
    while (curr) {
        if (curr->data > x->data) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    
    return (succ != NULL) ? succ->data : -1; // Return -1 if no successor exists
}

// Function to insert a node in the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to find a node with a given value
Node* findNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return findNode(root->left, key);
    }
    return findNode(root->right, key);
}

// Driver code
int main() {
    Node* root = NULL;
    
    // Insert elements into BST
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);

    // Find the node whose successor we need
    Node* x = findNode(root, 2);

    // Call the function
    int successor = inOrderSuccessor(root, x);
    
    // Print result
    cout << "Inorder Successor of " << x->data << " is: " << successor << endl;

    return 0;
}