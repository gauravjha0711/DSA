#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);
    int throughRoot = height(root->left) + height(root->right);

    return max(throughRoot, max(leftDiameter, rightDiameter));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}





// int d=0;
//     int height(TreeNode* root){
//         if(root==nullptr){
//             return 0;
//         }
//         int left =height(root->left);
//         int right =height(root->right);
//         int curr= left+right;
//         d= max(d,curr);
//         return max(left,right)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         // if(root==nullptr){
//         //     return 0;
//         // }
//         height(root);
//         return d;
//     }