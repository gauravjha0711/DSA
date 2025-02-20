#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int lenLeft = mid-s+1;
    int lenRight = e-mid;
    int *left = new int[lenLeft];
    int *right = new int[lenRight];
    int main = s;
    for(int i=0;i<lenLeft;i++){
        left[i]=arr[main++];
    }
    for(int i=0;i<lenRight;i++){
        right[i]=arr[main++];
    }
    int leftIndex=0;
    int rightIndex=0;
    main = s;
    while(leftIndex<lenLeft && rightIndex<lenRight){
        if(left[leftIndex]<right[rightIndex]){
            arr[main++]=left[leftIndex++];
        }
        else{
            arr[main++]=right[rightIndex++];
        }
    }
    while(leftIndex<lenLeft){
        arr[main++]=left[leftIndex++];
    }
    while(rightIndex<lenRight){
        arr[main++]=right[rightIndex++];
    }
    delete[] left;
    delete[] right;
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr,s,e);
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array before sorting: ";
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    cout<<"Array after sorting: "<<endl;
    printArray(arr,n);
}