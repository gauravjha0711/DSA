#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void printll(Node* head){
    Node* temp = head;
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
void insertStart(Node* &head, Node* &tail, int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}
void insertEnd(Node* &head, Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}
void insertPosition(Node* &head, Node* &tail, int data, int pos){
    if(pos<=1){
        insertStart(head, tail, data);
    }
    else if(pos>=length(head)){
        insertEnd(head, tail, data);
    }
    else{
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node* cur = head;
        while(pos!=1){
            prev = cur;
            cur = cur->next;
            pos--;
        }
        prev->next = newNode;
        newNode->next = cur;
    }
}
void deletePos(Node* &head, Node* &tail, int pos){
    if(head==NULL){
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    if(head==tail){
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    if(pos<=1){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else if(pos>=length(head)){
        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    else{
        Node* prev = NULL;
        Node* cur = head;
        while(pos!=1){
            prev = cur;
            cur = cur->next;
            pos--;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}
int main(){
    //Node a; //Node a is created, Static way of creating object

    // Node* first = new Node(10); //Dynamic way of creating object
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node* head = first;
    // Node* tail = fifth;

    // printll(head);
    // cout<<endl;
    // cout<<"Length of linkedlist: "<<length(head)<<endl;

    // insertStart(head, tail, 60);
    // printll(head);
    // cout<<endl;

    // insertEnd(head, tail, 70);
    // printll(head);
    // cout<<endl;



    Node *head = NULL;
    Node *tail = NULL;
    insertStart(head, tail, 10);
    insertStart(head, tail, 20);
    insertStart(head, tail, 30);
    insertEnd(head, tail, 40);
    insertEnd(head, tail, 50);
    insertEnd(head, tail, 60);
    printll(head);
    cout<<endl;
    insertPosition(head, tail, 70, 6);
    printll(head);
    cout<<endl;


    deletePos(head, tail, 1);
    printll(head);
    cout<<endl;
    deletePos(head, tail, 6);
    printll(head);
    cout<<endl;
    deletePos(head, tail, 3);
    printll(head);
    cout<<endl;
    return 0;
}