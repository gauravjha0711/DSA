#include<iostream>
using namespace std;
int getSum(int arr[], int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    else{
        return arr[0]+getSum(arr+1,n-1);
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
    int sum = getSum(arr, n);
    cout<<"sum is: "<<sum<<endl;
}