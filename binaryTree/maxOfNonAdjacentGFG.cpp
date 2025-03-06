#include <iostream>
#include <utility> // For pair
#include <algorithm> // For max function

using namespace std;

// Definition of Node using a class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the maximum sum of non-adjacent nodes
pair<int, int> solve(Node* root) {
    if (!root) {
        return {0, 0}; // {Include, Exclude}
    }

    auto left = solve(root->left);
    auto right = solve(root->right);

    // Case 1: Include current node
    int include = root->data + left.second + right.second;

    // Case 2: Exclude current node
    int exclude = max(left.first, left.second) + max(right.first, right.second);

    return {include, exclude};
}

// Function to get the maximum sum of non-adjacent nodes
int getMaxSum(Node* root) {
    auto ans = solve(root);
    return max(ans.first, ans.second);
}

// Driver code
int main() {
    // Creating a sample binary tree:
    /*
          10
         /  \
        1    2
       / \    \
      3   4    5
    */
    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    // Call the function
    cout << "Maximum sum of non-adjacent nodes: " << getMaxSum(root) << endl;

    return 0;
}
