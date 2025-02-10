#include<iostream>
using namespace std;
void insertionsort(int arr[], int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
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
    insertionsort(arr, n);
    cout<<"Array after sorting: ";
    printarray(arr, n);
}