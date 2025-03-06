#include <iostream>
#include <queue>
using namespace std;

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

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << node->data << " ";
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
}

Node* makeBst(int inOrder[], int s, int e) {
    if (s > e) {
        return NULL;  // Fix: Return NULL if the range is invalid
    }

    int mid = (s + e) / 2;
    Node* root = new Node(inOrder[mid]);

    // Recursively build left and right subtrees and link them
    root->left = makeBst(inOrder, s, mid - 1);  // Left subtree
    root->right = makeBst(inOrder, mid + 1, e); // Right subtree

    return root;
}

int main() {
    int inOrder[] = {1, 2, 3, 4, 5, 6, 7};  // In-order traversal of the BST
    Node* root = makeBst(inOrder, 0, 6);    // Building the BST
    cout << "Level Order Traversal of the BST is: " << endl;
    levelOrderTraversal(root);  // Perform level order traversal
    return 0;
}
