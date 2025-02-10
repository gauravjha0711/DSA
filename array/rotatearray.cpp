#include<iostream>
using namespace std;
int main(){
    int arr[6] = {1,2,3,4,5,6};
    int n = 6;
    int k = 3;
    int temp[6] = {0};
    for(int i=0;i<n;i++){
        temp[(i+k)%n] = arr[i];
    }
    cout<<"Array after rotate: ";
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }cout<<endl;
}