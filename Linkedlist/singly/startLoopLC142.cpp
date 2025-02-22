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
    return 0;
}