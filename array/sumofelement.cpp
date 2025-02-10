//sum of two element is equal to fixed number
#include<iostream>
using namespace std;
int main(){
    int arr[8] = {0,1,2,3,4,5,7,8};
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            if(arr[i]+arr[j]==5){
                cout<<arr[i]<<" "<<arr[j];
                cout<<endl;
            }
        }
    }
}