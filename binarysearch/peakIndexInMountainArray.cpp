#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int s=0;
    int e=n-1, mid;
    while(s<e){
        mid=s+(e-s)/2;
        if(arr[mid]>arr[mid+1]){
            e=mid;
        }
        else{
            s=mid+1;
        }
    }
    return s;
}
int main(){
    vector<int> v={0,2,1,0};
    cout<<peakIndexInMountainArray(v);
    return 0;
}