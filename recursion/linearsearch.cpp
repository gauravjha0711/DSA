#include<iostream>
using namespace std;
bool linearSearch(int arr[], int n, int k){
    if(n==0){
        return false;
    }
    if(k==arr[0]){
        return true;
    }
    return linearSearch(arr+1,n-1,k);
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
    bool ans = linearSearch(arr,n,k);
    if(ans){
        cout<<"Element is found\n";
    }
    else{
        cout<<"Element is not found\n";
    }
}