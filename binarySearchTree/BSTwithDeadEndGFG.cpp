#include <bits/stdc++.h>
using namespace std;

// Definition for a Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Helper function to recursively check for dead ends
void solve(Node* root, unordered_map<int, bool> &visited, bool &ans) {
    if (!root) return;
    
    visited[root->data] = 1;

    // If it's a leaf node, check for dead ends
    if (root->left == NULL && root->right == NULL) {
        int xp1 = root->data + 1;
        int xm1 = (root->data - 1 == 0) ? root->data : root->data - 1;

        // Check if both xp1 and xm1 are present in visited
        if (visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()) {
            ans = true;
            return;
        }
    }

    // Recurse for left and right children
    solve(root->left, visited, ans);
    solve(root->right, visited, ans);
}

// Main function to check if there exists a dead end in the binary tree
bool isDeadEnd(Node *root) {
    bool ans = false;
    unordered_map<int, bool> visited;
    solve(root, visited, ans);
    return ans;
}

// Helper function to insert nodes into the Binary Tree
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Main function to test the solution
int main() {
    Node* root = NULL;

    // Construct the tree [50, 30, 20, 40, 70, 60, 80]
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Check for dead end
    if (isDeadEnd(root)) {
        cout << "Dead End Exists" << endl;
    } else {
        cout << "No Dead End" << endl;
    }

    return 0;
}
