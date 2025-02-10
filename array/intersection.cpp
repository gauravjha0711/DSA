//find same element in another array
#include<iostream>
using namespace std;
int main(){
    // int arr1[8] = {1,2,3,4,5,3,5,2};
    // int arr2[8] = {8,9,6,3,5,2,9,2};
    // for(int i=0;i<8;i++){
    //     int ele = arr1[i];
    //     for(int j=0;j<8;j++){
    //         if(ele==arr2[j]){
    //             cout<<ele<<" ";
    //             arr2[j] = -257;
    //             ele = -259;
    //         }
    //     }
    // }

    int arr1[6] = {1,2,2,2,3,4};
    int arr2[6] = {2,2,3,3,8,9};
    int i=0,j=0;
    cout<<"Intersection is: ";
    while(i<6 && j<6){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}