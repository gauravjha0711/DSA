#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        next = NULL;
        prev = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void print(Node* head){
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
int length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void insertHead(Node* &head, Node* &tail, int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode; 
    }
}
void insertEnd(Node* &head, Node* &tail, int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertPos(Node* &head, Node* &tail, int data, int pos){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail= newNode;
    }
    else if(pos==1){
        insertHead(head, tail, data);
    }
    else if(pos>length(head)){
        insertEnd(head, tail, data);
    }
    else{
        Node* newNode = new Node(data);
        Node* pre = NULL;
        Node* cur = head;
        while(pos!=1){
            pre = cur;
            cur = cur->next;
            pos--;
        }
        pre->next = newNode;
        newNode->prev = pre;
        newNode->next = cur;
        cur->prev = newNode;
    }
}
void deletePos(Node* &head, Node* &tail, int pos){
    if(head==NULL){
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    else if(head==tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else if(pos==1){
        Node* temp = head;
        head= head->next;
        head->prev = NULL;
        delete temp;
    }
    else if(pos>=length(head)){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else{
        Node* pre = NULL;
        Node* cur = head;
        while(pos!=1){
            pre = cur;
            cur = cur->next;
            pos--;
        }
        Node* newNode = cur->next;
        pre->next = newNode;
        cur->prev = NULL;
        cur->next = NULL;
        newNode->prev = pre;
        delete cur;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertHead(head, tail, 10);
    insertHead(head, tail, 20);
    insertHead(head, tail, 30);
    print(head);
    cout<<endl;

    insertEnd(head, tail, 40);
    insertEnd(head, tail, 50);
    print(head);
    cout<<endl;

    insertPos(head, tail, 60, 3);
    print(head);
    cout<<endl;

    deletePos(head, tail, 3);
    print(head);
    cout<<endl;
    return 0;
}