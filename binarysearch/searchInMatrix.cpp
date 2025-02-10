#include<iostream>
using namespace std;
bool search(int arr[][3], int r, int c, int target){
    int s=0;
    int e = (r*c)-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        int rowIndex = mid/c;
        int colIndex = mid%c;
        int curNumber = arr[rowIndex][colIndex];
        if(curNumber==target){
            return true;
        }
        else if(curNumber<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return false;
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    bool find = search(arr,3,3,11);
    if(find){
        cout<<"Number found"<<endl;
    }
    else{
        cout<<"number not found"<<endl;
    }
}