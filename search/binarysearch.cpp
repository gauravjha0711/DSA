#include<iostream>
using namespace std;
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int arr[], int n){
    int t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}
int binarysearch(int arr[],int n,int key){
    int s=0,l=n,m;
    while(s<=l){
        m=s+(l-s)/2;
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]<key){
            s=m+1;
        }
        else{
            l=m-1;
        }
    }
    return -1;
}
int main(){
    cout<<"Enter size of array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter value of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    cout<<"Array after sort: ";
    printarray(arr, n);
    int key;
    cout<<"Enter key for search: ";
    cin>>key;
    int pos = binarysearch(arr, n , key);
    if(pos==-1){
        cout<<"Key not found";
    }
    else{
        cout<<"Keys found at "<<pos+1;
    }
}




