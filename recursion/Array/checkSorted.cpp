#include<iostream>
using namespace std;
bool checkSorted(int arr[], int n, int index){
    if(index>=n){
        return true;
    }
    if(arr[index]>arr[index-1]){
        return checkSorted(arr, n, index+1);
    }
    else{
        return false;
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
    bool ans = checkSorted(arr,n,1);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}