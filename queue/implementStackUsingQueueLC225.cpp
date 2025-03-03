#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++) {
        int front = q.front();
        q.pop();
        q.push(front);
    }
}

int pop() {
    if (q.empty()) {
        cout << "Stack is empty!" << endl;
        return -1; // Indicating error
    }
    int front = q.front(); // Store the front element before popping
    q.pop();
    return front; // Return the original front
}

int top() {
    if (q.empty()) {
        cout << "Stack is empty!" << endl;
        return -1; // Indicating error
    }
    return q.front();
}

bool empty() {
    return q.empty();
}

int main() {
    push(10);
    push(20);
    push(30);
    
    cout << "Top element: " << top() << endl; // Should print 30
    cout << "Popped element: " << pop() << endl; // Should print 30
    cout << "Is stack empty? " << (empty() ? "Yes" : "No") << endl;

    return 0;
}
