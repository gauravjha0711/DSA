// #include <iostream>
// using namespace std;

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* pre = NULL;
//         ListNode* cur = head;
//         while (cur != NULL) {
//             ListNode* newNode = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = newNode;
//         }
//         return pre;
//     }
// };

// // Helper function to print the linked list
// void printList(ListNode* head) {
//     while (head != NULL) {
//         cout << head->val << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// int main() {
//     // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);
    
//     cout << "Original List: ";
//     printList(head);
    
//     Solution solution;
//     head = solution.reverseList(head);
    
//     cout << "Reversed List: ";
//     printList(head);
    
//     return 0;
// }






#include <iostream>

using namespace std;

// Definition for singly-linked list using class
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse the linked list
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


//reverse linked list by using recursion
// ListNode* reverseListRecursive(ListNode* head, ListNode* pre = NULL) {
//     if (!head) return pre;
//     ListNode* newNode = head->next;
//     head->next = pre;
//     return reverseListRecursive(newNode, head);
// }


// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original List: ";
    printList(head);
    
    head = reverseList(head);
    
    cout << "Reversed List: ";
    printList(head);
    
    return 0;
}
