#include <iostream>
using namespace std;

// Definition for singly-linked list using a class
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNodeFast(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* newNode = cur->next;
        cur->next = pre;
        pre = cur;
        cur = newNode;
    }
    return pre;
}

bool compare(ListNode* head, ListNode* head2) {
    while (head != NULL && head2 != NULL) {
        if (head->val != head2->val) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    ListNode* middle = middleNodeFast(head);
    ListNode* head2 = reverseList(middle);
    
    return compare(head, head2);
}

// Function to insert a node at the end of the linked list
void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = NULL;
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertNode(head, val);
    }
    
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    
    return 0;
}
