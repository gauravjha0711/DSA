#include<iostream>
#include<array>
using namespace std;
int main(){
    array<int, 5> arr = {0,1,2,3,4};
    cout<<"Size of array: "<<arr.size()<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}