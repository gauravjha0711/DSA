#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        next=NULL;
    }
    Node(int x){
        data=x;
        next=NULL;
    }
};
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void insertAtEnd(Node*& head, int val){
    Node* newNode = new Node(val);
    if(!head){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
}
void reverse(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
void addOne(Node* &head){
    //reverse the linked list
    reverse(head);
    //process 
    Node* temp=head;
    int carry=1;
    while(temp->next!=NULL){
        int totalSum = temp->data+carry;
        int digit = totalSum%10;
        carry = totalSum/10;
        temp->data=digit;
        temp=temp->next;
        if(carry==0){
            break;
        }
    }
    if(carry!=0){
        int totalSum = temp->data+carry;
        int digit = totalSum%10;
        carry = totalSum/10;
        temp->data=digit;
        if(carry!=0){
            Node* newNode = new Node(carry);
            temp->next=newNode;
        }
    }

    //reverse the linked list
    reverse(head);
}
int main(){
    Node* head = NULL;
    insertAtEnd(head, 9); 
    insertAtEnd(head, 9);
    insertAtEnd(head, 9);
    print(head);

    cout<<"After adding 1: "<<endl;
    addOne(head);
    print(head);
}