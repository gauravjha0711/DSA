#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void printarray(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool compare(int a, int b){
    return a<b;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array before sorting : ";
    printarray(arr);
    sort(arr.begin(), arr.end(), compare);
    cout<<"Array after sorting: ";
    printarray(arr);
}