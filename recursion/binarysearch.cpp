#include<iostream>
using namespace std;
bool binarySearch(int arr[], int s, int e, int k){
    if(s>e){
        return false;
    }
    int mid = s+(e-s)/2;
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){
        return binarySearch(arr,mid+1,e,k);
    }
    else{
        return binarySearch(arr,s,mid-1,k);
    }
}
int main(){
    int n,k;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[n] = {0};
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter key: ";
    cin>>k;
    bool ans = binarySearch(arr,0,n,k);
    if(ans){
        cout<<"Element is found\n";
    }
    else{
        cout<<"Element is not found\n";
    }
}