#include <iostream>
#include <vector>
using namespace std;

// Node definition for BST
class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Insert function that also tracks the least greater element (successor)
Node* insert(Node* root, int val, int &succ) {
    if (!root) return new Node(val);
    
    if (root->data <= val) {
        root->right = insert(root->right, val, succ);
    } else {
        succ = root->data;
        root->left = insert(root->left, val, succ);
    }
    
    return root;
}

// Function to find the least greater element for each element in the array
vector<int> findLeastGreater(vector<int>& arr, int n) {
    vector<int> ans(n, -1); // Initialize result with -1
    Node* root = NULL;      // Root of BST
    
    // Process elements from right to left
    for (int i = n - 1; i >= 0; i--) {
        int succ = -1;
        root = insert(root, arr[i], succ);
        ans[i] = succ;
    }
    
    return ans;
}

// Main function
int main() {
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = arr.size();
    
    vector<int> result = findLeastGreater(arr, n);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
