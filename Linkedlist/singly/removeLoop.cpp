#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertAtEnd(ListNode*& head, int val) {
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

void createLoop(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* temp = head;
    ListNode* loopNode = NULL;
    int count = 1;
    while (temp->next) {
        if (count == pos) loopNode = temp;
        temp = temp->next;
        count++;
    }
    if (loopNode) temp->next = loopNode;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            slow = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}
ListNode* removeLoop(ListNode* head) {
    if (!head || !head->next) return head; // Edge case: Empty list or single node

    ListNode* fast = head;
    ListNode* slow = head;

    // Detect loop using Floyd's Cycle Detection Algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {  // Cycle detected
            slow = head;
            
            // Find the start of the loop
            ListNode* prev = fast;  // To track the last node in the loop
            while (slow != fast) {
                prev = fast; // Store previous node of fast
                fast = fast->next;
                slow = slow->next;
            }
            
            // Break the loop
            prev->next = NULL;
            return head;
        }
    }
    return head; // No cycle found
}

int main() {
    ListNode* head = NULL;
    int n, val, pos;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }
    cout << "Enter the position to create a loop (-1 for no loop): ";
    cin >> pos;
    createLoop(head, pos);
    
    ListNode* cycleNode = detectCycle(head);
    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    cout<<"Removing the loop..."<<endl;

    removeLoop(head);
    cycleNode = detectCycle(head);
    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    return 0;
}