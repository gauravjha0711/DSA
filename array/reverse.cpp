#include<iostream>
using namespace std;
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverse(int arr[], int n){
    int start=0, end=n-1;
    while(start<end){
        swap(arr[start++], arr[end--]);
    }
}
void putZeroOne(int arr[], int n){
    int zeroCount=0, oneCount=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        else if(arr[i]==1){
            oneCount++;
        }
    }
    int index=0;
    while(zeroCount--){
        arr[index++]=0;
    }
    while(oneCount--){
        arr[index++]=1;
    }
}
void rightShift(int arr[], int n){
    int temp=arr[n-1];
    for(int i=n-1;i>=1;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}
int main(){
//     int arr[8] = {8,1,3,4,7,9,5,6};
//     cout<<"Array before swap: ";
//     printarray(arr,8);
//     reverse(arr,8);
//     cout<<"Array after swap: ";
//     printarray(arr,8);


    //put all zero at start and one at the end
    // int arr[8] = {0,1,0,1,1,1,0,0,};
    // putZeroOne(arr,8);
    // printarray(arr,8);



    //move array element to right by one position
    int arr[8] = {1,2,3,4,5,6,7,8};
    rightShift(arr,8);
    printarray(arr,8);
}