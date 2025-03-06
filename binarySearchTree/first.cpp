#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        
    }
}
bool search(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(root->data>target){
        return search(root->left, target);
    }
    else{
        return search(root->right, target);
    }
}
int mini(Node* root){
    Node* temp = root;
    if(root==NULL){
        return -1;
    }
    while(temp->left!=NULL){
        temp= temp->left;
    }
    return temp->data;
}
int maxi(Node* root){
    Node* temp = root;
    if(root==NULL){
        return-1;
    }
    if(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}
Node* create(Node* &root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(root->data>data){
        root->left = create(root->left,data);
    }
    else{
        root->right = create(root->right,data);
    }
    return root;
}
void input(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        create(root,data);
        cin>>data;
    }
} 
int main(){
    Node *root = NULL;
    cout<<"Enter the elements of the tree: ";
    input(root);

    cout<<"Level Order Traversal: ";
    levelOrderTraversal(root);

    int target;
    cout<<"Enter the element to be searched: ";
    cin>>target;
    if(search(root,target)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    cout<<"Minimum element in the tree: "<<mini(root)<<endl;
    cout<<"Maximum element in the tree: "<<maxi(root)<<endl;
}