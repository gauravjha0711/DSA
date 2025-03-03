#include<iostream>
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
Node* create(){
    int x;
    cout<<"Enter the data for node: ";
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node *newNode = new Node(x);
    cout<<"Enter left child of "<<x<<endl;
    newNode->left = create();
    cout<<"Enter right child of "<<x<<endl;
    newNode->right = create();
    return newNode;
}
void preOrderTraversal(Node* root){
    //LNR
    if(root==NULL){
        return;
    }
    preOrderTraversal(root->left);
    cout<<root->data<<" ";
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node* root){
    //NLR
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    //LRN
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        cout<<front->data<<" ";
        q.pop();
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
}
void levelOrderTraversal2(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>1){
        Node *front = q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            q.push(NULL);
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
int main(){
    Node *root = create();
    cout<<"Preorder Traversal: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"Inorder Traversal: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"Level Order Traversal: ";
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Level Order Traversal 2: ";
    levelOrderTraversal2(root);
    cout<<endl;
    return 0;
}