#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Comparator class for priority queue (min-heap)
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min-heap: smallest value has highest priority
    }
};

// Standalone function to merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    int k = lists.size();
    if (k == 0) return NULL;

    // Push the head of each non-null list into the priority queue
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) {
            pq.push(lists[i]);
        }
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    while (!pq.empty()) {
        ListNode* temp = pq.top();
        pq.pop();

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }

        if (temp->next != NULL) {
            pq.push(temp->next);
        }
    }

    return head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int val : vals) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Main function to test mergeKLists
int main() {
    vector<ListNode*> lists;

    // Create sample linked lists
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    ListNode* merged = mergeKLists(lists);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
