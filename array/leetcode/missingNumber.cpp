#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int sum=0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    int totalSum = ((n)*(n+1))/2;
    return totalSum-sum;
}
int main(){
    vector<int> v={3,0,1};
    cout<<missingNumber(v)<<endl;
    return 0;
}