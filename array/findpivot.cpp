#include<iostream>
using namespace std;
int findPivotIndex(int arr[], int n){
    int s=0,e=n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        if(mid+1<n && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(mid-1>=0 && arr[mid]<arr[mid-1]){
            return mid-1;
        }
        else if(arr[s]>arr[mid]){
            s = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
int main(){
    int arr[8] = {5,6,7,8,1,2,3,4};
    int ans = findPivotIndex(arr, 8);
    cout<<"Pivot index: "<<ans<<endl;
}