#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    // Process first k elements
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    // Add the max of first window
    ans.push_back(nums[dq.front()]);

    // Process the rest of the elements
    for (int i = k; i < nums.size(); i++) {
        // Remove elements that are out of the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Maintain decreasing order in deque
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        // Add current element index
        dq.push_back(i);

        // Push the maximum for the current window
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

// Test the function
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}