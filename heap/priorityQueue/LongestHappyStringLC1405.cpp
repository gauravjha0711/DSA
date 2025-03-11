#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class node {
public:
    char data;
    int count;
    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
public:
    bool operator()(node a, node b) {
        return a.count < b.count; // Max-heap based on count
    }
};

// Function without class
string longestDiverseString(int a, int b, int c) {
    priority_queue<node, vector<node>, compare> maxHeap;
    if (a > 0) maxHeap.push(node('a', a));
    if (b > 0) maxHeap.push(node('b', b));
    if (c > 0) maxHeap.push(node('c', c));

    string ans = "";
    while (maxHeap.size() > 1) {
        node first = maxHeap.top(); maxHeap.pop();
        node second = maxHeap.top(); maxHeap.pop();

        // Append first character
        if (first.count >= 2) {
            ans += first.data;
            ans += first.data;
            first.count -= 2;
        } else {
            ans += first.data;
            first.count--;
        }

        // Append second character
        if (second.count >= 2 && second.count >= first.count) {
            ans += second.data;
            ans += second.data;
            second.count -= 2;
        } else {
            ans += second.data;
            second.count--;
        }

        // Push back if counts remain
        if (first.count > 0) maxHeap.push(first);
        if (second.count > 0) maxHeap.push(second);
    }

    // Handle last character if one remains
    if (!maxHeap.empty()) {
        node temp = maxHeap.top(); maxHeap.pop();
        if (temp.count >= 2) {
            ans += temp.data;
            ans += temp.data;
        } else {
            ans += temp.data;
        }
    }

    return ans;
}

int main() {
    // Test cases
    cout << longestDiverseString(1, 1, 7) << endl; // Example: "ccaccbcc"
    cout << longestDiverseString(2, 2, 1) << endl; // Example: "aabbc"
    cout << longestDiverseString(7, 1, 0) << endl; // Example: "aabaa"
    cout << longestDiverseString(0, 0, 0) << endl; // Example: ""
    cout << longestDiverseString(1, 0, 3) << endl; // Example: "ccac"

    return 0;
}




//time O(nlog3)
//space O(3)