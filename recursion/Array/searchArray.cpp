#include<iostream>
using namespace std;
int searchArray(int arr[], int n, int index, int target){
    if(index>=n){
        return -1;
    }
    if(arr[index]==target){
        return index;
    }
    else{
        return searchArray(arr,n,index+1,target);
    }
}
int main(){
    int n,target;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[n] = {0};
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter target: ";
    cin>>target;
    cout<<searchArray(arr,n,0,target);
}