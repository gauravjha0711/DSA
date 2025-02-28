#include <iostream>
using namespace std;

class queue {
public:
    int* arr;
    int front;
    int rear;
    int capacity;  // Renamed from `size`

    queue(int n) {
        this->arr = new int[n];
        this->front = -1;
        this->rear = -1;
        this->capacity = n;
    }

    void push(int data) {
        if (rear == capacity - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {  // Fix condition
            front++;
        }
        rear++;
        arr[rear] = data;
    }

    void pop() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {  // Reset queue when last element is removed
            front = rear = -1;
        } else {
            front++;
        }
    }

    int Front() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getSize() {  // Renamed from `size()`
        if (front == -1) {
            return 0;
        }
        return rear - front + 1;
    }

    bool empty() {
        return (front == -1);
    }
};

int main() {
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front: " << q.Front() << endl;
    q.pop();
    cout << "Front: " << q.Front() << endl;
    cout << "Size: " << q.getSize() << endl;  // Updated method call
    cout << "Empty: " << q.empty() << endl;
    return 0;
}
