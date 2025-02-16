#include<iostream>
using namespace std;
void selectionsort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minn = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minn]){
                minn=j;
            }
        }
        swap(arr[minn], arr[i]);
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
    selectionsort(arr, n);
    cout<<"Array after sorting: ";
    printarray(arr, n);
}