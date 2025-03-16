#include <iostream>
using namespace std;

// Node class to define tree nodes
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Count total number of nodes in the tree
int countNode(Node* tree) {
    if (!tree) return 0;
    return 1 + countNode(tree->left) + countNode(tree->right);
}

// Check if the tree is a complete binary tree
bool isComplete(Node* tree, int index, int totalNodes) {
    if (!tree) return true;
    if (index > totalNodes) return false;

    return isComplete(tree->left, 2 * index, totalNodes) &&
           isComplete(tree->right, 2 * index + 1, totalNodes);
}

// Check if the tree follows Max Heap property
bool isMaxOrder(Node* tree) {
    if (!tree) return true;

    if (!tree->left && !tree->right) return true;

    if (tree->left && !tree->right)
        return tree->data >= tree->left->data && isMaxOrder(tree->left);

    if (tree->left && tree->right)
        return tree->data >= tree->left->data &&
               tree->data >= tree->right->data &&
               isMaxOrder(tree->left) &&
               isMaxOrder(tree->right);

    return false;
}

// Check if the binary tree is a Max Heap
bool isHeap(Node* root) {
    int total = countNode(root);
    return isComplete(root, 1, total) && isMaxOrder(root);
}

int main() {
    /*
           10
         /    \
        9      8
       / \    /
      7   6  5
    */

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    if (isHeap(root)) {
        cout << "The binary tree is a Max Heap." << endl;
    } else {
        cout << "The binary tree is NOT a Max Heap." << endl;
    }

    return 0;
}
