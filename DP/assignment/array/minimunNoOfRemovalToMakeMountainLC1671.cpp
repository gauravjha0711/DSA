#include<bits/stdc++.h>
using namespace std;
int solveLIS(vector<int>& arr, vector<int>& lis) {
    vector<int> ans;
    for (int i = 0; i < arr.size(); ++i) {
        if (ans.empty() || arr[i] > ans.back()) {
            ans.push_back(arr[i]);
            lis.push_back(ans.size());
        } else {
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
            lis.push_back(index + 1);
        }
    }
    return ans.size();
}

int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis, lds;

    solveLIS(nums, lis);

    vector<int> reversed(nums.rbegin(), nums.rend());
    solveLIS(reversed, lds);
    reverse(lds.begin(), lds.end());  // Align LDS to original positions

    int largestMountain = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (lis[i] > 1 && lds[i] > 1) {
            largestMountain = max(largestMountain, lis[i] + lds[i] - 1);
        }
    }

    return n - largestMountain;
}
int main(){
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout << minimumMountainRemovals(nums) << endl; // Output: 3
    return 0;
}