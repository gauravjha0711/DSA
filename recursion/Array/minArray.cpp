#include<iostream>
using namespace std;
int minArray(int arr[], int n,int index, int mini){
    if(index>=n){
        return mini;
    }
    mini = min(mini, arr[index]);
    return minArray(arr, n, index+1, mini);
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
    int mini = minArray(arr, n, 0, arr[0]);
    cout<<"Minimum element is: "<<mini<<endl;
    return 0;
}