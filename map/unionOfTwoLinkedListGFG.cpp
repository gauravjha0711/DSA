#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
Node* makeUnion(struct Node* head1, struct Node* head2) {
    // code here
    map<int, Node*> map;
    Node* temp = head1;
    while(temp){
        map[temp->data] = temp;
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        map[temp->data] = temp;
        temp = temp->next;
    }
    Node* head = NULL;
    temp = NULL;
    for(auto it=map.begin();it!=map.end();it++){
        if(!head){
            head = it->second;
            temp = head;
        }
        else{
            temp->next = it->second;
            temp = temp->next;
        }
    }
    temp->next = NULL;
    return head;
}
int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);
    head1->next->next->next->next->next->next->next = new Node(8);
    head1->next->next->next->next->next->next->next->next = new Node(9);
    head1->next->next->next->next->next->next->next->next->next = new Node(10);
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(10);
    Node* head = makeUnion(head1, head2);
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}