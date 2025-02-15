#include<iostream>
using namespace std;
int firstocc(int arr[],int n, int k){
    int s=0,e=n-1,mid;
    int ans=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<k){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int lastocc(int arr[],int n, int k){
    int s=0,e=n-1,mid;
    int ans=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==k){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<k){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[8] = {0,1,2,2,2,5,7,8};
    int first = firstocc(arr, 8, 2);
    int last = lastocc(arr, 8, 2);
    cout<<first+1<<" "<<last+1;
}