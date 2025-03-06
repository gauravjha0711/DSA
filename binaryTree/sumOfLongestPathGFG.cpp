#include <iostream>
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

// Function to find the sum of nodes on the longest path from root to leaf
pair<int, int> height(Node* root) {
    if (!root) {
        return {0, 0}; // {height, sum}
    }

    auto lh = height(root->left);
    auto rh = height(root->right);

    int sum = root->data;

    // If both left and right subtree have the same height, take the path with the max sum
    if (lh.first == rh.first) {
        sum += max(lh.second, rh.second);
    }
    // If left subtree is taller, add its sum
    else if (lh.first > rh.first) {
        sum += lh.second;
    }
    // If right subtree is taller, add its sum
    else {
        sum += rh.second;
    }

    return {max(lh.first, rh.first) + 1, sum}; // Returning {height, max sum}
}

// Function to return the maximum sum of the longest root-to-leaf path
int sumOfLongRootToLeafPath(Node* root) {
    auto ans = height(root);
    return ans.second;
}

// Driver code to test the function
int main() {
    /* Sample Tree:
          4
         / \
        2   5
       / \  / \
      7   1 1  2
     /
    3
    */
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(1);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);

    // Calling function and printing output
    cout << "Sum of nodes on the longest path: " << sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
