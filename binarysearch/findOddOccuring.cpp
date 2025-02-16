#include<iostream>
using namespace std;
int findOddOccuring(int arr[], int n){
    int s=0, e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(s==e){
            return s;
        }
        if(mid%2==0){
            if(mid+1<n && arr[mid]==arr[mid+1]){
                s=mid+2;
            }
            else{
                e=mid;
            }
        }
        else{
            if(mid-1>=0 && arr[mid]==arr[mid-1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int arr[]={1,1,2,2,3,3,4,4,8,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Element: "<<arr[findOddOccuring(arr,n)]<<endl;
    return 0;
}