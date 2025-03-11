#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i){
    int index=i;
    int left = 2*i;
    int right = 2*i+1;
    int largest = index;
    if(left<=n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest = right;
    }
    if(index!=largest){
        swap(arr[index],arr[largest]);
        index = largest;
        heapify(arr,n,index);
    }
}
void buildHeap(int arr[], int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}
void printHeap(int arr[], int n){
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapSort(int arr[], int n){
    while(n!=1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}
int main(){
    int arr[] = { -1,12,15,13,11,14};
    int n=5;
    buildHeap(arr,n);
    printHeap(arr,n);
    heapSort(arr,n);
    cout<<"After sorting"<<endl;
    printHeap(arr,n);
}