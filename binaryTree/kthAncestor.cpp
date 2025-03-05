#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* solve(Node* root, int &k, int node) {
    if (root == NULL) return NULL;

    if (root->data == node) return root;

    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);

    if (left || right) {
        k--;
        if (k == 0) {
            return root;
        }
        return left ? left : right;
    }
    return NULL;
}

int kthAncestor(Node* root, int k, int node) {
    Node* ancestor = solve(root, k, node);
    return (ancestor == NULL || k > 0) ? -1 : ancestor->data;
}
