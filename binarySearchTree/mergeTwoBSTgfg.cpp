#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Node definition for BST
class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to merge two BSTs into a sorted list
vector<int> merge(Node* root1, Node* root2) {
    vector<int> ans;
    stack<Node*> sa, sb;
    Node *a = root1, *b = root2;
    
    while (a || b || !sa.empty() || !sb.empty()) {
        while (a) {
            sa.push(a);
            a = a->left;
        }
        while (b) {
            sb.push(b);
            b = b->left;
        }
        
        if (sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)) {
            auto atop = sa.top();
            sa.pop();
            ans.push_back(atop->data);
            a = atop->right;
        } else {
            auto btop = sb.top();
            sb.pop();
            ans.push_back(btop->data);
            b = btop->right;
        }
    }
    
    return ans;
}

// Function to insert nodes into a BST
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    
    return root;
}

// Function to print a vector
void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    
    // Insert values into first BST
    vector<int> values1 = {10, 5, 15, 2, 7};
    for (int val : values1) {
        root1 = insertBST(root1, val);
    }
    
    // Insert values into second BST
    vector<int> values2 = {12, 3, 6, 20};
    for (int val : values2) {
        root2 = insertBST(root2, val);
    }
    
    // Merge BSTs
    vector<int> mergedResult = merge(root1, root2);
    
    // Print merged sorted values
    printVector(mergedResult);
    
    return 0;
}
