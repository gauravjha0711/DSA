#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;

    // Custom comparator for min-heap based on distance (distance = x^2 + y^2)
    auto compare = [](pair<int, int>& a, pair<int, int>& b) {
        int disA = a.first * a.first + a.second * a.second;
        int disB = b.first * b.first + b.second * b.second;
        return disA > disB;  // Min-heap
    };

    // Priority queue to store points along with their squared distance from the origin
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    // Push all points into the priority queue
    for (auto& point : points) {
        pq.push({point[0], point[1]});
    }

    // Extract the closest k points
    while (k-- && !pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ans.push_back({top.first, top.second});
    }

    return ans;
}

// Driver code to test the function
int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> result = kClosest(points, k);

    // Print the k closest points
    for (auto& p : result) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;

    return 0;
}
