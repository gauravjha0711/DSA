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
void leftViewTraversal(Node* root, int level, vector<int> &leftView){
    if(root==NULL){
        return;
    }
    if(level==leftView.size()){
        leftView.push_back(root->data);
    }
    leftViewTraversal(root->left, level+1, leftView);
    leftViewTraversal(root->right, level+1, leftView);
}
void rightViewTraversal(Node* root, int level, vector<int> &rightView){
    if(root==NULL){
        return;
    }
    if(level==rightView.size()){
        rightView.push_back(root->data);
    }
    rightViewTraversal(root->right, level+1, rightView);
    rightViewTraversal(root->left, level+1, rightView);
}
int main(){
    Node* root = createNode();
    cout<<"Inorder Traversal: ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"Level Order Traversal: "<<endl;
    levelTraversal(root);
    cout<<"Left View Traversal: ";
    vector<int> leftView;
    leftViewTraversal(root, 0, leftView);
    for(int i=0; i<leftView.size(); i++){
        cout<<leftView[i]<<" ";
    }
    cout<<endl;
    cout<<"Right View Traversal: ";
    vector<int> rightView;
    rightViewTraversal(root, 0, rightView);
    for(int i=0; i<rightView.size(); i++){
        cout<<rightView[i]<<" ";
    }
    cout<<endl;
    return 0;
}


//10 20 40 -1 -1 50 70 100 -1 -1 111 -1 -1 80-1 -1 30 -1 60 -1 90 112-1 -1 113 -1 -1