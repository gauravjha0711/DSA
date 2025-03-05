#include <iostream>
using namespace std;

// Definition of the Node class
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Helper function to check sum tree property and return sum of subtree
pair<bool, int> checkSumTree(Node* root) {
    if (root == NULL) {
        return {true, 0};  // Empty tree is a sum tree, sum is 0
    }
    if (root->left == NULL && root->right == NULL) {
        return {true, root->data};  // Leaf node is a sum tree
    }

    // Recursively check left and right subtrees
    auto left = checkSumTree(root->left);
    auto right = checkSumTree(root->right);

    // Check if current node satisfies sum tree property
    bool isSumTree = left.first && right.first && (root->data == left.second + right.second);

    // Return whether it's a sum tree and the total sum including current node
    return {isSumTree, left.second + right.second + root->data};
}

// Main function to check if the tree is a sum tree
bool isSumTree(Node* root) {
    return checkSumTree(root).first;
}

// Driver function to test the code
int main() {
    // Creating a sample sum tree
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(2);

    if (isSumTree(root)) {
        cout << "The given tree is a Sum Tree.\n";
    } else {
        cout << "The given tree is NOT a Sum Tree.\n";
    }

    return 0;
}
