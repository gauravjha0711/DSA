#include<iostream>
#include<vector>
using namespace std;
int houseRobbing(vector<int> &arr, int s, int e){
    if(s>e){
        return 0;
    }
    int include = arr[s]+houseRobbing(arr, s+2, e);
    int exclude = 0 + houseRobbing(arr, s+1, e);
    return max(include, exclude);
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum = houseRobbing(arr, 0, n-1);
    cout<<"Maximum amount: "<<sum<<endl;
    return 0;
}