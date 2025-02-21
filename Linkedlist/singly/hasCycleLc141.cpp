#include <iostream>
#include <map>
using namespace std;

// Definition for singly-linked list using a class
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    map<ListNode*, bool> table;
    ListNode* temp = head;
    while (temp != NULL) {
        if (table[temp]) {
            return true;
        }
        table[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next; // Creating a cycle
    
    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }
    
    return 0;
}
