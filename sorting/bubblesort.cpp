#include<iostream>
using namespace std;
void bubblesort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array before sorting : ";
    printarray(arr, n);
    bubblesort(arr, n);
    cout<<"Array after sorting: ";
    printarray(arr, n);
}