#include<iostream>
#include<vector>
using namespace std;
int houseRobber(vector<int> &nums, int index){
    if(index>=nums.size()){
        return 0;
    }
    int include = nums[index] + houseRobber(nums, index+2);
    int exclude = houseRobber(nums, index+1);
    return max(include, exclude);
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = houseRobber(nums, 0);
    cout<<"Maximum amount that can be robbed: "<<ans<<endl;
    return 0;
}