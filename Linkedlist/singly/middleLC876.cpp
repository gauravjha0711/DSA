#include <iostream>

using namespace std;

// Definition for singly-linked list node using a class
class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor to initialize a node
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle node of a linked list
// ListNode* middleNode(ListNode* head) {
//         int count = 0;
//         ListNode* temp = head;

//         // First pass: count the number of nodes in the list
//         while (temp != nullptr) {
//             count++;
//             temp = temp->next;
//         }

//         // Calculate the position of the middle node
//         int pos = (count / 2) + 1;
//         int curPos = 1;
//         ListNode* temp2 = head;

//         // Second pass: traverse to the middle node
//         while (curPos != pos) {
//             temp2 = temp2->next;
//             curPos++;
//         }

//         return temp2;
// }


// Function to find the middle node of a linked list fast 
ListNode* middleNodeFast(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}



// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);


    // ListNode* middle = middleNode(head);

    cout << "Original List: ";
    printList(head);

    // cout << "Middle Node: " << middle->val << endl;
    // cout<<"From Middle Node: ";
    // printList(middle);

    ListNode* middleFast = middleNodeFast(head);
    cout << "Middle Node: " << middleFast->val << endl;
    printList(middleFast);
    

    return 0;
}