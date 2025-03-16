#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* findIntersection(Node* head1, Node* head2) {
    unordered_map<int, int> map;
    Node* temp = head2;

    // Count the frequency of elements in head2
    while (temp) {
        map[temp->data]++;
        temp = temp->next;
    }

    Node* head = NULL;
    Node* tail = NULL;
    Node* cur = head1;

    // Traverse head1 and create new list based on intersection
    while (cur) {
        if (map[cur->data] > 0) {
            Node* newNode = new Node(cur->data);
            if (!head) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            map[cur->data]--;  // to avoid duplicates if present
        }
        cur = cur->next;
    }

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
    Node* head = findIntersection(head1, head2);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}