#include <iostream>
#include <vector>
using namespace std;

// Function to maintain max-heap property
void heapify(vector<int> &v, int i, int n) {
    while (true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < n && v[left] > v[largest]) {
            largest = left;
        }
        if (right < n && v[right] > v[largest]) {
            largest = right;
        }
        if (largest == i) {
            break;
        }
        swap(v[i], v[largest]);
        i = largest;
    }
}

// Function to merge two max heaps into one
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    for (int i = (c.size() / 2) - 1; i >= 0; i--) {
        heapify(c, i, c.size());
    }

    return c;
}

// Driver code
int main() {
    // Sample Input
    int n = 4, m = 3;
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    // Merging heaps
    vector<int> merged = mergeHeaps(a, b, n, m);

    // Output the result
    for (int val : merged) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
