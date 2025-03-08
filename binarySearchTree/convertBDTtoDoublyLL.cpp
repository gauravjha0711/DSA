#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Function to convert BST to Doubly Linked List
void convertBDTtoDoublyLL(Node* root, Node* &head) {
    if (root == NULL) {
        return;
    }

    // Recursive call for right subtree
    convertBDTtoDoublyLL(root->right, head);

    // Adjust pointers
    root->right = head;
    if (head != NULL) {
        head->left = root;
    }
    head = root; // Move head to current root

    // Recursive call for left subtree
    convertBDTtoDoublyLL(root->left, head);
}

// Function to print Doubly Linked List
void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
    // Constructing a BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    // Convert BST to DLL
    Node* head = NULL;
    convertBDTtoDoublyLL(root, head);

    // Print DLL
    printLL(head);

    return 0;
}
