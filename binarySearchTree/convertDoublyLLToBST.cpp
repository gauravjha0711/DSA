#include <iostream>
#include <queue>
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

// Function to convert Doubly Linked List to Balanced BST
Node* convertDoublyLLToBST(Node* &head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    // Recursively construct the left subtree
    Node* leftAns = convertDoublyLLToBST(head, n / 2);

    // Make the middle node the root
    Node* root = head;
    root->left = leftAns;

    // Move head to the next node
    head = head->right;

    // Recursively construct the right subtree
    root->right = convertDoublyLLToBST(head, n - n / 2 - 1);

    return root;
}

// Function to perform Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->val << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

// Function to count the number of nodes in the Doubly Linked List
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->right;
    }
    return count;
}

int main() {
    // Creating a sorted Doubly Linked List (DLL)
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 8; i++) {
        temp->right = new Node(i);
        temp->right->left = temp; // Correctly setting the left pointer
        temp = temp->right;
    }

    // Count nodes in DLL
    int n = countNodes(head);

    // Convert DLL to BST
    Node* root = convertDoublyLLToBST(head, n);

    // Perform Level Order Traversal on BST
    levelOrderTraversal(root);

    return 0;
}
