#include<iostream>
using namespace std;
void print(int arr[], int n, int index){
    if(index>=n){
        return ;
    }
    else{
        cout<<arr[index]<<" ";
        print(arr,n,index+1);
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
    print(arr, n, 0);
    return 0;
}