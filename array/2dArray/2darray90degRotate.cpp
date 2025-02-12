#include<iostream>
using namespace std;
void printArray(int arr[][3], int r, int c){
    for (int i = 0; i < r; i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void rotate(int arr[][3], int r, int c){
    for(int i=0;i<r;i++){
        for(int j=i;j<c;j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int i=0;i<r;i++){
        int s=0,l=c-1;
        while(s<=l){
            swap(arr[i][s++],arr[i][l--]);
        }
    }
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Matrix before: \n";
    printArray(arr,3,3);
    rotate(arr,3,3);
    cout<<"Matrix after rotate: \n";
    printArray(arr,3,3);
}