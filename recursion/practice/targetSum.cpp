#include<iostream>
#include<vector>
using namespace std;
void targetSum(int index,int& target,vector<int>& ans,vector<int>& arr,int sum){
    if(index == arr.size()){
        if(target == sum){
            for(int i : ans){
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    // Include the current element
    ans.push_back(arr[index]);
    sum += arr[index];
    targetSum(index + 1, target, ans, arr, sum);
    // Exclude the current element
    ans.pop_back();
    sum -= arr[index];
    targetSum(index + 1, target, ans, arr, sum);
}
int main(){
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter target sum: ";
    cin >> target;
    
    vector<int> ans;
    targetSum(0, target, ans, arr, 0);
    
    return 0;
}