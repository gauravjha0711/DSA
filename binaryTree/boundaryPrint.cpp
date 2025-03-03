#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* createNode(){
    cout<<"Enter the value of the root node: ";
    int val;
    cin>>val;
    if(val == -1){
        return NULL;
    }
    Node* root = new Node(val);
    cout<<"Enter the value of the left child of "<<val<<": ";
    root->left = createNode();
    cout<<"Enter the value of the right child of "<<val<<": ";
    root->right = createNode();
    return root;
}
void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void levelTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}
void leftBoundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left!=NULL){
        leftBoundary(root->left);
    }
    else{
        leftBoundary(root->right);
    }
}
void leafNodes(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    leafNodes(root->left);
    leafNodes(root->right);
}
void rightBoundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->right!=NULL){
        rightBoundary(root->right);
    }
    else{
        rightBoundary(root->left);
    }
    cout<<root->data<<" ";
}
void boundaryPrint(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    //left boundary
    leftBoundary(root->left);
    //leaf nodes
    leafNodes(root->left);
    leafNodes(root->right);
    //right boundary
    rightBoundary(root->right);
}
int main(){
    Node* root = createNode();
    // cout<<"Inorder Traversal: ";
    // inOrderTraversal(root);
    // cout<<endl;
    cout<<endl;
    cout<<"Level Order Traversal: "<<endl;
    levelTraversal(root);
    cout<<endl;
    
    cout<<"Boundary Print: ";
    boundaryPrint(root);
    cout<<endl;

    return 0;
}


//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80-1 -1 30 -1 60 -1 90 112-1 -1 113 -1 -1