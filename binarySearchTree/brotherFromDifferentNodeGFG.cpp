#include <bits/stdc++.h>
using namespace std;

// Definition for a Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to count pairs from two BSTs whose sum equals x
int countPairs(Node* root1, Node* root2, int x) {
    int ans = 0;
    stack<Node*> s1, s2;
    Node* a = root1;
    Node* b = root2;

    while (1) {
        while (a) {
            s1.push(a);
            a = a->left;
        }
        while (b) {
            s2.push(b);
            b = b->right;
        }
        
        if (s1.empty() || s2.empty()) {
            break;
        }

        auto atop = s1.top();
        auto btop = s2.top();
        int sum = atop->data + btop->data;

        if (sum == x) {
            ans++;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if (sum < x) {
            s1.pop();
            a = atop->right;
        }
        else {
            s2.pop();
            b = btop->left;
        }
    }
    return ans;
}

// Function to insert a node in a BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Main function to test the code
int main() {
    Node* root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 3);
    root1 = insert(root1, 7);
    root1 = insert(root1, 2);
    root1 = insert(root1, 4);
    root1 = insert(root1, 6);
    root1 = insert(root1, 8);

    Node* root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 6);
    root2 = insert(root2, 15);
    root2 = insert(root2, 3);
    root2 = insert(root2, 8);
    root2 = insert(root2, 11);
    root2 = insert(root2, 18);

    int x = 16;
    cout << "Number of pairs with sum " << x << ": " << countPairs(root1, root2, x) << endl;

    return 0;
}
