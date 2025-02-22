#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to get the length of the linked list
int length(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to reverse k nodes in a group
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || head->next==NULL || k == 1) {
        return head;
    }
    
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* nextNode = NULL;
    int pos = 0;
    if(length(head)<k){
        return head;
    }

    while (pos < k && cur) {
        nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
        pos++;
    }
    
    if (nextNode) {
        head->next = reverseKGroup(nextNode, k);
    }
    return prev;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a node at the end of the linked list
void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

int main() {
    ListNode* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    
    cout << "Original List: ";
    printList(head);
    
    int k = 3;
    head = reverseKGroup(head, k);
    
    cout << "Reversed in K Groups: ";
    printList(head);
    
    return 0;
}
