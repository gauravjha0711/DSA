#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int main = s;
    for(int i=0;i<len1;i++){
        first[i] = arr[main++];
    }
    main = mid+1;
    for(int i=0;i<len2;i++){
        second[i] = arr[main++];
    }
    int index1=0;
    int index2=0;
    main = s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[main++] = first[index1++];
        }
        else{
            arr[main++] = second[index2++];
        }
    }
    while(index1<len1){
        arr[main++]=first[index1++];
    }
    while(index2<len2){
        arr[main++]=second[index2++];
    }
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return ;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1,e);
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