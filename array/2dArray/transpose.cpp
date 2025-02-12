#include<iostream>
using namespace std;
void printMatrix(int arr[][4], int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void transpose(int arr[][4], int r, int c){
    for(int i=0;i<r;i++){
        for(int j=i;j<c;j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}
int main(){
    int r=4,c=4;
    int arr[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    cout<<"Matrix before transpose: \n";
    printMatrix(arr,r,c);
    transpose(arr,r,c);
    cout<<"Matrix after transpose: \n";
    printMatrix(arr,r,c);
}