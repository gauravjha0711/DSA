#include<iostream>
using namespace std;
int main(){
    int i=0;
    int arr[6] = {1,0,5,4,0,9};
    for(int j=0;j<6;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}