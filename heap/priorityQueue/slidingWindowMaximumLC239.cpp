#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    vector<int> ans;

    // Initial window
    for (int i = 0; i < k; i++) {
        pq.push({nums[i], i});
    }
    ans.push_back(pq.top().first);

    // Sliding the window
    for (int i = k; i < nums.size(); i++) {
        pq.push({nums[i], i});
        
        // Remove elements outside the window
        while (pq.top().second <= i - k) {
            pq.pop();
        }

        ans.push_back(pq.top().first);
    }

    return ans;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
