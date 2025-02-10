#include<iostream>
using namespace std;
int main(){
    int arr[4]={10,20,30,40};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<"{"<<arr[i]<<","<<arr[j]<<"}"<<endl;
        }
    }
}
