#include<bits/stdc++.h>
using namespace std;
int maxLen(vector<int>& arr) {
    // code here
    int csum=0;
    int ans=0;
    unordered_map<int, int> map;
    for(int i=0;i<arr.size();i++){
        csum += arr[i];
        if(csum==0){
            ans = max(ans, i+1);
        }
        else if(map.find(csum)==map.end()){
            map[csum]=i;
        }
        else{
            ans = max(ans, i-map[csum]);
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<maxLen(arr)<<endl;
    return 0;
}
// Time Complexity: O(N)