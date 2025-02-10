#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void shiftNegativeNumberOneSide(int arr[], int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n] = {0};
    cout<<"Enter the value: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shiftNegativeNumberOneSide(arr, n);
    printArray(arr, n);
}