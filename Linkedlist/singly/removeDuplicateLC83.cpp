#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete duplicates from a sorted linked list
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* temp = head;
    while (temp && temp->next) {
        if (temp->val == temp->next->val) {
            ListNode* newNode = temp->next;
            temp->next = newNode->next;
            delete newNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
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
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    insert(head, 4);
    insert(head, 4);
    insert(head, 5);
    
    cout << "Original List: ";
    printList(head);
    
    head = deleteDuplicates(head);
    
    cout << "List after removing duplicates: ";
    printList(head);
    
    return 0;
}
