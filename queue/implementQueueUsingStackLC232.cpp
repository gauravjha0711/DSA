#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> s1;
stack<int> s2;

void push(int x) {
    s1.push(x);
}

int pop() {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if (!s2.empty()) {
        int popVal = s2.top();
        s2.pop();
        return popVal;
    }
    return -1;
}

int peek() {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.empty() ? -1 : s2.top();
}

bool empty() {
    return s1.empty() && s2.empty();
}

int main() {
    push(1);
    push(2);
    cout << "Peek: " << peek() << endl; // Should print 1
    cout << "Pop: " << pop() << endl;   // Should print 1
    cout << "Empty: " << empty() << endl; // Should print false
    cout << "Pop: " << pop() << endl;   // Should print 2
    cout << "Empty: " << empty() << endl; // Should print true
    return 0;
}
// Time Complexity: O(1) for push, O(n) for pop and peek
// Space Complexity: O(n) for n elements in the queue