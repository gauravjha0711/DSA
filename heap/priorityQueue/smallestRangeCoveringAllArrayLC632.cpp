#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Custom Node class to store value, row index, and column index
class Node {
public:
    int data;
    int row;
    int col;

    Node(int v, int r, int c) {
        data = v;
        row = r;
        col = c;
    }
};

// Comparator class for min-heap based on node data
class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

// Function to find the smallest range covering at least one element from each list
vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    int maxi = INT_MIN;
    int mini = INT_MAX;

    // Min-heap to track the current minimum elements across the lists
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Insert first element of each list into the heap
    for (int i = 0; i < k; i++) {
        int element = nums[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        pq.push(new Node(element, i, 0));
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();

        int topData = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;

        mini = topData;

        // Update the answer if the current range is smaller
        if (maxi - mini < ansEnd - ansStart) {
            ansStart = mini;
            ansEnd = maxi;
        }

        // If the list of current element has more elements, insert next one
        if (topCol + 1 < nums[topRow].size()) {
            int nextVal = nums[topRow][topCol + 1];
            maxi = max(maxi, nextVal);
            pq.push(new Node(nextVal, topRow, topCol + 1));
        } else {
            // If any list is exhausted, we can't include all lists in the range anymore
            break;
        }
    }

    return {ansStart, ansEnd};
}

// Main function to test the logic
int main() {
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> range = smallestRange(nums);

    cout << "Smallest Range: [" << range[0] << ", " << range[1] << "]" << endl;

    return 0;
}
// Time Complexity: O(N * log K)
// Space Complexity: O(K)