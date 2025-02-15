#include<iostream>
using namespace std;
int findFirstOccurence(int* arr, int n, int target){
    int s=0, e=n-1;
    int ans = -1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            ans=mid;;
            e = mid-1;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int findLastOccurence(int* arr, int n, int target){
    int s=0, e=n-1;
    int ans = -1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            ans=mid;;
            s= mid+1;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {1,2,5,5,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 5;
    int first = findFirstOccurence(arr, n, target);
    int last = findLastOccurence(arr, n, target);
    int ans = last-first+1;
    if(ans==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at "<<ans;
    }
    return 0;
}