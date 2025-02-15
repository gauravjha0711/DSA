#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int newIndex = (i+k)%n;
        ans[newIndex] = nums[i];
    }
    nums=ans;
}
int main(){
    vector<int> v={1,2,3,4,5,6,7};
    int k=3;
    rotate(v, k);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}