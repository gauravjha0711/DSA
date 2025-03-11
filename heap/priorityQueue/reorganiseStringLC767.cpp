#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// Custom node class to store character and its frequency
class node {
public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

// Custom comparator for max-heap (higher count gets higher priority)
class compare {
public:
    bool operator()(node a, node b) {
        return a.count < b.count;
    }
};

// Function to reorganize the string so that no same adjacent characters exist
string reorganizeString(string s) {
    int freq[26] = {0};

    // Count frequency of each character
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    // Max-heap to store characters based on their frequency
    priority_queue<node, vector<node>, compare> maxHeap;

    // Push characters with non-zero frequency into the heap
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            maxHeap.push(node(i + 'a', freq[i]));
        }
    }

    string ans = "";

    // Greedily pick top two most frequent characters
    while (maxHeap.size() > 1) {
        node first = maxHeap.top();
        maxHeap.pop();
        node second = maxHeap.top();
        maxHeap.pop();

        ans += first.data;
        ans += second.data;

        first.count--;
        second.count--;

        if (first.count > 0) {
            maxHeap.push(first);
        }
        if (second.count > 0) {
            maxHeap.push(second);
        }
    }

    // If one character is left
    if (maxHeap.size() == 1) {
        node temp = maxHeap.top();
        maxHeap.pop();

        if (temp.count == 1) {
            ans += temp.data;
        } else {
            // Not possible to rearrange without adjacent duplicates
            return "";
        }
    }

    return ans;
}

// Main function to test the logic
int main() {
    string input = "aaabbc";
    string result = reorganizeString(input);

    if (result == "") {
        cout << "Reorganization not possible." << endl;
    } else {
        cout << "Reorganized String: " << result << endl;
    }

    return 0;
}
