#include<iostream>
#include<vector>
using namespace std;
void evenNumber(int arr[], int n, int index, vector<int> &even){
    if(index>=n){
        return;
    }
    if(arr[index]%2==0){
        even.push_back(arr[index]);
    }
    evenNumber(arr, n, index+1, even);
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[n] = {0};
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> even;
    evenNumber(arr, n, 0, even);
    cout<<"Even numbers are: ";
    for(int i=0;i<even.size();i++){
        cout<<even[i]<<" ";
    }
    cout<<endl;
    return 0;
}