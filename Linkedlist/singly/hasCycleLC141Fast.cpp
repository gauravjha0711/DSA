#include <iostream>
// #include <map>
using namespace std;

// Definition for singly-linked list using a class
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL){
        fast=fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            return true;
        }
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
