#include<iostream>
using namespace std;
int searchNearlySorted(int arr[], int n, int target){
    int s=0, e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if((mid-1)>0 && arr[mid-1]==target){
            return mid-1;
        }
        if(arr[mid]==target){
            return mid;
        }
        if((mid+1)<n && arr[mid+1]==target){
            return mid+1;
        }
        if(arr[mid]<target){
            s=mid+2;
        }
        else{
            e=mid-2;
        }
    }
    return -1;
}
int main(){
    int arr[]={5,10,30,20,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=20;
    cout<<"Index: "<<searchNearlySorted(arr,n,target);
    return 0;
}