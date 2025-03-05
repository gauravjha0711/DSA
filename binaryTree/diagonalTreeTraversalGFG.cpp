#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to perform diagonal traversal of a binary tree
vector<int> diagonal(Node* root) {
    vector<int> ans;
    queue<Node*> q;

    if (!root) return ans;

    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        while (temp) {
            ans.push_back(temp->data);
            if (temp->left) {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    
    return ans;
}

// Main function to test the implementation
int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    vector<int> result = diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
