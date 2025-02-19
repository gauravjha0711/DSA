#include<iostream>
using namespace std;
int binarySearch(int arr[], int s, int e, int target){
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[mid]<target){
        binarySearch(arr, mid+1, e, target);
    }
    else{
        binarySearch(arr, s, mid, target);
    }
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[n] = {0};
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    int ans = binarySearch(arr,0,n-1,target);
    if(ans==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index: "<<ans<<endl;
    }
    return 0;
}