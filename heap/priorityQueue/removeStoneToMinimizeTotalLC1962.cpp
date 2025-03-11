#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Function to minimize the total number of stones after k operations
int minStoneSum(vector<int>& piles, int k) {
    // Max-heap to always get the largest pile
    priority_queue<int> pq;
    for (int i = 0; i < piles.size(); i++) {
        pq.push(piles[i]);
    }

    // Perform k operations
    while (k--) {
        int topElement = pq.top();
        pq.pop();
        topElement = topElement - floor(topElement / 2);  // Remove floor(top / 2) stones
        pq.push(topElement);
    }

    // Calculate the total sum of remaining stones
    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

// Main function to test the logic
int main() {
    vector<int> piles = {5, 4, 9};
    int k = 2;

    int result = minStoneSum(piles, k);
    cout << "Minimum Total Stones After " << k << " Operations: " << result << endl;

    return 0;
}

//time complexity: O(n+klogn)
//space complexity: O(n)