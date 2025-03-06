#include <iostream>

using namespace std;

// Definition of TreeNode using a class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to flatten the binary tree into a linked list
void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* pre = curr->left;
            // Find the rightmost node in the left subtree
            while (pre->right) {
                pre = pre->right;
            }
            // Connect the rightmost node to the current right subtree
            pre->right = curr->right;
            // Move left subtree to right
            curr->right = curr->left;
            curr->left = nullptr;
        }
        // Move to the next right node
        curr = curr->right;
    }
}

// Function to print the flattened tree as a linked list
void printFlattenedTree(TreeNode* root) {
    while (root) {
        cout << root->val << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // Creating the binary tree: [1,2,5,3,4,null,6]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);  // Flatten the tree

    printFlattenedTree(root);  // Print the output

    return 0;
}
